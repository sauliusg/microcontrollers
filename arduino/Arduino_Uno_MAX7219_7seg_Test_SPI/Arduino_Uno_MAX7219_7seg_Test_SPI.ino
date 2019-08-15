#include <SPI.h>

/* Chip (Slave) select pin: */
#define CS 10

#define DATA 11
#define CLK  13

/* Segment byte maps for numbers 0 to 9, "1" bit means segment is ON: */
//                           "0"  "1"  "2"  "3"  "4"  "5"  "6"  "7"  "8"  "9"
const byte SEGMENT_MAP[] = {0x7E,0x30,0x6D,0x79,0x33,0x5B,0x5F,0x70,0x7F,0x7B};

#define DECIMAL_POINT 0x80;

SPISettings spi_settings = SPISettings(5000000, MSBFIRST, SPI_MODE0);

void output_max7219( byte reg, byte data )
{
  digitalWrite(CS,LOW);
  // See https://www.arduino.cc/en/Reference/SPI for an example:
  SPI.beginTransaction(spi_settings);
  SPI.transfer(reg);
  SPI.transfer(data);
  SPI.endTransaction();
  digitalWrite(CS,HIGH);
}

void output_max7219_16( uint16_t payload )
{
  digitalWrite(CS,LOW);
  // See https://www.arduino.cc/en/Reference/SPI for an example:
  SPI.beginTransaction(spi_settings);
  SPI.transfer16(payload);
  SPI.endTransaction();
  digitalWrite(CS,HIGH);
}

void setup ()
{
  SPI.begin();
  pinMode(CS, OUTPUT); 

  output_max7219( 0x0B, 0x0F ); // Set scan to all digits
  output_max7219( 0x09, 0x00 ); // Not decoding any digits
  output_max7219( 0x0A, 0xFF ); // Set intensity to max.

  output_max7219( 0x0C, 0x00 ); // Shutdown
  output_max7219( 0x0C, 0x01 ); // Wake-up after a shutdown
  output_max7219( 0x0F, 0xFF ); // Test
  output_max7219( 0x0F, 0xFE ); // Normal mode
  delay(10);
  output_max7219( 0x0F, 0xFF ); // Test
  output_max7219( 0x0F, 0xFE ); // Normal mode

  output_max7219( 0x01, SEGMENT_MAP[0] );
  output_max7219( 0x02, SEGMENT_MAP[1] );
  output_max7219( 0x03, SEGMENT_MAP[2] );
  output_max7219( 0x04, SEGMENT_MAP[3] );

  output_max7219( 0x05, SEGMENT_MAP[4] );
  output_max7219( 0x06, SEGMENT_MAP[5] );
  output_max7219( 0x07, SEGMENT_MAP[6] );
  output_max7219( 0x08, SEGMENT_MAP[7] );
}

int count;

byte digits[] = {1,2,3,4,5,6,7,8,9,0};

/* Main program */
void loop()
{
  byte digit = (count / 10) % 10;
  byte max7219_register = 0x01; // Digit address (RAM "register")
  byte digit_value = SEGMENT_MAP[digit]; // Segment layout for the digit to display
  uint16_t payload = ((uint16_t)max7219_register << 8) | digit_value;

  if( digit == 0 && count % 10 == 0 ) {
    byte first_digit = digits[0];
    for( byte i = 0; i < 9; i++ ) {
      digits[i] = digits[i+1]; 
    }
    digits[9] = first_digit;
    for( byte i = 0; i < 8; i++ ) {
        output_max7219( i+1, SEGMENT_MAP[digits[i]] ); 
    }
  }

  if( 0 ) {
    output_max7219_16( payload );
  } else {
    output_max7219( max7219_register, digit_value );
  }
  
  count ++;

  delay( 10 );
}
 
