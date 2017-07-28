//Use a Sony remote to turn something on and off
// uses the Play and Stop buttons on the remote

#include <IRremote.h>
#define PLAY 0x4cb92
#define STOP 0x1cb92

int RECV_PIN = 11;
int OUTPUT_PIN = 4;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  pinMode(OUTPUT_PIN, OUTPUT);
  pinMode(13, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
}

int on = 0;
unsigned long last = millis();

void loop() {
  if (irrecv.decode(&results)) {
    if (results.value == PLAY) { // Sony DVD play
      digitalWrite(OUTPUT_PIN, HIGH);
    } 
    else if (results.value == STOP) { // Sony DVD stop
      digitalWrite(OUTPUT_PIN, LOW);
    }   
    irrecv.resume(); // Receive the next value
  }
}

