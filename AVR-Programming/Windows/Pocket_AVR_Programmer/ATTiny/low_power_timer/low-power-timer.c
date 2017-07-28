/* ATtiny85 Low-Power Timer */

#include <avr/sleep.h>

// Utility macros
#define adc_disable() (ADCSRA &= ~(1<<ADEN)) //disable ADC before power-off
#define adc_enable() (ADCSRA |= (1<<ADEN)) // re-enable ADC

// Constants
const int Speaker = 1;
const int Lamp = 0;
const unsigned long Alarm = 900000 // Alarm time - 15 minutes
unsigned long StartTime = 0;    //start time

void setup()
{
    pinMode(Lamp, OUTPUT);
    pinMode(Speaker, OUTPUT);
    adc_disable();      //ADC uses ~320uA when enabled
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
}

void enterSleep(void)
{
    sleep_enable();
    sleep_cpu();
}

void playBeep(void)
{
    for(int i=0; i<500; i++)
    {
        digitalWrite(Speaker, HIGH);
        delay(1);
        digitalWrite(Speaker, LOW);
        delay(1);
    }
}

void flashLed(int wait)
{
    digitalWrite(LAMP, HIGH);
    delay(wait);
    digitalWrite(LAMP, LOW);
}

// Main loop

void loop()
{
    //long flash
    flashLed(125);
    delay(125);
    flashLed(125);
    do
    {
        //Flash light
        flashLed(1);
        delay(2000);
    } while (millis() - StartTime < Alarm);
    //Alarm
    playBeep();
    enterSleep();
    // continue after reset
}
