#include <IRremote.h>

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
    // If it's been at least 1/4 second since the last
    // IR received, toggle the relay
    if (millis() - last > 250) {
      on = !on;
      Serial.print("button pressed\n");
      digitalWrite(OUTPUT_PIN, on ? HIGH : LOW);
    }
    last = millis();      
    irrecv.resume(); // Receive the next value
  }
}
