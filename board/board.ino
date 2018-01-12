String inputData;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Hello");
  delay(1000);

  // wait for input  
  while(Serial.available()==0);

  inputData = Serial.readString();
  Serial.println("You want me to make move:" + inputData);
}
