#include <Servo.h>
#include <ArduinoJson.h>

Servo myservo;

int pos=0;
int Index;

// init X axis variables
int xStep = 11;
int xDirection = 2;
int xEnable = 3;

// init Y axis variables
int yStep = 4;
int yDirection = 5;
int yEnable = 6;

// init Z axis variables
int zStep = 8;
int zDirection = 9;
int zEnable = 10;

// init claw pin
int clawPin = 7;

bool isOnStartPoint = false;

void setup(){
  Serial.begin(9600);
  
  myservo.attach(clawPin);

  // init X Pins
  pinMode(xStep, OUTPUT);
  pinMode(xDirection, OUTPUT);
  pinMode(xEnable, OUTPUT);

  // init Y Pins
  pinMode(yStep, OUTPUT);
  pinMode(yDirection, OUTPUT);
  pinMode(yEnable, OUTPUT);

  // init Y Pins
  pinMode(zStep, OUTPUT);
  pinMode(zDirection, OUTPUT);
  pinMode(zEnable, OUTPUT);
  
  // Enable Pins
  digitalWrite(xEnable,LOW);
  digitalWrite(yEnable,LOW);
  digitalWrite(zEnable,LOW);
}

void loop(){    
  if(!isOnStartPoint){
    goToStartPoint();
  }

  while(Serial.available()==0);
  delay(500);

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(Serial);

  if (root.success()) {
    int startX = root["start"][0];
    int startY = root["start"][1];

    int endX = root["end"][0];
    int endY = root["end"][1];


    movePone(startX, startY, endX, endY);
  }
}

void goToStartPoint(){
  delay(500);
  digitalWrite(yStep, HIGH);
  for(Index = 0; Index < 2300; Index++){
    digitalWrite(yDirection,HIGH);
    delayMicroseconds(400);
    digitalWrite(yDirection,LOW);
    delayMicroseconds(400);
  }

  delay(500);
  isOnStartPoint = true;
}

void movePone(int startX, int startY, int endX, int endY){
  digitalWrite(zStep, LOW);
  for(Index = 0; Index < 2600; Index++){
    digitalWrite(zDirection,HIGH);
    delayMicroseconds(250);
    digitalWrite(zDirection,LOW);
    delayMicroseconds(250);
  }


  delay(1000);
  digitalWrite(xStep, HIGH);
  for(Index = 0; Index < startX; Index++){
    digitalWrite(xDirection,HIGH);
    delayMicroseconds(200);
    digitalWrite(xDirection,LOW);
    delayMicroseconds(200);
  } 


  delay(1000);
  digitalWrite(yStep,LOW);
  for(Index = 0; Index < startY + 2300; Index++){
    digitalWrite(yDirection,HIGH);
    delayMicroseconds(400);
    digitalWrite(yDirection,LOW);
    delayMicroseconds(400);
  }


  delay(1000);
  digitalWrite(zStep,HIGH);
  for(Index = 0; Index < 2600; Index++){
    digitalWrite(zDirection,HIGH);
    delayMicroseconds(250);
    digitalWrite(zDirection,LOW);
    delayMicroseconds(250);
  }


  delay(1000);
  for(pos=30;pos>=1;pos -=1){
    delay(80);
    myservo.write(pos);
  }


  delay(1000);
  digitalWrite(zStep, LOW);
  for(Index = 0; Index < 2600; Index++){
    digitalWrite(zDirection,HIGH);
    delayMicroseconds(250);
    digitalWrite(zDirection,LOW);
    delayMicroseconds(250);
  }


  delay(1000);
  digitalWrite(yStep,HIGH);
  for(Index = 0; Index < startY + 2300; Index++){
    digitalWrite(yDirection,HIGH);
    delayMicroseconds(400);
    digitalWrite(yDirection,LOW);
    delayMicroseconds(400);
  }


  delay(1000);
  digitalWrite(xStep, LOW);
  for(Index = 0; Index < startX; Index++){
    digitalWrite(xDirection,HIGH);
    delayMicroseconds(200);
    digitalWrite(xDirection,LOW);
    delayMicroseconds(200);
  } 


  delay(1000);
  digitalWrite(zStep,HIGH);
  for(Index = 0; Index < 2600; Index++){
    digitalWrite(zDirection,HIGH);
    delayMicroseconds(250);
    digitalWrite(zDirection,LOW);
    delayMicroseconds(250);
  }


  delay(1000);
  for(pos=0;pos<30;pos +=1){
    delay(80);
    myservo.write(pos);
  }
}
