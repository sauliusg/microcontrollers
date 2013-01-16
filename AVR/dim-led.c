#include <avr/io.h>

#define sbi(REGISTER,BIT) REGISTER |= (1 << BIT);    /* sets BIT in REGISTER */
#define cbi(REGISTER,BIT) REGISTER &= ~(1 << BIT);   /* clears BIT in REGISTER */

void delay(unsigned short steps)
/* delay for a minimum of <steps> */
{
    unsigned short inner;

    while ( steps ) {
	steps--;
	inner = 10;
	while (inner) {
	    inner--;
	}
    }
}

void flash(short flash, short duration)
{
    /* LED on */
    sbi(PORTD,PD5);
    delay(flash);
    /* LED off */
    cbi(PORTD,PD5);
    delay(duration-flash);
}

int main(void)
{
    short i, j;
    short duration = 200;
    /* enable  PD5 as output */
    sbi(DDRD,PD5);
    /* enable  Port D as output */
    DDRD=0xFF;;
    while (1) {
	for( i = 0; i < duration-duration/3; i ++ ) {
	    for( j = 0; j < 2; j++ ) {
		flash(i,duration);
	    }
	}
	for( i = duration-duration/3; i >= 0; i -- ) {
	    for( j = 0; j < 2; j++ ) {
		flash(i,duration);
	    }
	}
	for( i = 0; i < 10; i ++ ) {
	    delay(1600);
	}
    }
    return 0;
}
