/* 
    From AVR-Timers.pdf Chap 7
    Using Timer/Counter 2 8-bit with clock prescaler and hardware CTC
    to toggle PB3 - OC2A

    */

#include <avr/io.h>

int main (void) {
    DDRB |= 0xff;                   //set all ports output
    TCCR2A |= ( 1 << WGM21 );       //set CTC mode
    TCCR2A |= ( 1 << COM2A0 );      //enable timer2 compare channel toggle mode
    OCR2A = 150;                    //set timer count compare value
    TCCR2B |= ( 1 << CS22 ) | ( 1 << CS21 ) | ( 1 << CS20 ); //set up the timer prescaler

    while (1)
    {
        //do something here if we want
    }
}
