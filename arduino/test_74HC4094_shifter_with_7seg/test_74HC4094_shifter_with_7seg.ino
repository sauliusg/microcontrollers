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

int digits[][8] = {
//  DP,F,A,B, C,G,D,E -- 7-seg segments
//   7,6,5,4, 3,2,1,0 -- 74HC4094 QP pins
//   | | | |  | | | |
    {0,1,1,1, 1,0,1,1}, // 0
    {0,0,0,1, 1,0,0,0}, // 1
    {0,0,1,1, 0,1,1,1}, // 2
    {0,0,1,1, 1,1,1,0}, // 3
    {0,1,0,1, 1,1,0,0}, // 4
    {0,1,1,0, 1,1,1,0}, // 5
    {0,1,1,0, 1,1,1,1}, // 6
    {0,0,1,1, 1,0,0,0}, // 7
    {0,1,1,1, 1,1,1,1}, // 8
    {0,1,1,1, 1,1,1,0}, // 9
    {0,1,1,1, 1,1,0,1}, // A
    {0,1,0,0, 1,1,1,1}, // b
    {0,1,1,0, 0,0,1,1}, // C
    {0,0,0,1, 1,1,1,1}, // d
    {0,1,1,0, 0,1,1,1}, // E
    {0,1,1,0, 0,1,0,1}, // F
    {0,0,0,0, 0,0,0,0}, // blank
    {1,1,1,1, 1,1,1,1}, // all on
};


unsigned int count = 0;

void loop()
{
  int *pattern;
  
  digitalWrite( STR, LOW );
  digitalWrite( OE, HIGH );
  for( int i = 0; i < sizeof(digits[0])/sizeof(digits[0][0]); i ++ ) {
    pattern = digits[count % 16];
    // Output a pattern bit into the shifter:
    if( i == 0 ) {
        // Decide whether to enable DP (Decimal Point):
        digitalWrite( D, count % 3 == 0 ? HIGH : LOW );
    } else {
        digitalWrite( D, pattern[i] ? HIGH : LOW );
    }
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

