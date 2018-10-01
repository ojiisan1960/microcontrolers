/*
 * Exploring Arduino
 * listing 2-3
 * PWM with analogWrite
 * 
 */
const int LED = 9;              //led on pin 9
void setup() {
  pinMode(LED, OUTPUT);         //set pin 9 for output
}

void loop() {
  for (int i=0; i<256; i++)
  {
    analogWrite(LED, i);        //
    delay(10);                  //wait 10 ms
  }
  for (int i=255; i>0; i--)
  {
    analogWrite(LED, i);
    delay(10);
  }

}
