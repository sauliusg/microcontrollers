#include <avr/io.h>

#define sbi(REGISTER,BIT) REGISTER |= (1 << BIT);    /* sets BIT in REGISTER */
#define cbi(REGISTER,BIT) REGISTER &= ~(1 << BIT);   /* clears BIT in REGISTER */

void delay_ms(unsigned short ms)
/* delay for a minimum of <ms> */
/* with a 4Mhz crystal, the resolution is 1 ms */
{
        unsigned short outer1, outer2;
        outer1 = 200; 

        while (outer1) {
                outer2 = 1000;
                while (outer2) {
                        while ( ms ) ms--;
                        outer2--;
                }
                outer1--;
        }
}

int main(void)
{
        /* enable  PD5 as output */
        /* sbi(DDRD,PD5); */
        DDRC |= 0xFF ;
        DDRD |= 0xFF;
        while (1) {
                /* led on, pin=0 */
                /* cbi(PORTD,PD5); */
	        PORTC |= 0xFF;
	        PORTD |= 0xFF;
                delay_ms(500);
                /* set output to 5V, LED off */
                /* sbi(PORTD,PD5); */
	        PORTC &= 0x0;
	        PORTD &= 0x0;
                delay_ms(500);
        }
        return 0;
}
