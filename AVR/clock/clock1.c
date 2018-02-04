#include <avr/io.h>
#include <avr/interrupt.h>

#define sbi(REGISTER,BIT) REGISTER |= (1 << BIT);    /* sets BIT in REGISTER */
#define cbi(REGISTER,BIT) REGISTER &= ~(1 << BIT);   /* clears BIT in REGISTER */

static volatile short digits[4];

void delay_short( unsigned short count )
{
    while( count-- > 0 );
}

/*
  Photoresistor to sense ambient light, so that the clock display can
  be dimmed in the dark:

                       /   /
                     |/_ |/_
pin 15 PB1: -o------/\/\/\------|
             |
             ---------||--------|

*/

/*
 Segment layout:
 PORTD:

 G - PD0 (0x01)
 H - PD1 (0x02)
 E - PD2 (0x04)
 C - PD3 (0x08)
 D - PD4 (0x10)
 B - PD5 (0x20)
 A - PD6 (0x40)
 F - PD7 (0x80)

 Dot layout:

 Upper dot: PD5
 Lower dot: PD1

*/

#define SEG_A 0x40
#define SEG_B 0x20
#define SEG_C 0x08
#define SEG_D 0x10
#define SEG_E 0x04
#define SEG_F 0x80
#define SEG_G 0x01
#define SEG_H 0x02

static short digit7seg[] = {
    /* 0 */ 0xFF & (~ (SEG_G | SEG_H )),
    /* 1 */ SEG_B + SEG_C,
    /* 2 */ SEG_A + SEG_B + SEG_G + SEG_E + SEG_D,
    /* 3 */ SEG_A + SEG_B + SEG_G + SEG_C + SEG_D,
    /* 4 */ SEG_F + SEG_G + SEG_B + SEG_C,
    /* 5 */ SEG_A + SEG_F + SEG_G + SEG_C + SEG_D,
    /* 6 */ 0xFF & (~ (SEG_B | SEG_H)),
    /* 7 */ SEG_A + SEG_B + SEG_C,
    /* 8 */ 0xFF & (~SEG_H),
    /* 6 */ 0xFF & (~ (SEG_E | SEG_H)),
    /* A */ 0xFF & (~ (SEG_D | SEG_H)),
    /* B */ SEG_F + SEG_G + SEG_E + SEG_C + SEG_D,
    /* C */ SEG_A + SEG_F + SEG_E + SEG_D,
    /* D */ SEG_B + SEG_G + SEG_E + SEG_C + SEG_D,
    /* E */ SEG_A + SEG_F + SEG_G + SEG_E + SEG_D,
    /* F */ SEG_A + SEG_F + SEG_G + SEG_E,
};

/*
 Button layout:
 PORTC:

 indicator 0 (leftmost)  : PC0
 indicator 1             : PC1
 indicator 2             : PC2
 indicator 3 (rightmost) : PC3

 middle dots             : PC4

 common - PD0

 PORTB:

 button1 - PD6
 button2 - PD7
 button3 - PD4
 button4 - PD5
 
*/

short read( unsigned short cycles )
{
    unsigned short i;
    short val = 0xFF;

    /* disable all 7-seg indicators; set pins low: */
    PORTC = 0x00;
    /* Clearing old values from PORTD: */
    PORTD = 0xFF;
    /* Configure PORTD for input, except for pin PD0: */
    DDRD = 0x01;
    /* Set low level on PD0: */
    PORTD = 0xFE;

    /* read the values, do debouncing: */
    for( i = 0; i < cycles; i++ ) {
	val &= PIND;
    }

    /* clean up the ports: */
    /* disable PORTD pull-up resistors: */
    PORTD = 0x00;
    /* program PORTD for output: */
    DDRD  = 0xFF;

    return val;
}

#define SECONDS_PER_24H 86400

static volatile long half_seconds;
static volatile long seconds;

ISR( TIMER1_COMPA_vect )
{
    half_seconds ++;
    if( !(half_seconds & 0x01) ) {
	seconds ++;
    }

    if( seconds >= SECONDS_PER_24H ) {
	seconds = 0;
    }

    int whole_minutes = seconds / 60;
    int minutes = whole_minutes % 60;
    int hours = whole_minutes / 60;

    digits[3] = digit7seg[ minutes % 10 ];
    digits[2] = digit7seg[ minutes / 10 ];

    digits[1] = digit7seg[ hours % 10 ];
    digits[0] = digit7seg[ hours / 10 ];
}

/* Ambiaent light measurement: */

#define MAX_CAPACITOR_CHARGE_COUNT    10
#define MAX_CAPACITOR_DISCHARGE_COUNT 200

#define CAPACITOR_STATE_CHARGE 0x01
#define LED_STATE_ON           0x02

unsigned short state;

