/* Note: Trig and Echo should share the same Digital pin 7. The module is set up  so that it sends a ping 
over the trig pin and listens for the return on the echo pin. */

#include "Ultrasonic.h"

Ultrasonic ultrasonic(7);
void setup()
{
       Serial.begin(9600);
}
void loop()
{
        ultrasonic.Measure();
        Serial.println("The distance to obstacles in front is: ");
        //Serial.print(ultrasonic.RangeInCentimeters);
        //Serial.println(" cm");
        Serial.print(ultrasonic.RangeInInches);
        Serial.println(" inch");
        delay(500);
       
}

