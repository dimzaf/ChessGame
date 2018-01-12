#include <Servo.h>
Servo myservo;

int pos=0;
int Index;

void setup(){
  myservo.attach(7);
  pinMode(6, OUTPUT); //Enable
  pinMode(4, OUTPUT); //Step
  pinMode(5, OUTPUT); //Direction
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, OUTPUT);
  
  digitalWrite(6,LOW);
  digitalWrite(10,LOW);
  digitalWrite(3,LOW);
}

void loop(){
  digitalWrite(8,LOW);

  for(Index = 0; Index < 2600; Index++){
    digitalWrite(9,HIGH);
    delayMicroseconds(250);
    digitalWrite(9,LOW);
    delayMicroseconds(250);
  }

  delay(1000);
  digitalWrite(4,LOW);

  for(Index = 0; Index < 10000; Index++){
    digitalWrite(5,HIGH);
    delayMicroseconds(400);
    digitalWrite(5,LOW);
    delayMicroseconds(400);
  }

  delay(1000);
  digitalWrite(8,HIGH);

  for(Index = 0; Index < 2600; Index++){
    digitalWrite(9,HIGH);
    delayMicroseconds(250);
    digitalWrite(9,LOW);
    delayMicroseconds(250);
  }

  delay(1000);

  for(pos=30;pos>=1;pos -=1){
    delay(80);
    myservo.write(pos);
  }

  digitalWrite(8,LOW);

  for(Index = 0; Index < 2600; Index++){
    digitalWrite(9,HIGH);
    delayMicroseconds(250);
    digitalWrite(9,LOW);
    delayMicroseconds(250);
  }

  delay(1000);
  digitalWrite(4,HIGH);

  for(Index = 0; Index < 10000; Index++){
    digitalWrite(5,HIGH);
    delayMicroseconds(400);
    digitalWrite(5,LOW);
    delayMicroseconds(400);
  }

  delay(1000);
 
  digitalWrite(11,HIGH);

  for(Index = 0; Index < 10000; Index++){
    digitalWrite(2,HIGH);
    delayMicroseconds(200);
    digitalWrite(2,LOW);
    delayMicroseconds(200);
  }

  delay(1000);
  digitalWrite(8,HIGH);

  for(Index = 0; Index < 2600; Index++){
    digitalWrite(9,HIGH);
    delayMicroseconds(250);
    digitalWrite(9,LOW);
    delayMicroseconds(250);
  }

  delay(1000);

  for(pos=0;pos<30;pos +=1){
    delay(80);
    myservo.write(pos);
  }


  digitalWrite(8,LOW);

  for(Index = 0; Index < 2600; Index++){
    digitalWrite(9,HIGH);
    delayMicroseconds(250);
    digitalWrite(9,LOW);
    delayMicroseconds(250);
  }

  delay(1000);
  digitalWrite(11,LOW);

  for(Index = 0; Index < 10000; Index++){
    digitalWrite(2,HIGH);
    delayMicroseconds(200);
    digitalWrite(2,LOW);
    delayMicroseconds(200);
  }

  delay(1000);
  
  for(pos=0;pos<30;pos +=1){
    delay(80);
    myservo.write(pos);
  }

  digitalWrite(8,HIGH);

  for(Index = 0; Index < 2600; Index++){
    digitalWrite(9,HIGH);
    delayMicroseconds(250);
    digitalWrite(9,LOW);
    delayMicroseconds(250);
  }
  
  delay (1000);
}