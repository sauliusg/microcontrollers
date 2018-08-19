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
#include <dht.h>

#ifndef _BV
  #define _BV(bit) (1<<(bit))
#endif


//Adafruit_LEDBackpack matrix = Adafruit_LEDBackpack();
Adafruit_7segment matrix = Adafruit_7segment();

#define DHT22_PIN 7

dht DHT22;

void setup() {
  Serial.begin(9600);
  Serial.println("DHT22 humidity sensor");
  
  matrix.begin(0x70);  // pass in the address
}

unsigned int step = 0;                                                                                                                                               

void loop() {

  int chk_dht22 = DHT22.read(DHT22_PIN);

  Serial.print("DHT22(");
  Serial.print(step+1);
  Serial.print("): ");

  if( chk_dht22 == DHTLIB_OK ) {
    double temperature = DHT22.temperature;
    double humidity = DHT22.humidity;
    if( step & 0x0002 ) {
      matrix.print(humidity,1);
    } else {
      matrix.print(temperature,1);
    }

    Serial.print("T = ");
    Serial.print(temperature);
    Serial.print(" RH = ");
    Serial.print(humidity);
    Serial.print(" ");
  } else {
    matrix.print(0xEEEE, HEX);
    Serial.print("T = ?? ");
    Serial.print("RH = ??");
  }
  matrix.writeDisplay();
  Serial.println("");

  step ++;  
  delay(2000);
}

