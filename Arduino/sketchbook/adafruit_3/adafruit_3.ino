/*
Adafruit Arduino - Lesson 3. RGB LED
*/

/* using a common anode RGB led */

int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int time = 1000;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}

void loop()
{
  setColor(255, 0, 0);  // red
  delay(time);
  setColor(0, 255, 0);  // green
  delay(time);
  setColor(0, 0, 255);  // blue
  delay(time);
  setColor(255, 255, 0);  // yellow
  delay(time);  
  setColor(80, 0, 80);  // purple
  delay(time);
  setColor(0, 255, 255);  // aqua
  delay(time);
  setColor(0x4B, 0x0, 0x82);  // indigo
  delay(time);
}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, 255-red);
  analogWrite(greenPin, 255-green);
  analogWrite(bluePin, 255-blue);  
}
