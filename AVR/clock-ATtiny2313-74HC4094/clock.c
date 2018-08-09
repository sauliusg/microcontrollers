#include <avr/io.h>
#include <avr/interrupt.h>
 #include <avr/sleep.h>

#define sbi(REGISTER,BIT) REGISTER |= _BV(BIT);    /* sets BIT in REGISTER */
#define cbi(REGISTER,BIT) REGISTER &= ~(_BV(BIT));   /* clears BIT in REGISTER */

static volatile unsigned short digits[4];

/* Pins PD6 (pin 11) and PB0 (pin 12) are free so far. */

/*
 Segment layout -- segments are assigned to the 74HC4094 shifter
 parallel output pins:
*/

#define SEG_A 0x80
#define SEG_B 0x40
#define SEG_C 0x20
#define SEG_D 0x10
#define SEG_E 0x08
#define SEG_F 0x04
#define SEG_G 0x02
#define SEG_H 0x01

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

/* Hour dot leds:

   Upper dot: PD4 
   Lower dot: PD5
*/

void display_dots( long half_seconds )
{
    if( half_seconds & 0x01 ) {
    	cbi( PORTD, PD4 );
    	cbi( PORTD, PD5 );
    } else {
    	sbi( PORTD, PD4 );
    	sbi( PORTD, PD5 );
    }
}

/* Button pins:

  short buttons = ~PINB & 0x1E;

  Button 1: PB1
  Button 2: PB2
  Button 3: PB3
  Button 4: PB4
*/

// 74HC4094 shift register pin number assignments:
int D   = PD0; // Serial data in
int CP  = PD1; // Serial data clock
int STR = PD2; // Strobe: latch shifted values into a parallel output
int OE  = PD3; // Output Enable

/* Initialise microcontroller: */
void init(void)
{
    /* Enable selected pins as inputs: */
    cbi(DDRB,PB1);
    cbi(DDRB,PB2);
    cbi(DDRB,PB3);
    cbi(DDRB,PB4);

    /* Enable selected pins as an output: */
    sbi(DDRD,PD0);
    sbi(DDRD,PD1);
    sbi(DDRD,PD2);
    sbi(DDRD,PD3);

    sbi(DDRD,PD5);
    sbi(DDRD,PD4);

    sbi(PORTD,OE);
    cbi(PORTD,CP);
    cbi(PORTD,STR);
}

/* Second-counting interrupt service routine: */

#define SECONDS_PER_24H 86400

static volatile unsigned long half_seconds;
static volatile unsigned long seconds;

ISR( TIMER1_COMPA_vect )
{
    half_seconds ++;

    if( !(half_seconds & 0x01) ) {
	seconds ++;
    }

    if( seconds >= SECONDS_PER_24H ) {
	seconds = 0;
    }
}

#define SECONDS_PER_MINUTE 60
#define MINUTES_PER_HOUR   60
#define SECONDS_PER_HOUR   (SECONDS_PER_MINUTE * MINUTES_PER_HOUR)

#define DIGIT_BASE         10

void compute_digits( volatile unsigned short digits[] )
{
#if 1
    int whole_minutes = seconds / SECONDS_PER_MINUTE;
    int minutes = whole_minutes % MINUTES_PER_HOUR;
    int hours = whole_minutes / MINUTES_PER_HOUR;

    digits[3] = minutes % DIGIT_BASE;
    digits[2] = minutes / DIGIT_BASE;

    digits[1] = hours % DIGIT_BASE;
    digits[0] = hours / DIGIT_BASE;
#else
    unsigned int whole_minutes = seconds / SECONDS_PER_MINUTE;
    unsigned int minutes = whole_minutes % MINUTES_PER_HOUR;

    digits[3] = seconds % DIGIT_BASE;
    digits[2] = ((seconds % SECONDS_PER_MINUTE) / DIGIT_BASE) % DIGIT_BASE;

    digits[1] = minutes % DIGIT_BASE;
    digits[0] = (minutes / DIGIT_BASE) % DIGIT_BASE;
#endif
}

void put_digit( unsigned short digit )
{
    short i;
    short pattern = digit7seg[digit];

    cli();
    for( i = 0; i < 8; i ++ ) {
        // Output a pattern bit into the shifter:
        short bit = pattern & 0x01;
        pattern >>= 1;
        if(bit) {
            sbi(PORTD,D);
        } else {
            cbi(PORTD,D);
        }
        // Clock the shift:
        sbi(PORTD,CP);
        cbi(PORTD,CP);
    }
    sei();
}

void put_digits( volatile unsigned short digits[] )
{
    unsigned short i;

    cbi(PORTD,STR);
    for( i = 0; i < 4; i++ ) {
        put_digit( digits[i] );
    }
    sbi(PORTD,STR);
}

void setup_timer( void )
{
    /* Disable interrupts: */
    cli();
    /* Low Fuse should be FF for this setup; in particular, CKDIV8
       should be unprogrammed (1), so that the crystal clock
       frequencey is NOT divided by 8. */
    /* Set up Timer1 for 0.5s at 16.0000 MHz crystal: */
    /* Number of timer pre-scaled pulses to count: */
    OCR1A = 62500 / 2; /* Half-second intervals. */
    /* Mode 4, CTC on OCR1A: */
    TCCR1B |= (1 << WGM12);
    /* Set interrupt on compare match: */
    TIMSK |= (1 << OCIE1A);
    /* set prescaler to 256 and start the timer: */
    TCCR1B |= (1 << CS12);
    /* Enable interrupts: */
    sei();
}

#define DEBOUNCING_DELAY 50

unsigned short
read_buttons( void )
{
    static short countdown;
    static unsigned short old_buttons;
    unsigned short buttons;

    if( countdown > 0 ) {
        // Delay for debouncing:
        countdown --;
        return 0;
    } else {
        buttons = ~PINB & 0x1E;
        if( buttons != old_buttons ) {
            // A new button press event is detected:
            old_buttons = buttons;
            // Start debouncing:
            countdown = DEBOUNCING_DELAY;
            return buttons;
        }
        return 0;
    }
}

int main(void)
{
    init();
    setup_timer();

    unsigned short buttons;

    while (1) {

        compute_digits( digits );
        put_digits( digits );
        display_dots( half_seconds );
        buttons = read_buttons();

        if( buttons ) {
            switch( buttons ) {
            case 2:
                seconds += SECONDS_PER_MINUTE;
                break;
            case 4:
                if( seconds >= SECONDS_PER_MINUTE )
                    seconds -= SECONDS_PER_MINUTE;
                else
                    seconds = SECONDS_PER_24H - SECONDS_PER_MINUTE;
                break;
            case 8:
                seconds += SECONDS_PER_HOUR;
                break;
            case 16:
                if( seconds >= SECONDS_PER_HOUR )
                    seconds -= SECONDS_PER_HOUR;
                else
                    seconds = SECONDS_PER_24H - SECONDS_PER_HOUR;
                break;
            default:
                // do nothing;
                break;
            }
	    if( seconds >= SECONDS_PER_24H ) {
		seconds = 0;
	    }
            seconds = (seconds/SECONDS_PER_MINUTE)*SECONDS_PER_MINUTE;
        }

        //sleep_enable();
        //sei();
        //sleep_cpu();

    }
}
