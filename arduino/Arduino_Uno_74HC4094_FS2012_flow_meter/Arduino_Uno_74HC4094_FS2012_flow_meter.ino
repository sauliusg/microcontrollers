/* Define shift register pins used for seven segment display */
#define LATCH_DIO 10
#define CLK_DIO   14
#define DATA_DIO  16
#define OE         9

/*
 Segment layout -- segments are assigned to the shifter
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

/* Segment byte maps for numbers 0 to 9 */
const byte SEGMENT_MAP[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0X80,0X90};
/* Byte maps to select digit 1 to 4 */
const byte SEGMENT_SELECT[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};

void WriteNumberToSegment(byte Segment, byte Value);

void setup()
{
  // initialize the digital pin as an output.
  /* Set DIO pins to outputs */
  pinMode(LATCH_DIO,OUTPUT);
  pinMode(CLK_DIO,OUTPUT);
  pinMode(DATA_DIO,OUTPUT);
  pinMode(OE,OUTPUT);
}

int counter = 0;

void loop()
{
  digitalWrite(OE,HIGH);
  /* Update the display with the current counter value */
  for( int i = 0; i < 8; i++ ) {
    WriteNumberToSegment( i, counter%10 );
    delay(200);
  }
  counter ++;
}

/* Write a decimal number between 0 and 9 to one of the 4 digits of the display */
void WriteNumberToSegment(byte Segment, byte Value)
{
  digitalWrite(LATCH_DIO,HIGH);
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[Value]);
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Segment] );
  digitalWrite(LATCH_DIO,LOW);
}
