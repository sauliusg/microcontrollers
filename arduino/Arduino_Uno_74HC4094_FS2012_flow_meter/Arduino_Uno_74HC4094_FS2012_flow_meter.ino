#include <SlowSoftI2CMaster.h>

#define I2C1_7BITADDR 0x07 // FS2012
#define I2C1_SDA 4
#define I2C1_SCL 5

#define I2C2_7BITADDR 0x07 // FS2012
#define I2C2_SDA 6
#define I2C2_SCL 7

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

SlowSoftI2CMaster si1 = SlowSoftI2CMaster(I2C1_SDA, I2C1_SCL, /*internal_pullups=*/true);
SlowSoftI2CMaster si2 = SlowSoftI2CMaster(I2C2_SDA, I2C2_SCL, /*internal_pullups=*/true);

void setup()
{
  // initialize the digital pin as an output.
  /* Set DIO pins to outputs */
  pinMode(LATCH_DIO,OUTPUT);
  pinMode(CLK_DIO,OUTPUT);
  pinMode(DATA_DIO,OUTPUT);
  pinMode(OE,OUTPUT);
  
  Serial.begin(9600);
  Serial.println("FS2012 Flow Meter test (Soft I2C)");
}

unsigned int iflow;
unsigned int aflow;
unsigned int iflow_2;
unsigned int aflow_2;

unsigned long long count;

void loop()
{
  if( count % 100 == 0 ) { 
    if (!si1.i2c_start((I2C1_7BITADDR<<1)|I2C_WRITE)) { // init transfer
        Serial.println("I2C 1st device busy");
    }
    si1.i2c_rep_start((I2C1_7BITADDR<<1)|I2C_READ); // restart for reading
    byte msb = si1.i2c_read(false); // read one byte
    byte lsb = si1.i2c_read(true); // read one byte and send NAK afterwards
    si1.i2c_stop(); // stop communication
  
    if (!si2.i2c_start((I2C2_7BITADDR<<1)|I2C_WRITE)) { // init transfer
        Serial.println("I2C 2nd device busy");
    }
    si2.i2c_rep_start((I2C2_7BITADDR<<1)|I2C_READ); // restart for reading
    byte msb_2 = si2.i2c_read(false); // read one byte
    byte lsb_2 = si2.i2c_read(true); // read one byte and send NAK afterwards
    si2.i2c_stop(); // stop communication

    iflow = (msb << 8) | lsb;
    aflow = analogRead(A0);
    iflow_2 = (msb_2 << 8) | lsb_2;
    aflow_2 = analogRead(A1);
  
    Serial.print("analog1: ");
    Serial.print(aflow);
    Serial.print(" digital1: ");
    Serial.print(iflow);
    Serial.print("     analog2: ");
    Serial.print(aflow_2);
    Serial.print(" digital2: ");
    Serial.print(iflow_2);
    Serial.println();
  }
  
  digitalWrite(OE,HIGH);
  /* Update the display with the current counter value */
  unsigned long long tens_power = 1;
  for( int i = 0; i < 4; i++ ) {
    WriteNumberToSegment( i, (iflow/tens_power)%10 );
    tens_power *= 10;
    delay(1);
  }
  tens_power = 1;
  for( int i = 4; i < 8; i++ ) {
    WriteNumberToSegment( i, (iflow_2/tens_power)%10 );
    tens_power *= 10;
    delay(1);
  }

  count++;
}

/* Write a decimal number between 0 and 9 to one of the 4 digits of the display */
void WriteNumberToSegment(byte Segment, byte Value)
{
  digitalWrite(LATCH_DIO,LOW);
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[Value]);
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Segment] );
  digitalWrite(LATCH_DIO,HIGH);
}
