#include <dht.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

dht DHT11_1;
dht DHT11_2;
dht DHT22;

#define DHT11_1_PIN 6
#define DHT11_2_PIN 7
#define DHT22_PIN 8

int step = 0;
int ledPinNo = 13;

void setup()
{
  pinMode( ledPinNo, OUTPUT );
  lcd.begin(16, 2);
  Serial.begin(9600);
}

int chk_dht11;
int chk_dht22;

void loop()
{
  chk_dht11 = step == 0 ? DHT11_1.read11(DHT11_1_PIN) : DHT11_2.read11(DHT11_2_PIN);
  chk_dht22 = DHT22.read(DHT22_PIN);

  lcd.setCursor(0,0); 
  lcd.print("11(");
  lcd.print(step+1);
  lcd.print("): ");

  Serial.print("DHT11(");
  Serial.print(step+1);
  Serial.print("): ");

  if( chk_dht11 == DHTLIB_OK ) {
    double temperature = step == 0 ? DHT11_1.temperature : DHT11_2.temperature;
    double humidity = step == 0 ? DHT11_1.humidity : DHT11_2.humidity;
    lcd.print(temperature, 0);
    lcd.print((char)223);
    lcd.print("C ");
    lcd.print(humidity, 0);
    lcd.print("% ");

    Serial.print("T = ");
    Serial.print(temperature);
    Serial.print(" RH = ");
    Serial.print(humidity);
    Serial.print(" ");
  } else {
    lcd.print("T=?? ");
    lcd.print("RH=?");    
    Serial.print("T = ?? ");
    Serial.print("RH = ??");    
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

  Serial.print("DTH22: T = ");
  if( chk_dht22 == DHTLIB_OK ) {
    Serial.print(DHT22.temperature);
  } else {
    Serial.print( "??" );
  }
  Serial.print(" RH = ");
  if( chk_dht22 == DHTLIB_OK ) {
    Serial.print(DHT22.humidity);
  } else {
    Serial.print( "??" );
  }  
  Serial.println("");

  if( step == 0 ) {
    digitalWrite( ledPinNo, HIGH );
    step = 1;
  } else {
    digitalWrite( ledPinNo, LOW );
    step = 0;
  }

  delay(2000);
}
