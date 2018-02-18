#include <RFID.h>

/*
* Read a card using a mfrc522 reader on your SPI interface
* Pin layout should be as follows (on Arduino Uno):
* MOSI: Pin 11 / ICSP-4
* MISO: Pin 12 / ICSP-1
* SCK: Pin 13 / ISCP-3
* SS/SDA: Pin 10
* RST: Pin 9
*/

#include <SPI.h>
#include <RFID.h>

#define SS_PIN 10
#define RST_PIN 9

RFID rfid(SS_PIN,RST_PIN);


int led = 7;
int power = 8; 
int serNum[5];
int cards[][5] = {
  {144, 66, 100, 77, 251}  
};

bool access = false;

void setup(){

    Serial.begin(9600);
    SPI.begin();
    rfid.init();

    pinMode(led, OUTPUT);

    digitalWrite(led, LOW);
   
}

void loop(){
    
    if(rfid.isCard()){
        if(rfid.readCardSerial()){
            Serial.print(rfid.serNum[0]);
            Serial.print(" ");
            Serial.print(rfid.serNum[1]);
            Serial.print(" ");
            Serial.print(rfid.serNum[2]);
            Serial.print(" ");
            Serial.print(rfid.serNum[3]);
            Serial.print(" ");
            Serial.print(rfid.serNum[4]);
            Serial.println("");
        }
        Serial.println("Trying to authenticate block 4 with default KEYA value");
        uint8_t keya[6] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
	  
        // Start with block 4 (the first block of sector 1) since sector 0
        // contains the manufacturer data and it's probably better just
        // to leave it alone unless you know what you're doing
        //success = nfc.mifareclassic_AuthenticateBlock(uid, uidLength, 4, 0, keya);
        int success;
        unsigned char authMode = 0x60;
        int blockNr = 8;
        success = rfid.auth(/*authMode =*/authMode, /*BlockAddr =*/blockNr,
                            /*Sectorkey =*/keya, /*serNum =*/rfid.serNum);

        if( success == MI_OK ) {
            Serial.print( "Authenticated with authMode = " );
            Serial.println( authMode );
        } else {
            Serial.print( "Card authentication failed: code = " );
            Serial.println( success );
        }

        for( int i = blockNr; i < blockNr + 4; i ++ ) {
            unsigned char buffer[MAX_LEN*16];
            int errcode;
            memset( buffer, 0, sizeof(buffer));
            if( (errcode = rfid.read( i, buffer )) == MI_OK ) {
                Serial.println( "Read OK" );
            } else {
                Serial.print( "Read faled? Code = " );
                Serial.println( errcode );
            }

            for( int j = 0; j < MAX_LEN; j++ ) {
                char number[4];
                snprintf( number, sizeof(number), "%02X ", buffer[j] );
                Serial.print( number );
            }
            for( int j = 0; j < MAX_LEN; j++ ) {
                char characters[4];
                snprintf( characters, sizeof(characters), "%c ", buffer[j] );
                Serial.print( characters );
            }
            Serial.println();
        }
        Serial.println( ">>>>" );
    }
    
    rfid.halt();

}


