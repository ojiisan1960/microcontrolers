/* 
    From AVR-Timers.pdf Chap 4
    using a timer with clock prescaler and CTC
    */

#include <avr/io.h>

int main (void) {
    DDRB |= 0xff;                           //set all ports output
    TCCR1B |= ( 1 << WGM12 );               //set CTC mode
    OCR1A = 7812;                          //set timer count compare value
    TCCR1B |= ( 1 << CS10 ) | (1 << CS11 ); //set up the timer FCPU/64

    while (1)
    {
        if (TIFR1 & ( 1 << OCF1A ) )         //check timer interrupt register
        {
            PORTB ^= ( 1 << 1 );            //toggle the led
            TIFR1 = ( 1 << OCF1A );         //clear the CTC flag
            }
    }
}

