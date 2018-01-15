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
  
//  myservo.attach(clawPin);

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
//  Serial.println(Serial.readString());

  char json[] = "{}";
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(json);

  if (root.success()) {
    Serial.println("parseObject() success");
  }else{
    Serial.println("parseObject() failed");
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
