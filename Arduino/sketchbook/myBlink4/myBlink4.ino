/*
  Blink 4
  Control 4 leds
 */
 
int led0 = 12;
int led1 = 11;
int led2 = 10;
int led3 = 9;
int time = 1000;

void setup() {                
  // initialize the digital pin as an output.
  // 
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);  
}
// turn a pin on and off
void flash(int pin) {
  digitalWrite(pin, HIGH);   // on
  delay(time);                  // wait 
  digitalWrite(pin, LOW);    // off
}

void loop() {
  
  flash(11);
  flash(12);
  flash(11);
  flash(12);
  flash(9);
  flash(10);
  flash(9);
  flash(10);
 
}
