
int outputPinNo = 13;

void setup()
{
  pinMode( outputPinNo, OUTPUT );
}

void loop()
{
  digitalWrite( outputPinNo, HIGH );
  delay( 3000 ); // delay for 3 s
  digitalWrite( outputPinNo, LOW );
  delay( 500 );
  digitalWrite( outputPinNo, HIGH );
  delay( 3000 ); // delay for 3 s
  digitalWrite( outputPinNo, LOW );
  delay( 500 );
  digitalWrite( outputPinNo, HIGH );
  delay( 3000 ); // delay for 3 s
  digitalWrite( outputPinNo, LOW );
  delay( 6000 );
}
