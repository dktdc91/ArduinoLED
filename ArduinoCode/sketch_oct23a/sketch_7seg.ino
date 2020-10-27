#define REDPin    13
#define YELLOWPin    12
#define GREENPin    11
#define RED       0b000001
#define YELLOW   0b000010
#define GREEN     0b000100
#include "SevSeg.h"
SevSeg sevseg; 

const int BaudRate = 9600;
char incomingOption;
int option;
int range;

void setup() {
  pinMode(REDPin, OUTPUT);
  pinMode(GREENPin, OUTPUT);
  pinMode(YELLOWPin, OUTPUT);

  //Serial.begin(BaudRate);

    byte numDigits = 1;
    byte digitPins[] = {};
    byte segmentPins[] = {6, 5, 2, 3, 4, 7, 8, 9};
    bool resistorsOnSegments = true;

    byte hardwareConfig = COMMON_ANODE; 
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(200);
}

void loop() {
  incomingOption = Serial.read();
  option = incomingOption - '0';
  if(option >= 0 && option <= 7){
    range = option;
 
    if((range & RED) == RED){
      digitalWrite(REDPin, HIGH);
    }else{
      digitalWrite(REDPin, LOW);
    }
  
    if((range & GREEN) == GREEN){
      digitalWrite(GREENPin, HIGH);
    }else{
      digitalWrite(GREENPin, LOW);
    }
  
    if((range & YELLOW) == YELLOW){
      digitalWrite(YELLOWPin, HIGH);
    }else{
      digitalWrite(YELLOWPin, LOW);
    }
    
  }else{
    //Serial.write(incomingOption);
  }

  sevseg.setNumber(range);
  sevseg.refreshDisplay();  
  
}
