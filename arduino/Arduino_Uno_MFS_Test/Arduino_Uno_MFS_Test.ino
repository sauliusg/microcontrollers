/* Define shift register pins used for seven segment display */
#define LATCH_DIO 4
#define CLK_DIO 7
#define DATA_DIO 8

#define BUTTON1 A1
#define BUTTON2 A2
#define BUTTON3 A3

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
  /* Set DIO pins to outputs */
  pinMode(LATCH_DIO,OUTPUT);
  pinMode(CLK_DIO,OUTPUT);
  pinMode(DATA_DIO,OUTPUT);
  pinMode(BUTTON1,INPUT);
  pinMode(BUTTON2,INPUT);  
  pinMode(BUTTON3,INPUT);  
  pinMode(BUZZER,OUTPUT);
  digitalWrite( BUZZER, OFF );
}

byte write_numbers = 0;

#define MAX_COUNTER 400

int counter = 0;
byte digit = 0;
byte segmentMap = 1;

#define DEBOUNCING_LIMIT 200

byte debouncing_counter;

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
  byte b1 = digitalRead( BUTTON1 );
  byte b2 = digitalRead( BUTTON2 );
  if( b1 == 0 )
    write_numbers = 1;
  if( b2 == 0 )
    write_numbers = 0;
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
