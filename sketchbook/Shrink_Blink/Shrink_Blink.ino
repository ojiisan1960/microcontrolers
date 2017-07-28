/*
  Shrink_Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
  Optimised to reduce the binary size
  Original size: 1030 bytes
  New size: 469 bytes
 */

extern volatile unsigned long timer0_millis; // declare timer0_millis
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  //pinMode(13, OUTPUT);
  // set bit 5 in data direction register Port B
  //bitSet(DDRB, 5); // D13 (PB5) is now an output
  DDRB |= ( 1 << 5);
}

// the loop function runs over and over again forever
void loop() {
  //digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  //bitSet(PINB, 5);  // toggle the led pin
  DDRB ^= ( 1 << 5 );
  while(timer0_millis < 500); // wait 1 second
  timer0_millis = 0;  // reset the timer
  //delay(1000);              // wait for a second
  //digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  //delay(1000);              // wait for a second
}
