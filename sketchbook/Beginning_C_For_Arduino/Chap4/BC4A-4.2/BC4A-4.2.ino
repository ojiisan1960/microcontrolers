/*
  Beginning C For Arduino
  4-2
  Alternate Blink
  Alternates between two LEDs one second, repeatedly
*/

const int LED1 = 10;
const int LED2 = 11;

long counter = 0;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital LED pins as an output.
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
    if (counter % 2 == 1) {
  digitalWrite(LED1, LOW);    // turn LED2 off
  digitalWrite(LED2, HIGH);   // turn LED1 on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  }

    if (counter % 2 == 0) {
  digitalWrite(LED1, HIGH);   // turn LED2 on
  digitalWrite(LED2, LOW);    // turn LED1 off by making the voltage LOW
  delay(1000);                       // wait for a second
  }
  // increment counter
  counter = counter + 1;
}
