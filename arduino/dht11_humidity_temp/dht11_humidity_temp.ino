#include <dht.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

dht DHT;

#define DHT11_PIN 7

int step = 0;
int ledPinNo = 13;

void setup()
{
  pinMode( ledPinNo, OUTPUT );
  lcd.begin(16, 2);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  if( step == 0 ) {
    digitalWrite( ledPinNo, HIGH );
    step = 1;
  } else {
    digitalWrite( ledPinNo, LOW );
    step = 0;
  }
  delay(1000);
}
