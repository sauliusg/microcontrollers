#include <avr/io.h>

#define sbi(REGISTER,BIT) REGISTER |= (1 << BIT);    /* sets BIT in REGISTER */
#define cbi(REGISTER,BIT) REGISTER &= ~(1 << BIT);   /* clears BIT in REGISTER */

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

int phase = 0;

void flash(short flash, short pause)
{
    /* LED on */
    short port = phase == 0 ? PD5 : PD4;
    sbi(PORTD,port);
    delay_ms(flash);
    /* LED off */
    cbi(PORTD,port);
    delay_ms(pause);
}

int main(void)
{
    short i;
    /* enable selected pin as an output: */
    sbi(DDRD,PD5);
    sbi(DDRD,PD4);
    // DDRB=2;
    while (1) {
        flash(200,200);
        flash(200,200);
        flash(200,200);
        delay_ms(1500);
        for( i = 100; i >= 20; i -= 10 ) {
            flash(i,i);
        }
        phase = (phase == 0 ? 1 : 0);
    }
    return 0;
}
