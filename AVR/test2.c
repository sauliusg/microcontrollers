#include <avr/io.h>

#define sbi(REGISTER,BIT) REGISTER |= (1 << BIT);    /* sets BIT in REGISTER */
#define cbi(REGISTER,BIT) REGISTER &= ~(1 << BIT);   /* clears BIT in REGISTER */

void delay_ms(unsigned short ms)
/* delay for a minimum of <ms> */
/* with a 4Mhz crystal, the resolution is 1 ms */
{
        unsigned short outer1, outer2, innermost;
        outer1 = 160;

        while (outer1) {
                outer2 = 50;
                while (outer2) {
		        innermost = ms;
                        while ( innermost ) innermost--;
                        outer2--;
                }
                outer1--;
        }
}

int main(void)
{
        /* enable  PD5 as output */
        sbi(DDRD,PD5);

        while (1) {
                /* led on, pin=0 */
                cbi(PORTD,PD5);
                delay_ms(4);
                /* set output to 5V, LED off */
                sbi(PORTD,PD5);
                delay_ms(4);

                cbi(PORTD,PD5);
                delay_ms(4);
                sbi(PORTD,PD5);
                delay_ms(4);
		 
                cbi(PORTD,PD5);
                delay_ms(4);
                sbi(PORTD,PD5);
                delay_ms(4);

                cbi(PORTD,PD5);
                delay_ms(4);
                sbi(PORTD,PD5);
                delay_ms(4);

		cbi(PORTD,PD5);
                delay_ms(20);
		
       }
        return 0;
}
