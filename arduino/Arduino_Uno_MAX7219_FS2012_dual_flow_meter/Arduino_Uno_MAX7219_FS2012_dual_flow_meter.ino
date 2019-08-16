#include <SPI.h>
#include <Wire.h>

/* Chip (Slave) select pin for MAX7219 7-seg driver: */
#define CS 10

/* TCA9548A I2C multiplexer address: */
const uint8_t i2c_multiplexer_addr = 0x77;

/* I2C address of *both* flow sensors; sensors will be addressed 
 * via the TCA9548A I2C multiplexer in channels 2 and 7.
 */
const uint8_t FS2012_I2C_addr = 0x07; // Specified in the FS2012 datasheet, p. 6
                                      // https://www.idt.com/document/dst/fs2012-datasheet

const byte flow_sensor_1_channel = 0x04; // 0000_0100 - channel No. 2 (0-based)
const byte flow_sensor_2_channel = 0x80; // 1000_0000 - channel No. 7 (0-based)

/* Segment byte maps for numbers 0 to 9, "1" bit means segment is ON: */
//                           "0"  "1"  "2"  "3"  "4"  "5"  "6"  "7"  "8"  "9"
const byte SEGMENT_MAP[] = {0x7E,0x30,0x6D,0x79,0x33,0x5B,0x5F,0x70,0x7F,0x7B};

#define DECIMAL_POINT 0x80

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
  Wire.begin();
  Serial.begin(9600);

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

// Scaling factor to convert integer from the FS2012 sensor to a
// floating point number in L/min. For FS2012-{1020,1100}-NG the scale
// divisor is 1000 (for the ...-LQ sensors the factor would be 10),
// see https://www.idt.com/document/dst/fs2012-datasheet
// (S.G.):

double scale = 1000.0;

/* Main program */
void loop()
{
  unsigned int msb, lsb;
  byte digits[8];

  {
    // Select the first FS2012 flow meter:
    Wire.beginTransmission( i2c_multiplexer_addr );
    Wire.write( flow_sensor_1_channel );
    Wire.endTransmission();
    Serial.print( "FS2012 sensor 1 selected;" );
  
    // Read the sensor:
    Wire.beginTransmission( FS2012_I2C_addr );
    // Following example at
    // https://www.electroschematics.com/9798/reading-temperatures-i2c-arduino/ (S.G.):
    // request two bytes from the flow meter:
    Wire.requestFrom( FS2012_I2C_addr, (uint8_t)2 );
    // wait for response:
    while(Wire.available() == 0);
    msb = Wire.read();
    lsb = Wire.read();
    Serial.print( "msb = 0x" ); Serial.print( msb, HEX ); Serial.print( ", " );
    Serial.print( "lsb = 0x" ); Serial.print( lsb, HEX ); Serial.print( ", " );
    Wire.endTransmission();
  
    unsigned int iflow1 = (msb << 8) | lsb;
    double flow1 = iflow1/scale;

    // Convert to indicator digits:
    unsigned int quotient = iflow1;
    for( int i = 0; i < 4; i++ ) {
      byte digit = quotient % 10;
      quotient /= 10;
      digits[i] = SEGMENT_MAP[digit] | (i == 3 ? DECIMAL_POINT : 0);
    }

    Serial.print("iflow1 = ");
    Serial.print(iflow1);
    Serial.print(" ");
    Serial.print("Flow1 = ");
    Serial.print(flow1, 3);

    Serial.println("");
  }

  {
    // Select the second FS2012 flow meter:
    Wire.beginTransmission( i2c_multiplexer_addr );
    Wire.write( flow_sensor_2_channel );
    Wire.endTransmission();
    Serial.print( "FS2012 sensor 2 selected;" );
  
    // Read the sensor:
    Wire.beginTransmission( FS2012_I2C_addr );
    // Following example at
    // https://www.electroschematics.com/9798/reading-temperatures-i2c-arduino/ (S.G.):
    // request two bytes from the flow meter:
    Wire.requestFrom( FS2012_I2C_addr, (uint8_t)2 );
    // wait for response:
    while(Wire.available() == 0);
    msb = Wire.read();
    lsb = Wire.read();
    Serial.print( "msb = 0x" ); Serial.print( msb, HEX ); Serial.print( ", " );
    Serial.print( "lsb = 0x" ); Serial.print( lsb, HEX ); Serial.print( ", " );
    Wire.endTransmission();
    
    unsigned int iflow2 = (msb << 8) | lsb;
    double flow2 = iflow2/scale;
  
    // Convert to indicator digits:
    unsigned int quotient = iflow2;
    for( int i = 0; i < 4; i++ ) {
      byte digit = quotient % 10;
      quotient /= 10;
      digits[i+4] = SEGMENT_MAP[digit] | (i == 3 ? DECIMAL_POINT : 0);
    }

    Serial.print("iflow2 = ");
    Serial.print(iflow2);
    Serial.print(" ");
    Serial.print("Flow2 = ");
    Serial.print(flow2, 3);

    Serial.println("");
  }

  // Send the digits to the indicator:
  for( byte i = 0; i < 8; i++ ) {
    output_max7219( i+1, digits[i] ); 
  }

  delay( 500 );
}
 
