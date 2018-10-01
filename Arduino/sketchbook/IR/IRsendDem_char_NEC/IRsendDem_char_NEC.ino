/* Example program for from IRLib – an Arduino library for infrared encoding and decoding
 * Version 1.3   January 2014
 * Copyright 2014 by Chris Young http://cyborg5.com
 * Based on original example sketch for IRremote library 
 * Version 0.11 September, 2009
 * Copyright 2009 Ken Shirriff
 * http://www.righto.com/
 */
#include <IRLib.h>

IRsend My_Sender;

void setup()
{
  Serial.begin(9600);
}

void loop() {
  if (Serial.read() != -1) {
    //send a code  every time a character is received from the serial port
    //Toshiba power 2FD48B7
    My_Sender.send(NEC,0x2FD48B7, 32);
  }
}

