#include <avr/io.h>

#define sbi(REGISTER,BIT) REGISTER |= (1 << BIT);    /* sets BIT in REGISTER */
#define cbi(REGISTER,BIT) REGISTER &= ~(1 << BIT);   /* clears BIT in REGISTER */

static short digits[4];

void delay_short( unsigned short count )
{
    while( count-- > 0 );
}

void delay_ms(unsigned short ms)
{
        unsigned short outer1, outer2, innermost;
        outer1 = 20;

        while (outer1) {
                outer2 = 20;
                while (outer2) {
		        innermost = ms;
                        while ( innermost ) {
			    innermost--;
			}
                        outer2--;
			if( PORTC == 0x01 ) {
			    PORTD = 0;
			    PORTC = 0x00;
			    delay_short( 200 );
			    PORTC = 0x02;
			    PORTD = digits[1];
			} else if( PORTC == 0x32 ) {
			    PORTD = 0;
			    PORTC = 0x00;
			    delay_short( 200 );
			    PORTC = 0x04;
			    PORTD = digits[2];
			} else if( PORTC == 0x34 ) {
			    PORTD = 0;
			    PORTC = 0x00;
			    delay_short( 200 );
			    PORTC = 0x08;
			    PORTD = digits[3];
			} else {
			    PORTD = 0;
			    PORTC = 0x00;
			    delay_short( 200 );
			    PORTC = 0x01;
			    PORTD = digits[0];
			}
                }
                outer1--;
        }
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

 common - PC5

 PORTB:

 button1 - PD6
 button2 - PD7
 button3 - PD4
 button4 - PD5
 
*/

short read( void )
{
    short i;
    short val = 0xFF;

    /* disable all 7-seg indicators: */
    PORTC = 0x00;
    /* enable common button pin PC5: */
    /* programm PC5 for output, set it low */
    DDRC  |= 0x20;
    PORTC = 0x00;
    // DDRC  |= 0xF0;
    // PORTC |= 0xF0;
    /* program PORTD PB3 - PB5 for input: */
    // DDRD  |= ~(0x04 + 0x08 + 0x10);
    DDRD = 0x00;
    /* enable pull-up resistors: */
    // PORTD = 0x04 + 0x08 + 0x10;
    PORTD = 0xFF;

    /* read the values, do debouncing: */
    for( i = 0; i < 127; i++ ) {
	val &= PIND;
    }

    /* clean up the ports: */
    /* disable PORTD pull-up resistors: */
    PORTD = 0x00;
    /* program PORTD for output: */
    DDRD  = 0xFF;

    //val |= ~(0x04 + 0x08 + 0x10);
    return val;
}

int main(void)
{
        short i = 0;
	short j = 0;
        /* enable  PD5 as output */
        /* sbi(DDRD,PD5); */
        DDRC |= 0x0F;
        DDRD |= 0xFF;
	PORTC = 0x01;
	PORTD = 0x00;
	digits[2] = digits[0] = 0;
        while (1) {
	        // digits[2] = digit7seg[i];
	        // digits[3] = digit7seg[i];
                /* led on, pin=0 */
                /* cbi(PORTD,PD5); */
                delay_ms(100);
		i = read();
		// i = (i>>4)&0x0F;
		// i &= 0x0F;
		digits[0] = digit7seg[i & 0x0F];
		digits[1] = digit7seg[(i >> 4) & 0x0F] | SEG_H;
		/*
                if( i > 15 ) {
		    i = 0;
		    j ++;
		    if( j > 15 )
			j = 0;
		    if( j == 0 ) {
			digits[0] = 0;
			digits[2] = 0;
		    } else {
			digits[0] = digit7seg[j];
			digits[2] = digit7seg[j];
		    }
		}
		*/
        }
        return 0;
}
