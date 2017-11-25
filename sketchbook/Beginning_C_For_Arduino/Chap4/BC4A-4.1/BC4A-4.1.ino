/*
  Beginning C For Arduino
  4-1
  Alternate Blink
  Alternates between two LEDs one second, repeatedly
*/

const int LED1 = 10;
const int LED2 = 11;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital LED pins as an output.
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED1, HIGH);   // turn LED1 on (HIGH is the voltage level)
  digitalWrite(LED2, LOW);    // turn LED2 off
  delay(1000);                       // wait for a second
  digitalWrite(LED1, LOW);    // turn LED1 off by making the voltage LOW
  digitalWrite(LED2, HIGH);   // turn LED2 on
  delay(1000);                       // wait for a second
}
