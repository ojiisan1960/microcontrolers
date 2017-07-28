/*
  Blink for ATtiny85
  Turns an LED on and off repeatedly.
*/

void setup() {
  // initialize digital pin 0 as an output.
  pinMode(0, OUTPUT);
}

void loop() {
  digitalWrite(0, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(0, LOW);    // turn the LED off by making the voltage LOW
  //delay(1000);              // wait for a second
}
