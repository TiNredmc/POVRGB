int latchPin = 10; //Pin connected to LE of STP08DP05 
int clockPin = 13; //Pin connected to CLK of STP08DP05 
int dataPin = 11; //Pin connected to SDI of STP08DP05 
int OEPin = 9; //Pin connected to OEbar of STP08DP05 
void setup() { //set pins to output because they are addressed in the main loop 
pinMode(latchPin, OUTPUT); 
pinMode(clockPin, OUTPUT); 
pinMode(dataPin, OUTPUT); 
pinMode(OEPin, OUTPUT);} 
void loop() { //count up routine 
for (int j = 0; j < 16777216; j++) { 
//ground latchPin and hold low for as long as you are transmitting, OE pin is high… 
digitalWrite(latchPin, LOW); digitalWrite(OEPin, HIGH); 
shiftOut(dataPin, clockPin, LSBFIRST, j); 
//return the latch pin high to signal chip that it 
//no longer needs to listen for information 
digitalWrite(latchPin, HIGH); digitalWrite(OEPin, LOW);
      delay(10);
       
         }
    }
