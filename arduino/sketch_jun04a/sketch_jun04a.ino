
int outputPinNo = 13;

void setup()
{
  pinMode( outputPinNo, OUTPUT );
}

void loop()
{
  digitalWrite( outputPinNo, HIGH );
  delay( 1000 ); // delay for 1 s
  digitalWrite( outputPinNo, LOW );
  delay( 250 );

}
