#define ON             LOW
#define OFF            HIGH
 
void setup()
{
    // configure pins
    pinMode(A1, INPUT);
    pinMode(3,  OUTPUT);
    // default: sound Off
    digitalWrite(3, OFF);
}
 
void loop()
{
    // whait KEY1 press
    if( digitalRead(A1)==ON )
    {
        // sound ON
        digitalWrite(3, ON);
    }
    else
    {
        // sound OFF
        digitalWrite(3, OFF);
    }
}
