#include <Wire.h>

#define I2C1_7BITADDR 0x07 // FS2012
//#define I2C1_SCL 8
//#define I2C1_SDA 7

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

//SlowSoftI2CMaster si1 = SlowSoftI2CMaster(I2C1_SDA, I2C1_SCL, /*internal_pullups=*/true);

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

void loop()
{
//  if (!si1.i2c_start((I2C1_7BITADDR<<1)|I2C_WRITE)) { // init transfer
//      Serial.println("I2C device busy");
//  }
//  si1.i2c_rep_start((I2C1_7BITADDR<<1)|I2C_READ); // restart for reading
//  byte msb = si1.i2c_read(true); // read one byte
//  byte lsb = si1.i2c_read(true); // read one byte and send NAK afterwards
//  si1.i2c_stop(); // stop communication

  Wire.beginTransmission( I2C1_7BITADDR );
  // Following example at
  // https://www.electroschematics.com/9798/reading-temperatures-i2c-arduino/ (S.G.):
  // request two bytes from the flow meter:
  Wire.requestFrom( (uint8_t)I2C1_7BITADDR, (uint8_t)2 );
  // wait for response:
//  while(Wire.available() == 0);
  unsigned int msb = Wire.read();
  unsigned int lsb = Wire.read();
  Serial.print( "msb = 0x" ); Serial.print( msb, HEX ); Serial.print( ", " );
  Serial.print( "lsb = 0x" ); Serial.print( lsb, HEX ); Serial.print( ", " );
  Wire.endTransmission();
  // Another example available at
  // https://www.arduino.cc/en/Reference/WireRead (S.G.).

  unsigned int iflow = (msb << 8) | lsb;
  unsigned int aflow = analogRead(A0);
  
  Serial.print("analog: ");
  Serial.print(aflow);
  Serial.print(" digital: ");
  Serial.println(iflow);
  
  digitalWrite(OE,HIGH);
  /* Update the display with the current counter value */
  unsigned long long tens_power = 1;
  for( int i = 0; i < 4; i++ ) {
    WriteNumberToSegment( i, (aflow/tens_power)%10 );
    tens_power *= 10;
    delay(1);
  }
  for( int i = 4; i < 5; i++ ) {
    WriteNumberToSegment( i, (iflow/tens_power)%10 );
    tens_power *= 10;
    delay(1);
  }
}

/* Write a decimal number between 0 and 9 to one of the 4 digits of the display */
void WriteNumberToSegment(byte Segment, byte Value)
{
  digitalWrite(LATCH_DIO,LOW);
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[Value]);
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Segment] );
  digitalWrite(LATCH_DIO,HIGH);
}