unsigned short ambient_light( void )
{
    static unsigned short capacitor_discharge_count = 0;
    static unsigned short prev_capacitor_discharge_count = 0;
    static unsigned short capacitor_charge_count = 0;

    if( state & CAPACITOR_STATE_CHARGE ) {
        capacitor_charge_count ++;
        if( capacitor_charge_count >= MAX_CAPACITOR_CHARGE_COUNT ) {
            state &= ~CAPACITOR_STATE_CHARGE;
            cbi(DDRB,PB1); // pin is input
            capacitor_discharge_count = 0;
        }
    } else {
        unsigned short led = PINB;
        if( led & 0x02 ) {
            // Not yet discharged:
            capacitor_discharge_count ++;
        }
        if( !(led & 0x02) ||
            capacitor_discharge_count > MAX_CAPACITOR_DISCHARGE_COUNT ) {
            // Discharged, or reached maximum count:
            state |= CAPACITOR_STATE_CHARGE;
            sbi(DDRB,PB1); // pin is output
            sbi(PORTB,PB1);
            capacitor_charge_count = 0;
            prev_capacitor_discharge_count = capacitor_discharge_count;
        }
    }
    return prev_capacitor_discharge_count;
}


void display_digits(unsigned short cycles)
{
    PORTC = 0x01;
    PORTD = digits[0];
    delay_short( cycles );
    PORTD = 0;

    PORTC = 0x02;
    PORTD = digits[1];
    delay_short( cycles );
    PORTD = 0;

    PORTC = 0x04;
    PORTD = digits[2];
    delay_short( cycles );
    PORTD = 0;

    PORTC = 0x08;
    PORTD = digits[3];
    delay_short( cycles );
    PORTD = 0;

    /* Display dots: */
    PORTC = 0x10;
    if( half_seconds & 0x01 ) {
    	PORTD = 0x22;
    } else {
    	PORTD = 0x00;
    }
    delay_short( cycles / 6 );
    PORTD = 0;

    PORTC = 0;
}

static short old_buttons;
static short bnumbers[4]; /* Button position numbers */

#define MIN_DISPLAY_CYCLES 10
#define MAX_DISPLAY_CYCLES 200

void read_buttons( unsigned short read_cycles )
{
    short buttons = read( read_cycles ) >> 4;;
    if( buttons != old_buttons ) {
	short i;
	for( i = 0; i < 4; i++ ) {
	    short j = bnumbers[i];
	    short mask = (0x01 << i);
	    if( (buttons & mask) < (old_buttons & mask) ) {
		switch( j ) {
		case 0: seconds += 3600; break;
		case 1:
		    seconds -= 3600;
		    if( seconds < 0 ) {
			seconds = SECONDS_PER_24H - 3600;
		    }
		    break;
		case 2: seconds += 60; break;
		case 3:
		    seconds -= 60;
		    if( seconds < 0 ) {
			seconds = SECONDS_PER_24H - 60;
		    }
		    break;
		}
	    }
	    if( seconds >= SECONDS_PER_24H ) {
		seconds = 0;
	    }
	    seconds = (seconds / 60) * 60;
	}
	old_buttons = buttons;
    }
}

void read_and_display( unsigned short display_cycles,
		       unsigned short read_cycles )
{
    display_digits( display_cycles );
    read_buttons( read_cycles );
}

int main(void)
{
    DDRC |= 0x1F;
    DDRD |= 0xFF;
    PORTD = 0x00;

    digits[0] = digit7seg[0];
    digits[1] = digit7seg[1];
    digits[2] = digit7seg[2];
    digits[3] = digit7seg[3];

    bnumbers[2] = 0; /* button 1 */
    bnumbers[3] = 1; /* button 2 */
    bnumbers[0] = 2; /* button 3 */
    bnumbers[1] = 3; /* button 4 */

    /* Set up Timer1 for 0.5s at 6.400 MHz crystal: */
    /* Number of timer pre-scaled pulses to count: */
    OCR1A = 25000 / 2; /* Half-second intervals. */
    /* Mode 4, CTC on OCR1A: */
    TCCR1B |= (1 << WGM12);
    /* Set interrupt on compare match: */
    TIMSK |= (1 << OCIE1A);
    /* set prescaler to 128 and start the timer: */
    TCCR1B |= (1 << CS12);

    /* Enable interrupts: */
    sei();

    while (1) {
        unsigned short display_cycles;
        unsigned short ambient_counts = ambient_light();
        if( ambient_counts < MAX_DISPLAY_CYCLES - MIN_DISPLAY_CYCLES ) {
            display_cycles = MAX_DISPLAY_CYCLES - ambient_counts;
        } else {
            display_cycles = MIN_DISPLAY_CYCLES;
        }
        digits[3] = digit7seg[ display_cycles % 10 ];
        digits[2] = digit7seg[ (display_cycles/10) % 10 ];
        digits[1] = digit7seg[ (display_cycles/100) % 10 ];
        digits[0] = digit7seg[ (display_cycles/1000) % 10 ];
	read_and_display( /* display_cycles = */ display_cycles,
			  /* read_cycles = */ 127 );
    }
}
