#include <Adafruit_CircuitPlayground.h>


void setup() {
  CircuitPlayground.begin();
}

void loop() {
  delay(1000);
  CircuitPlayground.setPixelColor(0, 255, 0, 0);
  CircuitPlayground.setPixelColor(1, 0, 255, 0);
  CircuitPlayground.setPixelColor(2, 255, 0, 0);
  CircuitPlayground.setPixelColor(3, 0, 255, 0);
  CircuitPlayground.setPixelColor(4, 255, 0, 0);
  CircuitPlayground.setPixelColor(5, 0, 255, 0);
  CircuitPlayground.setPixelColor(6, 255, 0, 0);
  CircuitPlayground.setPixelColor(7, 0, 255, 0);
  CircuitPlayground.setPixelColor(8, 255, 0, 0);
  CircuitPlayground.setPixelColor(9, 0, 255, 0);
  delay(1000);
  CircuitPlayground.setPixelColor(1, 255, 0, 0);
  CircuitPlayground.setPixelColor(2, 0, 255, 0);
  CircuitPlayground.setPixelColor(3, 255, 0, 0);
  CircuitPlayground.setPixelColor(4, 0, 255, 0);
  CircuitPlayground.setPixelColor(5, 255, 0, 0);
  CircuitPlayground.setPixelColor(6, 0, 255, 0);
  CircuitPlayground.setPixelColor(7, 255, 0, 0);
  CircuitPlayground.setPixelColor(8, 0, 255, 0);
  CircuitPlayground.setPixelColor(9, 255, 0, 0);
  CircuitPlayground.setPixelColor(0, 0, 255, 0);


  if (CircuitPlayground.leftButton()) {
    CircuitPlayground.playTone(329, 500);
    delay(530);
    CircuitPlayground.playTone(329, 500);
    delay(530);
    CircuitPlayground.playTone(329, 1000);
    delay(1030);
    CircuitPlayground.playTone(329, 500);
    delay(530);
    CircuitPlayground.playTone(329, 500);
    delay(530);
    CircuitPlayground.playTone(329, 1000);
    delay(1030);
    CircuitPlayground.playTone(329, 500);
    delay(530);
    CircuitPlayground.playTone(392, 500);
    delay(530);
    CircuitPlayground.playTone(261, 500);
    delay(530);
    CircuitPlayground.playTone(294, 500);
    delay(530);
    CircuitPlayground.playTone(329, 2000);
    delay(2030);
    CircuitPlayground.playTone(349, 500);
    delay(530);
    CircuitPlayground.playTone(349, 500);
    delay(530);
    CircuitPlayground.playTone(349, 500);
    delay(530);
    CircuitPlayground.playTone(349, 500);
    delay(530);
    CircuitPlayground.playTone(349, 500);
    delay(530);
    CircuitPlayground.playTone(329, 500);
    delay(530);
    CircuitPlayground.playTone(329, 500);
    delay(530);
    CircuitPlayground.playTone(329, 250);
    delay(280);
    CircuitPlayground.playTone(329, 250);
    delay(280);
    CircuitPlayground.playTone(329, 500);
    delay(530);
    CircuitPlayground.playTone(294, 500);
    delay(530);
    CircuitPlayground.playTone(294, 500);
    delay(530);
    CircuitPlayground.playTone(329, 500);
    delay(530);
    CircuitPlayground.playTone(294, 1000);
    delay(1030);
    CircuitPlayground.playTone(392, 1000);
    delay(1030);
    CircuitPlayground.playTone(329, 500);
    delay(530);
    CircuitPlayground.playTone(329, 500);
    delay(530);
    CircuitPlayground.playTone(329, 1000);
    delay(1030);
    CircuitPlayground.playTone(329, 500);
    delay(530);
    CircuitPlayground.playTone(329, 500);
    delay(530);
    CircuitPlayground.playTone(329, 1000);
    delay(1030);
    CircuitPlayground.playTone(329, 500);
    delay(530);
    CircuitPlayground.playTone(392, 500);
    delay(530);
    CircuitPlayground.playTone(261, 500);
    delay(530);
    CircuitPlayground.playTone(294, 500);
    delay(530);
    CircuitPlayground.playTone(329, 2000);
    delay(2030);
    CircuitPlayground.playTone(349, 500);
    delay(530);
    CircuitPlayground.playTone(349, 500);
    delay(530);
    CircuitPlayground.playTone(349, 500);
    delay(530);
    CircuitPlayground.playTone(349, 500);
    delay(530);
    CircuitPlayground.playTone(349, 500);
    delay(530);
    CircuitPlayground.playTone(329, 500);
    delay(530);
    CircuitPlayground.playTone(329, 500);
    delay(530);
    CircuitPlayground.playTone(329, 250);
    delay(280);
    CircuitPlayground.playTone(329, 250);
    delay(280);
    CircuitPlayground.playTone(392, 500);
    delay(530);
    CircuitPlayground.playTone(392, 500);
    delay(530);
    CircuitPlayground.playTone(349, 500);
    delay(530);
    CircuitPlayground.playTone(294, 500);
    delay(530);
    CircuitPlayground.playTone(261, 2000);
  }

}

