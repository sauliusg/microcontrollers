#include <avr/io.h>

#define sbi(REGISTER,BIT) REGISTER |= (1 << BIT);    /* sets BIT in REGISTER */
#define cbi(REGISTER,BIT) REGISTER &= ~(1 << BIT);   /* clears BIT in REGISTER */

void delay_ms(unsigned short ms)
/* delay for a minimum of <ms> */
/* with a 4Mhz crystal, the resolution is 1 ms */
{
#if 0
          unsigned short outer1, outer2, innermost;
          outer1 = 160;
  
          while (outer1) {
                  outer2 = 200;
                  while (outer2) {
  		        innermost = ms;
                          while ( innermost ) innermost--;
                          outer2--;
                  }
                  outer1--;
          }
#else
          unsigned short outer, inner;

	  outer = ms;
          while ( outer ) {
	      inner = 80;
	      while( inner ) {
		  inner --;
	      }
	      outer --;
          }
#endif
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

int main(void)
{
        /* enable  PC0,1 as output */
        sbi(DDRC,PC0);
        sbi(DDRC,PC1);
        /* enable  Port D as output */
        DDRD = 0xFF;
	PORTD = 0x00;
        while (1) {
	        /* set pins PC0 and PC1 */
	        sbi(PORTC,PC0);
	        cbi(PORTC,PC1);

                /* LED */
                //cbi(PORTD,PD2);
		PORTD=0x00;
                delay_ms(1000);
                /* set output to 5V, LED off */
                //sbi(PORTD,PD2);
		PORTD=0xFF;
                delay_ms(1000);

                /* set pins PC0 and PC1 to opposite */
	        cbi(PORTC,PC0);
	        sbi(PORTC,PC1);

                /* another LED*/
                //cbi(PORTD,PD2);
		PORTD=0x00;
                delay_ms(1000);
                /* set output to 5V, LED off */
                //sbi(PORTD,PD2);
		PORTD=0xFF;
                delay_ms(1000);
        }
        return 0;
}
