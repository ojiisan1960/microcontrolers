/*
  Software serial multple serial test
 
 Receives an integer from the software serial, blinks an LED that number of times, and returns a confirmation.

 The circuit: 
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)
 
 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts, 
 so only the following can be used for RX: 
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69
 
 Not all pins on the Leonardo support change interrupts, 
 so only the following can be used for RX: 
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).
 
This code has been modified for use on an ATtiny.
Created by Matthew on June 11, 2013
http://projectsfromtech.blogspot.com/
 
 This example code is in the public domain.
 
 */
#include <SoftwareSerial.h>

SoftwareSerial TinySerial(3, 4); // RX, TX

void setup()  
{
  // Open serial communications and let us know we are connected
  TinySerial.begin(9600);
  TinySerial.println("Tiny Serial Connected via SoftwareSerial Library");
  pinMode(1, OUTPUT);
}

void loop()
{
  if(TinySerial.available())
  {
    int received = TinySerial.parseInt();   //Contrary to what the Arduino playground would imply, parseIt is supported
    TinySerial.print("Received data...");
    TinySerial.println("Flashing LED");
    if(received >=30)    //So it doesn't blink 150 times when you type 150 instead of 15
      received = 30;     
    Blink(1, received);    //Blink the LED on pin 1
    
  }
}

void Blink(byte led, byte times){ // poor man's display
  for (byte i=0; i< times; i++){
    digitalWrite(led,HIGH);
    delay (250);
    digitalWrite(led,LOW);
    delay (175);
  }
}

