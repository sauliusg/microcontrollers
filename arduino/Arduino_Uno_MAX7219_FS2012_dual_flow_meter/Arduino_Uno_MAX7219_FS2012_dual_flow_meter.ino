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

unsigned int read_word_i2c_multiplexed(
  byte channels, 
  byte i2c_multiplexer_address,
  byte i2c_device_address )
{
  byte msb, lsb;

  // Select the first FS2012 flow meter:
  Wire.beginTransmission( i2c_multiplexer_address );
  Wire.write( channels );
  Wire.endTransmission();

  // Read the sensor:
  Wire.beginTransmission( i2c_device_address );
  // Following example at
  // https://www.electroschematics.com/9798/reading-temperatures-i2c-arduino/ (S.G.):
  // request two bytes from the flow meter:
  Wire.requestFrom( i2c_device_address, (uint8_t)2 );
  // wait for response:
  while(Wire.available() == 0);
  msb = Wire.read();
  lsb = Wire.read();
  Wire.endTransmission();

  return (msb << 8) | lsb;
}

/* Segment byte maps for numbers 0 to 9, "1" bit means segment is ON: */
//                           "0"  "1"  "2"  "3"  "4"  "5"  "6"  "7"  "8"  "9"
const byte SEGMENT_MAP[] = {0x7E,0x30,0x6D,0x79,0x33,0x5B,0x5F,0x70,0x7F,0x7B};

#define DECIMAL_POINT 0x80

void set_digit_7seg_codes( unsigned int value,
                           byte scale, // position of the decimal point
                           byte digits[],
                           byte digits_length,
                           byte offset )
{
  for( byte i = 0; i < 4; i++ ) {
    if( i + offset >= digits_length ) break;
    byte digit = value % 10;
    value /= 10;
    digits[i + offset] = SEGMENT_MAP[digit] | (i == scale ? DECIMAL_POINT : 0);
  }
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

  unsigned int iflow1 = read_word_i2c_multiplexed(
    flow_sensor_1_channel,
    i2c_multiplexer_addr,
    FS2012_I2C_addr
  );
  double flow1 = iflow1/scale;

  set_digit_7seg_codes( iflow1, /*scale =*/3, 
                        digits, sizeof(digits),
                        /*offset =*/ 0 );

  unsigned int iflow2 = read_word_i2c_multiplexed(
    flow_sensor_2_channel,
    i2c_multiplexer_addr,
    FS2012_I2C_addr
  );
  double flow2 = iflow2/scale;

  set_digit_7seg_codes( iflow2, /*scale =*/3, 
                        digits, sizeof(digits),
                        /*offset =*/ 4 );

  Serial.print("iflow1: ");
  Serial.print(iflow1);
  Serial.print(" ");
  Serial.print("flow1: ");
  Serial.print(flow1, 3);

  Serial.print(" ");

  Serial.print("iflow2: ");
  Serial.print(iflow2);
  Serial.print(" ");
  Serial.print("flow2: ");
  Serial.print(flow2, 3);

  Serial.println("");

  // Send the digits to the indicator:
  for( byte i = 0; i < 8; i++ ) {
    output_max7219( i+1, digits[i] ); 
  }

  delay( 500 );
}
 
