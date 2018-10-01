#ifndef Ultrasonic_H
#define Ultrasonic_H

class Ultrasonic
{
	public:
		Ultrasonic(int pin);
		long RangeInCentimeters;
		long RangeInInches;
		long duration;
		void Measure(void); 
	private:
		int _pin;
};
#endif
