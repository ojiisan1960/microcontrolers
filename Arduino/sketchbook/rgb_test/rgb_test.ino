// Exploring Arduino
// Listing 2-6
// A controllable RGB Led
// 

const int BLED=9;           //blue led on pin 9
const int GLED=10;          //green led on pin 10
const int RLED=11;           //red led on pin 11

void setup() {
  pinMode (BLED, OUTPUT);
  //pinMode (GLED, OUTPUT);
  //pinMode (RLED, OUTPUT);

}


void loop() {
  
    //digitalWrite(RLED, HIGH);
    //delay(500);
    //digitalWrite(RLED, LOW);
    //delay(500);
    //digitalWrite(GLED, HIGH);
    //delay(1000);
    //digitalWrite(GLED, LOW);
    //delay(1000);
    digitalWrite(BLED, HIGH);
    delay(1000);
    digitalWrite(BLED, LOW);
    delay(1000);
}
