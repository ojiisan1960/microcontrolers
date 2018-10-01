//Use the small (fan?) remote to turn something on and off
// uses the Off and On buttons on the remote

#include <IRremote.h>
#define ON   0x143226DB
#define OFF 0xA32AB931

int RECV_PIN = 11;
int OUTPUT_PIN = 4;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  pinMode(OUTPUT_PIN, OUTPUT);
  pinMode(13, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
}

int on = 0;
unsigned long last = millis();

void loop() {
  if (irrecv.decode(&results)) {
    if (results.value == ON) {
      Serial.println("On button pushed");
      digitalWrite(OUTPUT_PIN, HIGH);
    } 
    else if (results.value == OFF) {
      Serial.println("Off button pushed");
      digitalWrite(OUTPUT_PIN, LOW);
    } 
    Serial.println("Waiting for next button...");  
    irrecv.resume(); // Receive the next value
  }
}

