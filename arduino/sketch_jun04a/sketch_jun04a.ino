
int outputPinNo = 13;

void setup()
{
  pinMode( outputPinNo, OUTPUT );
}

void loop()
{
  digitalWrite( outputPinNo, HIGH );
  delay( 300 ); // delay for 3 s
  digitalWrite( outputPinNo, LOW );
  delay( 100 );
  digitalWrite( outputPinNo, HIGH );
  delay( 300 ); // delay for 3 s
  digitalWrite( outputPinNo, LOW );
  delay( 100 );
  digitalWrite( outputPinNo, HIGH );
  delay( 300 ); // delay for 3 s
  digitalWrite( outputPinNo, LOW );
  delay( 600 );
}
