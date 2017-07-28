
#include <Servo.h>
#include "Ultrasonic.h"

Servo rArm;  // create a servo object for the right arm
Servo lArm;  // create a servo object for the left arm
Ultrasonic sensor(7);  // create the object for the sensor


void setup()
{
  rArm.attach(9);  // attach the servo to pin 9 in the servo object
  lArm.attach(10); // attach the servo to pin 10 in the servo object
  rArm.write(90);  // set the servo to the midpoint
  lArm.write(90);  // set the servo to the midpoint
}

void loop()
{
  sensor.Measure();  //send a ping and listen for echo
  if (sensor.RangeInInches > 24)  //change number for distance reaction
  {
    lArm.write(85);  //eyes covered
    rArm.write(95);  //eyes covered
    delay(500);
  }
  else {
    lArm.write(120);  //eyes uncovered
    rArm.write(60);   //eyes uncoveredr
    delay(2000);
  }
}


