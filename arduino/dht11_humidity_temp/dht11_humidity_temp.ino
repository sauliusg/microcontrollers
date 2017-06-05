#include <dht.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

dht DHT11;
dht DHT22;

#define DHT11_PIN 7
#define DHT22_PIN 8

int step = 0;
int ledPinNo = 13;

void setup()
{
  pinMode( ledPinNo, OUTPUT );
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop()
{
  int chk_dht11 = DHT11.read11(DHT11_PIN);
  int chk_dht22 = DHT22.read(DHT22_PIN);

  lcd.setCursor(0,0); 
  lcd.print("DHT11: ");
  if( chk_dht11 == DHTLIB_OK ) {
    lcd.print(DHT11.temperature, 0);
    lcd.print((char)223);
    lcd.print("C ");
    lcd.print(DHT11.humidity, 0);
    lcd.print("% ");
  } else {
    lcd.print("T=?? ");
    lcd.print("RH=?");    
  }

  lcd.setCursor(0,1);
  lcd.print("DHT22: ");
  if( chk_dht22 == DHTLIB_OK ) {
    lcd.print(DHT22.temperature, 0);
    lcd.print((char)223);
    lcd.print("C ");
    lcd.print(DHT22.humidity, 0);
    lcd.print("% ");
  } else {
    lcd.print("T=?? ");
    lcd.print("RH=?");    
  }

  Serial.print("DTH11: T = ");
  Serial.print(DHT11.temperature);
  Serial.print(" RH = ");
  Serial.print(DHT11.humidity);
  Serial.print(" ");

  Serial.print("DTH22: T = ");
  Serial.print(DHT22.temperature);
  Serial.print(" RH = ");
  Serial.print(DHT22.humidity);
  Serial.println("");

  if( step == 0 ) {
    digitalWrite( ledPinNo, HIGH );
    step = 1;
  } else {
    digitalWrite( ledPinNo, LOW );
    step = 0;
  }

  delay(1000);
}
