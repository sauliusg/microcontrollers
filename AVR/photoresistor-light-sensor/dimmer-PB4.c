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

#define MAX_CAPACITOR_CHARGE_COUNT    10
#define MAX_CAPACITOR_DISCHARGE_COUNT 2400

#define MAX_LED_COUNT 240

#define CAPACITOR_STATE_CHARGE 0x01
#define LED_STATE_ON           0x02

short state;

int main(void)
{
    unsigned long led_on_count; // , led_count;
    unsigned long capacitor_discharge_count;
    unsigned short capacitor_charge_count;
    /* enable selected pins as an output: */
    sbi(DDRB,PB3); // PB3 is output
    while (1) {
        if( state & CAPACITOR_STATE_CHARGE ) {
            capacitor_charge_count ++;
            if( capacitor_charge_count >= MAX_CAPACITOR_CHARGE_COUNT ) {
                state &= ~CAPACITOR_STATE_CHARGE;
                cbi(DDRB,PB4);  // PB4 is input
                capacitor_discharge_count = 0;
            }
        } else {
            unsigned short led = PINB;
            if( led & 0x10 ) {
                // Not yet discharged:
                capacitor_discharge_count ++;
            }
            if( !(led & 0x10) ||
                capacitor_discharge_count > MAX_CAPACITOR_DISCHARGE_COUNT ) {
                // Discharged, or reached maximum count:
                state |= CAPACITOR_STATE_CHARGE;
                sbi(DDRB,PB4);  // PB4 is output
                sbi(PORTB,PB4);
                capacitor_charge_count = 0;
                led_on_count = capacitor_discharge_count;                
            }
        }

        flash(led_on_count,led_on_count);

    }
    return 0;
}
