#include <Wire.h> // Enable this line if using Arduino Uno, Mega, etc.
//#include <TinyWireM.h> // Enable this line if using Adafruit Trinket, Gemma, etc.

#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_7segment matrix = Adafruit_7segment();

void setup() {
#ifndef __AVR_ATtiny85__
  Serial.begin(9600);
  Serial.println("7 Segment Backpack Test");
#endif
  matrix.begin(0x70);
}

void loop() {

  matrix.writeDigitNum(0, 8, true);
  matrix.writeDigitNum(1, 8, true);
  matrix.drawColon(true);
  matrix.writeDigitNum(3, 8, true);
  matrix.writeDigitNum(4, 8, true);
  matrix.writeDisplay();
  delay(500);
  matrix.clear();
  matrix.writeDisplay();
  delay(500);
 
}

