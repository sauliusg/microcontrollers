#include <avr/io.h>

#define sbi(REGISTER,BIT) REGISTER |= (1 << BIT);    /* sets BIT in REGISTER */
#define cbi(REGISTER,BIT) REGISTER &= ~(1 << BIT);   /* clears BIT in REGISTER */

/*

µC ports:

pin 2 PB3: ---/\/\/\---->|----|

                       /   /
                     |/_ |/_
pin 3 PB4: -o------/\/\/\------|
            |
             --------||--------|
*/

void delay(unsigned long delay)
{
    while ( delay ) {
	delay--;
        unsigned short inner = 200;
        while( inner ) {
            inner --;
        }
    }
}

void flash(short flash, short pause)
{
    /* LED on: */
    sbi(PORTB,PB3);
    delay(flash);
    /* LED off: */
    cbi(PORTB,PB3);
    delay(pause);
}

int main(void)
{
    unsigned long count;
    /* enable selected pins as an output: */
    sbi(DDRB,PB3); // PB3 is output
    while (1) {
        /* apply voltage to charge the capacitor: */
        sbi(DDRB,PB4);  // PB4 is output
        sbi(PORTB,PB4);
        delay(400);

        /* Watch the capacitor discharge via the photoresitor and
           check the time of the discharge (RC time constant): */
        cbi(DDRB,PB4);  // PB4 is input

        /* Read the LED voltage, wait until it falls to logical 0: */
        cbi(DDRB,PB4);  // PB4 is input
        count = 1;
        unsigned short led;
        do {
            led = PINB;
            count++;
        } while( led & 0x10 );

        // /* switch the LED "on" for a time proportional to 'count': */
        // sbi(DDRB,PB4);  // PB4 is output
        // cbi(PORTB,PB4); // PB4 low
        // sbi(PORTB,PB3); // PB3 high
        // delay(count);

        // Flash 'count' times:
        while( count > 0 ) {
            flash(80,80);
            count --;
        }
        delay(400);
    }
    return 0;
}
