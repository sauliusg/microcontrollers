#include <avr/io.h>

#define sbi(REGISTER,BIT) REGISTER |= (1 << BIT);    /* sets BIT in REGISTER */
#define cbi(REGISTER,BIT) REGISTER &= ~(1 << BIT);   /* clears BIT in REGISTER */

/*

Led ports:

pin 2 PB3: --/\/\/\-- 
                    |
pin 3 PB4: ----|<----

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
    /* LED off: */
    cbi(PORTB,PB3);
    sbi(PORTB,PB4);
    delay(flash);
    /* LED on: */
    sbi(PORTB,PB3);
    cbi(PORTB,PB4);
    delay(pause);
}

int main(void)
{
    unsigned long count;
    /* enable selected pins as an output: */
    sbi(DDRB,PB3);
    while (1) {
        /* apply directo voltage to the LED: */
        sbi(DDRB,PB4);  // PB4 is output
        cbi(PORTB,PB4); // PB4 low
        sbi(PORTB,PB3); // PB3 high
        delay(200);

        /* apply reverse voltage to the LED: */
        sbi(PORTB,PB4); // PB4 high
        cbi(PORTB,PB3); // PB3 low
        delay(20);     // wait for a LED "capacitor" to charge.

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
        sbi(DDRB,PB4);  // PB4 is output
        while( count > 0 ) {
            flash(100,100);
            count --;
        }
        delay(400);
    }
    return 0;
}
