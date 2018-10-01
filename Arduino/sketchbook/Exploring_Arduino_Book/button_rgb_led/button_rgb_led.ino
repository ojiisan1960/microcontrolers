// Exploring Arduino
// Listing 2-6
// A controllable RGB Led
// 

const int BLED=9;           //blue led on pin 9
const int GLED=10;          //green led on pin 10
const int RLED=11;           //red led on pin 11
const int BUTTON=2;         //push button on pin 2

boolean lastButton = LOW;   //last button state
boolean currentButton = LOW; //current button state
int ledMode = 0;              //cycle between led states

void setup() {
  pinMode (BLED, OUTPUT);
  pinMode (GLED, OUTPUT);
  pinMode (RLED, OUTPUT);
  pinMode (BUTTON, INPUT);  //set button to input ( not really needed, input is the default )

}

/* Debouncing function
 *  pass it the previous button state
 *  and return the current state
 */
 boolean debounce(boolean last)
 {
  boolean current = digitalRead(BUTTON);          //read the button state
  if (last !=current)                             //state is different
  {
    delay(5);                             //wait 5 ms
    current = digitalRead(BUTTON);        //read it again
  }
  return current;
 }
 /*
  * LED mode selection
  * pass a number for Led state
  */
void setMode(int mode)
{
  //RED
  if (mode == 1)
  {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
  }
  //GREEN
  else if (mode == 2)
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);
  }
  //BLUE
  else if (mode == 3)
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);
  }
  //PURPLE ( RED + BLUE )
  else if (mode == 4)
  {
    analogWrite(RLED, 127);
    analogWrite(GLED, 0);
    analogWrite(BLED, 127);
  }
  //TEAL (BLUE + GREEN )
  else if (mode == 5)
  {
    analogWrite(RLED, 0);
    analogWrite(GLED, 127);
    analogWrite(BLED, 127);
  }
  //ORANGE (GREEN + RED)
  else if (mode == 6)
  {
    analogWrite(RLED, 127);
    analogWrite(GLED, 127);
    analogWrite(BLED, 0);
  }
  //WHITE (GREEN + RED + BLUE)
  else if (mode == 7)
  {
    analogWrite(RLED, 127);
    analogWrite(GLED, 127);
    analogWrite(BLED, 127);
  }
  //OFF 
  else
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
  }
}

void loop() {
    currentButton = debounce(lastButton);   //read debounced state
    if (lastButton == LOW && currentButton == HIGH )  //if the button was pressed...
    {
      ledMode++;                          //increment the led mode
    }
    lastButton = currentButton;           //reset the button value
    //if you have cycled through all the mode, reset the mode counter to 0
    if (ledMode == 8) ledMode = 0;
    setMode(ledMode);                     //change the led state
}
