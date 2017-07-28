/*
  Blink 2
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
int greenLed = 9;
int yellowLed = 10;
int redLed = 11;
int time = 200;

void setup() {                
  // initialize the digital pin as an output.
  // 
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  
  //pinMode(redLed, OUTPUT);
    
}

void loop() {
  digitalWrite(yellowLed, HIGH); // Red2 on
  delay(time);              // wait for 1 second
  digitalWrite(yellowLed, LOW);    // Red2 off
  
  digitalWrite(redLed, HIGH);   // Red on
  delay(time);                  // wait 1 second
  digitalWrite(redLed, LOW);    // Red off
  
  digitalWrite(greenLed, HIGH);   // Green on
  delay(time);                  // wait 1 second
  digitalWrite(greenLed, LOW);  //Green off

  digitalWrite(redLed, HIGH);   // Red on
  delay(time);                  // wait 1 second
  digitalWrite(redLed, LOW);    // Red off
  
  
  
 
}
