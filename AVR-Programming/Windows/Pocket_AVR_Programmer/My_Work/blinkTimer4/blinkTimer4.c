/* 
    From AVR-Timers.pdf Chap 5
    using a timer with clock prescaler and CTC with interrupts
    */

#include <avr/io.h>
#include <avr/interrupt.h>

int main (void) {
    DDRB |= 0xff;                           //set all ports output
    TCCR1B |= ( 1 << WGM12 );               //set CTC mode
    TIMSK1 |= ( 1 << OCIE1A );               //enable CTS interrupt
    sei();                                  //enable global interrupts
    OCR1A = 15624;                          //set timer count compare value
    TCCR1B |= ( 1 << CS10 ) | (1 << CS11 ); //set up the timer FCPU/64

    while (1)
    {
        //do something here if we want
    }
}

ISR(TIMER1_COMPA_vect)
{
            PORTB ^= ( 1 << 1 );            //toggle the led
}
