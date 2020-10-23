#define BaudRate 9600
#define REDPin    10
#define GREENPin  8
#define ARDPin    13
#define RED       0b000001
#define GREEN     0b000010
#define ARD_LED   0b000100
char incomingOption;
int option;
int range;

void setup() {
  pinMode(REDPin, OUTPUT);
  pinMode(GREENPin, OUTPUT);
  pinMode(ARDPin, OUTPUT);

  Serial.begin(BaudRate);
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
  
    if((range & ARD_LED) == ARD_LED){
      digitalWrite(ARDPin, HIGH);
    }else{
      digitalWrite(ARDPin, LOW);
    }
  }
  
}
