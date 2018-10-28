// import the library 
#include <Servo.h>
// create an instance of the servo library
Servo myServo;

void setup(){
  // attach the servo to pin 9
  myServo.attach(9);

  // start serial communication for debugging
  // Serial.begin(9600);

  // move the servo to the unlocked position
  myServo.write(90);
}

void loop()
{
//  // move the servo to the locked position
//  myServo.write(90);
//
//  // wait for the servo to move into position
//  delay (1000);
//
//  // move the servo to the unlocked position
//  myServo.write(0);
//
//  // wait for it to move
//  delay(2000);
//
//  myServo.write(180);
//
//  // wait for it to move
//  delay(2000);
//
//  // move the servo to the unlocked position
//  myServo.write(0);
//
//  // wait for it to move
  delay(2000);
}

