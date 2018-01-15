#include <Servo.h>
Servo myservo;

int pos=0;
int Index;

// init X axis variables
int xStep = 11;
int xDirection = 2;
int xEnable = 3;
int xMaxSteps = 10000;

// init Y axis variables
int yStep = 4;
int yDirection = 5;
int yEnable = 6;
int xMaxSteps = 10000;

// init Z axis variables
int zStep = 8;
int zDirection = 9;
int zEnable = 10;
int zMaxSteps = 2600;

// init claw pin
int clawPin = 7;

void setup(){
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

}