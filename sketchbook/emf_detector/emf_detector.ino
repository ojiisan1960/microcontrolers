// Aaron ALAI EMF Detector April 22nd 2009 VERSION 1.0
// aaronalai1@gmail.com
// *future note, put in averaging function to average val which should result in a more
// smooth response from the led.  I will give you a hint on how to make an averaging function;
// it involves the use of an array


int inPin = 5;             // analog 5
int val = 0;                 // where to store info from analog 5
int pin11 = 11;         // output of red led

void setup() {
 
  Serial.begin(9600);
 
}

void loop() {
 
  val = analogRead(inPin);                    // reads in the values from analog 5 and
                                                                   //assigns them to val
  if(val >= 1){
   
    val = constrain(val, 1, 100);               // mess with these values                                      
    val = map(val, 1, 100, 1, 255);        // to change the response distance of the device
    analogWrite(pin11, val);                    // *note also messing with the resistor should change 
                                                                   // the sensitivity
   }else{                                                     // analogWrite(pin11, val); just tuns on the led with
                                                                  // the intensity of the variable val
    analogWrite(pin11, 0);                     // the else statement is just telling the microcontroller
                                                                 // to turn off the light if there is no EMF detected
  }
 
 Serial.println(val);                                // use output to aid in calibrating
 
}
