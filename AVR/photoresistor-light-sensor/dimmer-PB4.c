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

#define MAX_CAPACITOR_CHARGE_COUNT    10
#define MAX_CAPACITOR_DISCHARGE_COUNT 240

#define MAX_LED_COUNT    240
#define DIMMER_THRESHOLD 20

#define CAPACITOR_STATE_CHARGE 0x01
#define LED_STATE_ON           0x02

short state;

int main(void)
{
    unsigned long led_on_count = 0, led_count = 0;
    unsigned long capacitor_discharge_count = 0;
    unsigned long prev_capacitor_discharge_count = 0;
    unsigned short capacitor_charge_count = 0;
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
                prev_capacitor_discharge_count = capacitor_discharge_count;
            }
        }

        led_count ++;
        if( state & LED_STATE_ON ) {
            if( led_count > led_on_count ) {
                cbi( PORTB, PB3 ); // LED off
                state &= ~LED_STATE_ON;
            }
        }
        if( led_count >= MAX_LED_COUNT ) {
            led_count = 0;
            sbi( PORTB, PB3 ); // LED on
            state |= LED_STATE_ON;
            if( prev_capacitor_discharge_count <
                MAX_LED_COUNT - DIMMER_THRESHOLD ) {
                led_on_count = MAX_LED_COUNT - prev_capacitor_discharge_count;
            } else {
                led_on_count = DIMMER_THRESHOLD;
            }
        }

    }
    return 0;
}
