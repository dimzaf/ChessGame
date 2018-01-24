#include <Servo.h>
Servo myservo;

String axisInput;
int stepInput;
int voltInput;

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
int yMaxSteps = 10000;

// init Z axis variables
int zStep = 8;
int zDirection = 9;
int zEnable = 10;
int zMaxSteps = 2600;

// init claw pin
int clawPin = 7;

void setup() {
  Serial.begin(9600);

  myservo.attach(clawPin);
//  myservo.write(10);
  
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

void loop() {
  Serial.println("Give me Axis");
  while(Serial.available()==0);


















  // wait for input  
  // Serial.println("Give me Axis");
  // while(Serial.available()==0);
  // axisInput = Serial.readString();

  // Serial.println("Give me step");
  // while(Serial.available()==0);
  // stepInput = Serial.parseInt();

  // Serial.println("Give me volt");
  // while(Serial.available()==0);
  // voltInput = Serial.parseInt();

  // delay(1000);

  // if(axisInput != NULL){
  //   int direction;
  //   int step;
  //   int degrees;

  //   if(axisInput == "X"){
  //     direction = xDirection;
  //     step = xStep;
  //   }else if(axisInput == "Y"){
  //     direction = yDirection;
  //     step = yStep;
  //   }else if(axisInput == "Z"){
  //     direction = zDirection;
  //     step = zStep;
  //   }

  //   if(direction != NULL){
  //     digitalWrite(step, voltInput);
      
  //     for(Index = 0; Index < stepInput; Index++){
  //       digitalWrite(direction,1);
  //       delayMicroseconds(400);
  //       digitalWrite(direction,0);
  //       delayMicroseconds(400);
  //     }

  //     delay(1000);

  //    digitalWrite(step, !voltInput);
     
  //    for(Index = 0; Index < stepInput; Index++){
  //      digitalWrite(direction,1);
  //      delayMicroseconds(400);
  //      digitalWrite(direction,0);
  //      delayMicroseconds(400);
  //    }
  //   }
  // }
}