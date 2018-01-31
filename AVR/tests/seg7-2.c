#include <avr/io.h>

#define sbi(REGISTER,BIT) REGISTER |= (1 << BIT);    /* sets BIT in REGISTER */
#define cbi(REGISTER,BIT) REGISTER &= ~(1 << BIT);   /* clears BIT in REGISTER */

void delay_ms(unsigned short ms)
/* delay for a minimum of <ms> */
/* with a 4Mhz crystal, the resolution is 1 ms */
{
        unsigned short outer1, outer2, innermost;
        outer1 = 20;

        while (outer1) {
                outer2 = 200;
                while (outer2) {
		        innermost = ms;
                        while ( innermost ) innermost--;
                        outer2--;
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
};

int main(void)
{
        /* enable  PD5 as output */
        /* sbi(DDRD,PD5); */
        DDRC |= 0x01;
        DDRD |= 0xFF;
	PORTD |= digit7seg[2];
        while (1) {
                /* led on, pin=0 */
                /* cbi(PORTD,PD5); */
	        PORTC |= 0x01;
                delay_ms(20);
                /* set output to 5V, LED off */
                /* sbi(PORTD,PD5); */
	        PORTC &= 0x0;
	        /* PORTD &= 0x0; */
                delay_ms(20);
        }
        return 0;
}
