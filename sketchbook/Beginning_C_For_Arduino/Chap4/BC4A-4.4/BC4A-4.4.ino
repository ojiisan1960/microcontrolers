/*****
Heads or Tails
Turns on an LED which represents head or tails. The LED
remains on for about 3 seconds and the cycle repeats.
Dr. Purdum, Nov 12, 2014

*****/

#define HEADIOPIN 10  // Which I/O pins are we using?
#define TAILIOPIN 11
#define PAUSE 1000      // How long to delay?

int headsCounter; // Heads/tails counters
int tailsCounter;
long loopCounter;
long randomNumber = 0L; // 'L' tells compiler it's a long data type, not an int


// the setup routine runs once when you press reset:

void setup() {
  Serial.begin(115200);
  headsCounter = 0;
  tailsCounter = 0;
  loopCounter = 0;
  pinMode(HEADIOPIN, OUTPUT);
  pinMode(TAILIOPIN, OUTPUT);
  randomSeed(analogRead(A0)); // This seeds the random number generator
}

void loop() {
  randomNumber = generateRandomNumber();
  digitalWrite(HEADIOPIN, LOW);
  digitalWrite(TAILIOPIN, LOW); // Turn both LED's off
  delay(PAUSE); // Let them see both are off for a time slice
  if (randomNumber % 2 == 1) {
    digitalWrite(HEADIOPIN, HIGH);
    headsCounter++; // Treat odd numbers as a head
    } else {
    digitalWrite(TAILIOPIN, HIGH); // Even numbers are a tail
    tailsCounter++;
    }
    loopCounter++;
    if (loopCounter % 100 == 0) { // See how things are every 100 flips
      Serial.print("After ");
      Serial.print(loopCounter);
      Serial.print(" coin flips, heads = ");
      Serial.print(headsCounter);
      Serial.print(" and tails = ");
      Serial.println(tailsCounter);
    }
    delay(PAUSE); // Pause for 3 seconds
  }

    long generateRandomNumber()
    {
      return random(0, 1000000); // Random numbers between 0 and one million
    } 
