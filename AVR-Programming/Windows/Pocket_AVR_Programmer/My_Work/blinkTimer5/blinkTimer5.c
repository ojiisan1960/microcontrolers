/* 
    From AVR-Timers.pdf Chap 7
    using 16 bit Timer/Counter 1 with clock prescaler and hardware CTC
    to toggle PB2

    */

#include <avr/io.h>

int main (void) {
    DDRB |= 0xff;                           //set all ports output
    TCCR1B |= ( 1 << WGM12 );               //set CTC mode
    TCCR1A |= ( 1 << COM1B0 );              //enable timer1 compare channel toggle mode
    OCR1A = 15624;                          //set timer count compare value
    TCCR1B |= ( 1 << CS10 ) | (1 << CS11 ); //set up the timer FCPU/64

    while (1)
    {
        //do something here if we want
    }
}
