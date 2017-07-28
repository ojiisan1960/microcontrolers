/*
 * Control a tri color common anode LED
 * Setting the OUTPUT to LOW turns on the LED
 */

int redPin = 11;                  // Red LED connected to digital pin 12
int greenPin = 10;                // Green LED connected to digital pin 11
int bluePin = 9;                 // Blue LED connected to digital pin 10

void setup()                      // run once, when the sketch starts
{
  pinMode(redPin, OUTPUT);        // sets the digital pin as output
  pinMode(greenPin, OUTPUT);      // sets the digital pin as output
  pinMode(bluePin, OUTPUT);       // sets the digital pin as output
}

void loop()                       // run over and over again
{
  digitalWrite(bluePin, LOW);
  delay(500);  
  digitalWrite(redPin, LOW);     // sets the Red LED on
  delay(500);
  //digitalWrite(redPin, HIGH);
  //delay(500);
  //digitalWrite(greenPin, HIGH);   // sets the Green LED on
  //delay(500);                     // waits for a second
  //digitalWrite(greenPin, HIGH);  // sets the Green LED off
  //delay(500);
  digitalWrite(bluePin, LOW);    // sets the Green LED on
  delay(500);                     // waits for a second
  digitalWrite(redPin, HIGH);    // sets the Red LED on
  delay(500);
}
