/*
 *  Counting presses
 */

int switchPin = 2;              // switch is connected to pin 2
int ledPin = 12;
int val;                        // variable for reading the pin status
int val2;                      // second variable
int buttonState;                // variable to hold the button state
int ledMode = 0;                // LED state

void setup() {
  pinMode(switchPin, INPUT);    // Set the switch pin as input
  pinMode(ledPin, OUTPUT);
  buttonState = digitalRead(switchPin);   // read the initial state
}


void loop(){
  // debouncing
  val = digitalRead(switchPin);      // read input value and store it in val
  delay(10);                         // 10 milliseconds is a good amount of time
  val2 = digitalRead(switchPin);     // read the input again to check for bounces
  if (val == val2) {
    
    if (val != buttonState) {          // the button state has changed!
      if (val == LOW) {                // check if the button is pressed
        if ( ledMode == 0 ) {          // if led is off
        ledMode = 1;                  // set ledMode to on
         } else {               
        ledMode = 0;                // set ledMode to off
        }
      }
    }
  buttonState = val;                 // save the new state in our variable
   }


if (ledMode == 1 ) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
}
