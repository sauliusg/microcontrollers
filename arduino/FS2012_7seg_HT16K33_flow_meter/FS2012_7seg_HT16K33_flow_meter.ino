/*************************************************** 
  This is a library for our I2C LED Backpacks

  Designed specifically to work with the Adafruit LED Matrix backpacks 
  ----> http://www.adafruit.com/products/872
  ----> http://www.adafruit.com/products/871
  ----> http://www.adafruit.com/products/870

  These displays use I2C to communicate, 2 pins are required to 
  interface. There are multiple selectable I2C addresses. For backpacks
  with 2 Address Select pins: 0x70, 0x71, 0x72 or 0x73. For backpacks
  with 3 Address Select pins: 0x70 thru 0x77

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

#ifndef _BV
  #define _BV(bit) (1<<(bit))
#endif


//Adafruit_LEDBackpack matrix = Adafruit_LEDBackpack();
Adafruit_7segment matrix = Adafruit_7segment();

const uint8_t FS2012_I2C_addr = 0x07; // Specified in the FS2012 datasheet, p. 6
                                      // https://www.idt.com/document/dst/fs2012-datasheet

void setup() {
  Serial.begin(9600);
  Serial.println("FS2012 Flow Meter test");
  
  matrix.begin(0x70);  // pass in the address
  Wire.begin();
}

unsigned int step = 0;

// Scaling factor to convert integer from the FS2012 sensor to a floating point 
// number in L/min. For FS2012-{1020,1100}-NG the scale divisor is 1000 (for
// the ...-LQ units tha factor would be 10):

double scale = 1000.0;

void loop() {

  Serial.print("FS2012 ");
  Serial.print(step+1);
  Serial.print(": ");

  int ok = 1;
  if( ok ) {
    double flow;

    Wire.beginTransmission( FS2012_I2C_addr );
    // Following example at
    // https://www.electroschematics.com/9798/reading-temperatures-i2c-arduino/ (S.G.):
    // request two bytes from the flow meter:
    Wire.requestFrom( FS2012_I2C_addr, (uint8_t)2 );
    // wait for response:
    while(Wire.available() == 0);
    unsigned int msb = Wire.read();
    unsigned int lsb = Wire.read();
    Serial.print( "msb = 0x" ); Serial.print( msb, HEX ); Serial.print( ", " );
    Serial.print( "lsb = 0x" ); Serial.print( lsb, HEX ); Serial.print( ", " );
    Wire.endTransmission();
    // Another example available at
    // https://www.arduino.cc/en/Reference/WireRead (S.G.).

    unsigned int iflow = (msb << 8) | lsb;
    flow = iflow/scale;

    matrix.print(flow, 3);

    Serial.print("iflow = ");
    Serial.print(iflow);
    Serial.print(" ");
    Serial.print("Flow = ");
    Serial.print(flow, 3);
  } else {
    matrix.print(0xEEEE, HEX);
    Serial.print("Flow = ?? ");
  }
  matrix.writeDisplay();
  Serial.println("");

  step ++;  
  delay(2000);
}

