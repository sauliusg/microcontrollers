/* Define shift register pins used for seven segment display */
#define LATCH_DIO 4
#define CLK_DIO 7
#define DATA_DIO 8

#define BUTTON1 A1
#define BUTTON2 A2
#define BUTTON3 A3

const byte LED[] = {13,12,11,10};

#define BUZZER 3

#define ON             LOW
#define OFF            HIGH

byte current_buzzer = OFF;

/* Segment byte maps for numbers 0 to 9 */
const byte SEGMENT_MAP[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0X80,0X90};
/* Byte maps to select digit 1 to 4 */
const byte SEGMENT_SELECT[] = {0xF1,0xF2,0xF4,0xF8};
 
void setup ()
{
  /* Set DIO pins */
  pinMode(LATCH_DIO,OUTPUT);
  pinMode(CLK_DIO,OUTPUT);
  pinMode(DATA_DIO,OUTPUT);

  pinMode(BUTTON1,INPUT);
  pinMode(BUTTON2,INPUT);  
  pinMode(BUTTON3,INPUT);

  pinMode(LED[0], OUTPUT);
  pinMode(LED[1], OUTPUT);
  pinMode(LED[2], OUTPUT);
  pinMode(LED[3], OUTPUT);

  pinMode(BUZZER,OUTPUT);
  digitalWrite( BUZZER, OFF );
}

byte write_numbers = 0;

#define MAX_COUNTER 400

int counter = 0;
byte digit = 0;
byte segmentMap = 1;

#define DEBOUNCING_LIMIT 150
#define PRESS_LIMIT (DEBOUNCING_LIMIT + 60000)

byte debouncing_counter;
unsigned int debouncing_counters[3];

/*
 * Determines whether a button is pressed and if pressed, for how long. 
 * Uses delay for debouncing. Determines if a button is pressed and held
 * (beyond the debouncing time).

 * Button ports must be properly initialised for input before calling 
 * this function.

 * Return value: 
 *   0 -- button not pressed;
 *   
 *   1 -- button pressed for the first time (either still within
 *        the DEBOUNCING_LIMIT, or wa not relesed after that)
 *        
 *   2 -- button is pressed and held (longer than PRESS_LIMIT)

*/
byte read_button_state( int button, unsigned int *dbcounter )
{
  byte b = digitalRead( button );
  byte bvalue = 0;
  if( b == 0 ) {
    // Button closed
    if( *dbcounter == 0 ) {
      // Button pressed for the first time, start debouncing:
      (*dbcounter) ++;
      bvalue = 1;
    } else
    if( *dbcounter <= DEBOUNCING_LIMIT ) {
      (*dbcounter) ++;
      bvalue = 1;
    } else
    if( *dbcounter <= PRESS_LIMIT ) {
      if( *dbcounter < PRESS_LIMIT )
        (*dbcounter) ++;
      bvalue = 2;
    }
  } else {
    if( *dbcounter > DEBOUNCING_LIMIT ) {
      *dbcounter = 0;
      bvalue = 0;
    } else
    if( *dbcounter > 0 ) {
      (*dbcounter) ++;
      bvalue = 1;
    }
  }

  return bvalue;
}

/* Main program */
void loop()
{
  /* Update the display with the current counter value */
  if( write_numbers ) {
    WriteNumberToSegment(0 , digit);
    WriteNumberToSegment(1 , digit);
    WriteNumberToSegment(2 , digit);
    WriteNumberToSegment(3 , digit);
  } else {
    WriteSegmentMap(0, segmentMap);
    WriteSegmentMap(1, segmentMap);
    WriteSegmentMap(2, segmentMap);
    WriteSegmentMap(3, segmentMap);
  }
  counter ++;
  if( counter > MAX_COUNTER ) {
    counter = 0;
    digit ++;
    if( digit > 9 )
      digit = 0;
    segmentMap <<= 1;
    if( segmentMap > 0x20 )
      segmentMap = 1;
  }
  byte b1 = read_button_state( BUTTON1, &debouncing_counters[0] );
  byte b2 = read_button_state( BUTTON2, &debouncing_counters[1] );
  if( b1 != 0 )
    write_numbers = 1;
  if( b2 != 0 )
    write_numbers = 0;

  if( b1 == 0 ) {
    digitalWrite( LED[0], OFF );
    digitalWrite( LED[1], OFF );
  } else
  if( b1 == 1 ) {
    digitalWrite( LED[0], ON );
  } else
  if( b1 == 2 ) {
    digitalWrite( LED[0], ON );
    digitalWrite( LED[1], ON );
  }
  
  if( b2 == 0 ) {
    digitalWrite( LED[2], OFF );
    digitalWrite( LED[3], OFF );
  } else
  if( b2 == 1 ) {
    digitalWrite( LED[2], ON );
  } else
  if( b2 == 2 ) {
    digitalWrite( LED[3], ON );
  }
  
  byte b3 = digitalRead( BUTTON3 );
  if( b3 == 0 ) {
    // Button 3 pressed:
    if( debouncing_counter == 0 ) {
      debouncing_counter = DEBOUNCING_LIMIT; 
      if( current_buzzer == ON ) {
        current_buzzer = OFF;
      } else {
        current_buzzer = ON;
      }
      digitalWrite( BUZZER, current_buzzer );
    }
  }
  if( debouncing_counter != 0 ) {
    debouncing_counter --;
  }
}

/* Write a decimal number between 0 and 9 to one of the 4 digits of the display */
void WriteNumberToSegment(byte Segment, byte Value)
{
  digitalWrite(LATCH_DIO,LOW);
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[Value]);
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Segment] );
  digitalWrite(LATCH_DIO,HIGH);
}

/* Write a segment map (ValueMap) to a specified digit (Position) */
void WriteSegmentMap(byte Position, byte ValueMap)
{
  digitalWrite(LATCH_DIO,LOW);
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, ~ValueMap);
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Position] );
  digitalWrite(LATCH_DIO,HIGH);
}
