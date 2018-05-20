#define A_BUTTON      0
#define B_BUTTON      1
#define SELECT_BUTTON 2
#define START_BUTTON  3
#define UP_BUTTON     4
#define DOWN_BUTTON   5
#define LEFT_BUTTON   6
#define RIGHT_BUTTON  7

byte nesRegister = 0;     // State of Controller

int nesClock      = 2;    // The clock pin for the NES controller
int nesLatch      = 3;    // The latch pin for the NES controller
int nesData       = 4;    // The data pin for the NES controller

void setup() {
  Serial.begin(9600);
  
  pinMode(nesData, INPUT);
  
  pinMode(nesClock, OUTPUT);
  pinMode(nesLatch, OUTPUT);
  
  digitalWrite(nesClock, LOW);
  digitalWrite(nesLatch, LOW);
}

void loop() {
  nesRegister = readNesController();
  
  delay(200);
  
  String s = "";
  
  if (bitRead(nesRegister, A_BUTTON) == 0) {
    s += "A";
  } else {
    s += "a";
  }
    
  if (bitRead(nesRegister, B_BUTTON) == 0) {
    s += "B";
  } else {
    s += "b";
  }
    
  if (bitRead(nesRegister, START_BUTTON) == 0) {
    s += "S";
  } else {
    s += "s";
  }
  
  if (bitRead(nesRegister, SELECT_BUTTON) == 0) {
    s += "S";
  } else {
    s += "s";
  }
    
  if (bitRead(nesRegister, UP_BUTTON) == 0) {
    s += "^";
  } else {
    s += "_";
  }
    
  if (bitRead(nesRegister, DOWN_BUTTON) == 0) {
    s += "v";
  } else {
    s += "_";
  }
  
  if (bitRead(nesRegister, LEFT_BUTTON) == 0) {
    s += "<";
  } else {
    s += "_";  
  }
  
  if (bitRead(nesRegister, RIGHT_BUTTON) == 0) {
    s += ">";
  } else {
    s += "_";
  }
  Serial.println(s);
}

byte readNesController() 
{
  int tempData = 255;
    
  digitalWrite(nesLatch, HIGH);
  digitalWrite(nesLatch, LOW);

  // A button
  if (digitalRead(nesData) == LOW)
    bitClear(tempData, A_BUTTON);

  // B button
  digitalWrite(nesClock, HIGH);
  digitalWrite(nesClock, LOW);
  if (digitalRead(nesData) == LOW)
    bitClear(tempData, B_BUTTON);

  // SELECT Button
  digitalWrite(nesClock, HIGH);
  digitalWrite(nesClock, LOW);
  if (digitalRead(nesData) == LOW)
    bitClear(tempData, SELECT_BUTTON);

  // START Button
  digitalWrite(nesClock, HIGH);
  digitalWrite(nesClock, LOW);
  if (digitalRead(nesData) == LOW)
    bitClear(tempData, START_BUTTON);

  // UP Button
  digitalWrite(nesClock, HIGH);
  digitalWrite(nesClock, LOW);
  if (digitalRead(nesData) == LOW)
    bitClear(tempData, UP_BUTTON);

  // DOWN Button
  digitalWrite(nesClock, HIGH);
  digitalWrite(nesClock, LOW);
  if (digitalRead(nesData) == LOW)
    bitClear(tempData, DOWN_BUTTON);

  // LEFT Button
  digitalWrite(nesClock, HIGH);
  digitalWrite(nesClock, LOW);
  if (digitalRead(nesData) == LOW)
    bitClear(tempData, LEFT_BUTTON);  

  // RIGHT Button
  digitalWrite(nesClock, HIGH);
  digitalWrite(nesClock, LOW);
  if (digitalRead(nesData) == LOW)
    bitClear(tempData, RIGHT_BUTTON);
    
  return tempData;
}
