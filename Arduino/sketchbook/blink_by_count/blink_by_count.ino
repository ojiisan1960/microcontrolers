/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 10;
int delay_time = 1000;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  Serial.begin(9600);  
}

// the loop routine runs over and over again forever:
void loop() {
  for (int delay_time = 1000; delay_time > 0; delay_time--){
  Serial.println(delay_time);
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delay_time);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(delay_time);               // wait for a second
  }
}
