#include <avr/io.h>
#include <avr/interrupt.h>

#define sbi(REGISTER,BIT) REGISTER |= (1 << BIT);    /* sets BIT in REGISTER */
#define cbi(REGISTER,BIT) REGISTER &= ~(1 << BIT);   /* clears BIT in REGISTER */

static volatile unsigned short digits[4];

void delay_short( unsigned short count )
{
    while( count-- > 0 );
}


/*
 Segment layout -- segment are assigned to the 74HC4094 shifter
 parallel output pins:
*/

#define SEG_A 0x80
#define SEG_B 0x40
#define SEG_C 0x20
#define SEG_D 0x10
#define SEG_E 0x08
#define SEG_F 0x04
#define SEG_G 0x02
#define SEG_H 0x01

static short digit7seg[] = {
    /* 0 */ 0xFF & (~ (SEG_G | SEG_H )),
    /* 1 */ SEG_B + SEG_C,
    /* 2 */ SEG_A + SEG_B + SEG_G + SEG_E + SEG_D,
    /* 3 */ SEG_A + SEG_B + SEG_G + SEG_C + SEG_D,
    /* 4 */ SEG_F + SEG_G + SEG_B + SEG_C,
    /* 5 */ SEG_A + SEG_F + SEG_G + SEG_C + SEG_D,
    /* 6 */ 0xFF & (~ (SEG_B | SEG_H)),
    /* 7 */ SEG_A + SEG_B + SEG_C,
    /* 8 */ 0xFF & (~SEG_H),
    /* 6 */ 0xFF & (~ (SEG_E | SEG_H)),
    /* A */ 0xFF & (~ (SEG_D | SEG_H)),
    /* B */ SEG_F + SEG_G + SEG_E + SEG_C + SEG_D,
    /* C */ SEG_A + SEG_F + SEG_E + SEG_D,
    /* D */ SEG_B + SEG_G + SEG_E + SEG_C + SEG_D,
    /* E */ SEG_A + SEG_F + SEG_G + SEG_E + SEG_D,
    /* F */ SEG_A + SEG_F + SEG_G + SEG_E,
};

/* Hour dot leds: */
/* 
   PD5
   PD4
*/

/* Button pins: */
/* short buttons = ~PINB & 0x1E; */


// 74HC4094 shift register pin number assignments:
int D   = PD0; // Serial data in
int CP  = PD1; // Serial data clock
int STR = PD2; // Strobe: latch shifted values into a parallel output
int OE  = PD3; // Output Enable

/* Initialise microcontroller: */
void init(void)
{
    /* Enable selected pins as inputs: */
    cbi(DDRB,PB1);
    cbi(DDRB,PB2);
    cbi(DDRB,PB3);
    cbi(DDRB,PB4);

    /* Enable selected pins as an output: */
    sbi(DDRD,PD0);
    sbi(DDRD,PD1);
    sbi(DDRD,PD2);
    sbi(DDRD,PD3);

    sbi(DDRD,PD5);
    sbi(DDRD,PD4);
    // DDRB=2;

    sbi(PORTD,OE);
    cbi(PORTD,CP);
    cbi(PORTD,STR);
}

void put_digit( unsigned short digit )
{
    short i;
    short pattern = digit7seg[digit];

    for( i = 0; i < 8; i ++ ) {
        // Output a pattern bit into the shifter:
        short bit = pattern & 0x01;
        pattern >>= 1;
        if(bit) {
            sbi(PORTD,D);
        } else {
            cbi(PORTD,D);
        }
        // Clock the shift:
        sbi(PORTD,CP);
        cbi(PORTD,CP);
    }
}

void put_digits( volatile unsigned short digits[] )
{
    unsigned short i;

    cbi(PORTD,STR);
    for( i = 0; i < 4; i++ ) {
        put_digit( digits[i] );
    }
    sbi(PORTD,STR);
}

int main(void)
{
    unsigned short i;

    init();

    digits[0] = 0;
    digits[1] = 9;
    digits[2] = digits[3] = 6;
    
    while (1) {

        put_digits( digits );

        for( i = 0; i <= 255; i++ ) {
            delay_short(255);
        }
    }
}
