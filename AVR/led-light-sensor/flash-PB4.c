#include <avr/io.h>

#define sbi(REGISTER,BIT) REGISTER |= (1 << BIT);    /* sets BIT in REGISTER */
#define cbi(REGISTER,BIT) REGISTER &= ~(1 << BIT);   /* clears BIT in REGISTER */

/*

Led ports:

pin 2 PB3: ---->|----
                    |
pin 3 PB4: --/\/\/\-- 

*/

void delay_ms(unsigned short ms)
/* delay for a minimum of <ms> */
/* with a 4Mhz crystal, the resolution is 1 ms */
{
    unsigned short inner;

    while ( ms ) {
	ms--;
	inner = 200;
	while (inner) {
	    inner--;
	}
    }
}

void flash(short flash, short pause)
{
    /* LED */
    cbi(PORTB,PB3);
    sbi(PORTB,PB4);
    delay_ms(flash);
    /* LED invert */
    sbi(PORTB,PB3);
    cbi(PORTB,PB4);
    delay_ms(pause);
}

int main(void)
{
    /* enable selected pins as an output: */
    sbi(DDRB,PB3);
    sbi(DDRB,PB4);
    while (1) {
        flash(200,200);
    }
    return 0;
}
