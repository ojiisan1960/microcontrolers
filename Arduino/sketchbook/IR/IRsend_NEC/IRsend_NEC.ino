/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */


#include <IRremote.h>
#define POWER 0x4FB4AB5
IRsend irsend;

void setup()
{

}

void loop() {
  // wait for a button press here
  // if the button is pressed
	for (int i = 0; i < 3; i++) {
    // send the remote Power code 3 times
		irsend.sendNEC( POWER, 32);
		delay(40);
	}

 // no button - sleep?
	delay(5000); //5 second delay between each signal burst
}
