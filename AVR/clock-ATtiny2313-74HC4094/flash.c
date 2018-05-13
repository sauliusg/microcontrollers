#include <avr/io.h>

#define sbi(REGISTER,BIT) REGISTER |= (1 << BIT);    /* sets BIT in REGISTER */
#define cbi(REGISTER,BIT) REGISTER &= ~(1 << BIT);   /* clears BIT in REGISTER */

#define SEG_A 0x40
#define SEG_B 0x20
#define SEG_C 0x08
#define SEG_D 0x10
#define SEG_E 0x04
#define SEG_F 0x80
#define SEG_G 0x01
#define SEG_H 0x02

#if 0
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
#endif

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

#if 1
// 74HC4094 shift register pin number assignments:
int D   = PD0; // Serial data in
int CP  = PD1; // Serial data clock
int STR = PD2; // Strobe: latch shifted values into a parallel output
int OE  = PD3; // Output Enable
#endif

#if 1
int digits[][8] = {
//  DP,F,A,B, C,G,D,E -- 7-seg segments
//   7,6,5,4, 3,2,1,0 -- 74HC4094 QP pins
//   | | | |  | | | |
    {0,1,1,1, 1,0,1,1}, // 0
    {0,0,0,1, 1,0,0,0}, // 1
    {0,0,1,1, 0,1,1,1}, // 2
    {0,0,1,1, 1,1,1,0}, // 3
    {0,1,0,1, 1,1,0,0}, // 4
    {0,1,1,0, 1,1,1,0}, // 5
    {0,1,1,0, 1,1,1,1}, // 6
    {0,0,1,1, 1,0,0,0}, // 7
#if 0
    {0,1,1,1, 1,1,1,1}, // 8

    {0,1,1,1, 1,1,1,0}, // 9
    {0,1,1,1, 1,1,0,1}, // A
    {0,1,0,0, 1,1,1,1}, // b
    {0,1,1,0, 0,0,1,1}, // C
    {0,0,0,1, 1,1,1,1}, // d
    {0,1,1,0, 0,1,1,1}, // E
    {0,1,1,0, 0,1,0,1}, // F
    {0,0,0,0, 0,0,0,0}, // blank
    {1,1,1,1, 1,1,1,1}, // all on
#endif
};

int ones[] = {1,1,1,1, 1,1,1,1};
int zeros[] = {0,0,0,0, 0,0,0,0};

unsigned int count = 0;

#endif

int main(void)
{
    short i;
    /* enable selected pins as an output: */
#if 1
    sbi(DDRD,PD0);
    sbi(DDRD,PD1);
    sbi(DDRD,PD2);
    sbi(DDRD,PD3);
#endif
    sbi(DDRD,PD5);
    sbi(DDRD,PD4);
    // DDRB=2;
#if 1
    sbi(PORTD,OE);
    cbi(PORTD,CP);
    cbi(PORTD,STR);
#endif

    while (1) {
        flash(200,200);
        flash(200,200);
        flash(200,200);
        delay_ms(1500);
        for( i = 100; i >= 20; i -= 10 ) {
            flash(i,i);
        }
#if 0
        int *pattern;
  
        cbi(PORTD,STR);
        pattern = phase ? ones : zeros;
        int i;
        for( i = 0; i < sizeof(digits[0])/sizeof(digits[0][0]); i ++ ) {
            // pattern = digits[count % 16];
            // Output a pattern bit into the shifter:
            if(pattern) {
                sbi(PORTB,D);
            } else {
                cbi(PORTB,D);
            }
            // Clock the shift:
            sbi(PORTD,CP);
            delay_ms(1);
            sbi(PORTD,CP);
        }
        sbi(PORTD,STR);

        count ++;
#endif
        phase = (phase == 0 ? 1 : 0);
    }
    return 0;
}
