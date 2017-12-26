#include <avr/io.h>

#define sbi(REGISTER,BIT) REGISTER |= (1 << BIT);    /* sets BIT in REGISTER */
#define cbi(REGISTER,BIT) REGISTER &= ~(1 << BIT);   /* clears BIT in REGISTER */

static short digits[4];

void delay_short( unsigned short count )
{
    while( count-- > 0 );
}

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

 indicator 0 (leftomost) : PC0
 indicator 1             : PC1
 indicator 2             : PC2
 indicator 3 (rightmost) : PC3

 common - PC5

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

    /* disable all 7-seg indicators; set pin PC5 to low: */
    PORTC = 0x00;
    /* Clearing old values from PORTD: */
    PORTD = 0xFF;
    /* Configure PORTD for input: */
    DDRD = 0x00;

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

void display_digits(unsigned short cycles)
{
    PORTC = 0x21;
    PORTD = digits[0];
    delay_short( cycles );

    PORTC = 0x22;
    PORTD = digits[1];
    delay_short( cycles );

    PORTC = 0x24;
    PORTD = digits[2];
    delay_short( cycles );

    PORTC = 0x28;
    PORTD = digits[3];
    delay_short( cycles );
}

static short old_buttons;

static short counts[4];

void read_buttons( unsigned short read_cycles )
{
    short buttons = read( read_cycles ) >> 4;;
    if( buttons != old_buttons ) {
	short i;
	for( i = 0; i < 4; i++ ) {
	    short mask = (0x01 << i);
	    if( (buttons & mask) < (old_buttons & mask) ) {
		counts[i] ++;
		if( counts[i] > 15 ) {
		    counts[i] = 0;
		}
		digits[i] = digit7seg[counts[i]];
	    }
	}
	for( i = 0; i < 4; i++ ) {
	    short mask = (0x01 << i);
	    if( buttons & mask ) {
		digits[i] |= SEG_H;
	    } else {
		digits[i] &= ~SEG_H;
	    }
	}
	
	old_buttons = buttons;
    }
    //digits[0] = digit7seg[buttons & 0x0F];
    //digits[1] = digit7seg[(buttons >> 4) & 0x0F] | SEG_H;    
}

void read_and_display( unsigned short display_cycles,
		       unsigned short read_cycles )
{
    display_digits( display_cycles );
    read_buttons( read_cycles );
}

int main(void)
{
    DDRC |= 0x2F;
    DDRD |= 0xFF;
    PORTD = 0x00;

    digits[0] = digit7seg[0];
    digits[1] = digit7seg[1];
    digits[2] = digit7seg[2];
    digits[3] = digit7seg[3];

    while (1) {
	read_and_display( /* display_cycles = */ 200,
			  /* read_cycles = */ 127 );
    }
}
