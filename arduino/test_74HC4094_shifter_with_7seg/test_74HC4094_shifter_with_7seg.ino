// 74HC4094 shift register pin number assignments:
int STR = 2;  // Strobe: latch shifted values into a parallel output
int D   = 3;  // Serial data in
int CP  = 4;  // Serial data clock
int OE  = 13; // Output Enable

void setup()
{
  pinMode( STR, OUTPUT );
  pinMode( D, OUTPUT );
  pinMode( CP, OUTPUT );
  pinMode( OE, OUTPUT );

  // Set data trasnfer all pins to low:
  digitalWrite( STR, LOW );
  digitalWrite( D, LOW );
  digitalWrite( CP, LOW );
  digitalWrite( OE, LOW );
  
  Serial.begin(9600);     // Initialize serial communications with the PC

}

unsigned int count = 0;

void loop()
{
  //              DP,F,A,B, C,G,D,E
  int pattern[] = {0,1,1,0, 0,1,1,1};
  //int pattern[] = {1,1,1,1, 0,0,0,0};
  
  digitalWrite( STR, LOW );
  digitalWrite( OE, HIGH );
  for( int i = 0; i < sizeof(pattern)/sizeof(pattern[0]); i ++ ) {
    // Output a pattern bit into the shifter:
    digitalWrite( D, (pattern[i] == (count % 2)) ? LOW : HIGH );
    Serial.print( count );
    Serial.print( " " );
    Serial.println( count % 2 );
    // Clock the shift:
    digitalWrite( CP, HIGH );
    delay(1);
    digitalWrite( CP, LOW );
  }
  digitalWrite( OE, LOW );
  digitalWrite( STR, HIGH );

  count ++;

  delay( 1200 );
}

