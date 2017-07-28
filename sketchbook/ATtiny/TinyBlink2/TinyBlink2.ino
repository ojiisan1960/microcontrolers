/*
  Blink for ATtiny85
  Turns an LED on and off repeatedly.
*/

void setup() {
  // initialize digital pin 0 as an output.
  pinMode(0, OUTPUT); //Red LED
  pinMode(1, OUTPUT); //Green LED
}

void loop() {
  digitalWrite(0, HIGH);   // turn the Red LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(0, LOW);    // turn the Red LED off by making the voltage LOW
  //delay(1000);              // wait for a second
  digitalWrite(1, HIGH);  //turn the Green LED on
  delay(1000);            //wait
  digitalWrite(1, LOW);  //turn the Green LED off
  //delay(1000);            //wait
}
