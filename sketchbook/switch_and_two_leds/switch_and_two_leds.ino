/*
 *  Switch and LED test program
 */
 
int led1Pin = 12;                // LED is connected to pin 12
int led2Pin = 11;
int switchPin = 2;              // switch is connected to pin 2
int val;                        // variable for reading the pin status


void setup() {
  pinMode(led1Pin, OUTPUT);      // Set the LED pin as output
  pinMode(led2Pin, OUTPUT);
  pinMode(switchPin, INPUT);    // Set the switch pin as input
}


void loop(){
  val = digitalRead(switchPin);   // read input value and store it in val
  if (val == LOW) {               // check if the button is pressed
     digitalWrite(led1Pin, HIGH);   // turn LED 1 on
     digitalWrite(led2Pin, LOW);  //turn LED 2 off
  }
  if (val == HIGH) {              // check if the button is not pressed
    digitalWrite(led1Pin, LOW);    // turn LED 1 off
    digitalWrite(led2Pin, HIGH);   // turn LED 2 on
  }
}
