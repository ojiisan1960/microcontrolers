#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Ultrasonic.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

Ultrasonic::Ultrasonic(int pin)
{
	_pin = pin;
}
void Ultrasonic::Measure(void)
{
	pinMode(_pin, OUTPUT);
	digitalWrite(_pin, LOW);
	delayMicroseconds(2);
	digitalWrite(_pin, HIGH);
	delayMicroseconds(5);
	digitalWrite(_pin,LOW);
	pinMode(_pin,INPUT);
	duration = pulseIn(_pin,HIGH);
	RangeInCentimeters = duration/29/2;
	RangeInInches = duration/74/2;	
}
