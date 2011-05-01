#include <avr/io.h>

#define sbi(REGISTER,BIT) REGISTER |= (1 << BIT);    /* sets BIT in REGISTER */
#define cbi(REGISTER,BIT) REGISTER &= ~(1 << BIT);   /* clears BIT in REGISTER */

void delay_ms(unsigned short ms)
/* delay for a minimum of <ms> */
/* with a 4Mhz crystal, the resolution is 1 ms */
{
        unsigned short outer1, outer2;
        outer1 = 160; 

        while (outer1) {
                outer2 = 500;
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
        sbi(DDRD,PD5);
        while (1) {
                /* led on, pin=0 */
                cbi(PORTD,PD5);
                delay_ms(500);
                /* set output to 5V, LED off */
                sbi(PORTD,PD5);
                delay_ms(500);
        }
        return 0;
}
