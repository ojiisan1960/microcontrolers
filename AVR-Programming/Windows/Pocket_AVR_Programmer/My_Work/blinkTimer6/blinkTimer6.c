/* 
    From AVR-Timers.pdf Chap 5
    using a timer with clock prescaler and CTC with interrupts
    */

#include <avr/io.h>
#include <avr/interrupt.h>

int main (void) {
    DDRB |= 0xff;                           //set all ports output
    TIMSK1 |= ( 1 << TOIE1 );               //enable overflow interrupt
    sei();                                  //enable global interrupts
    TCCR1B |= (1 << CS11 );                 //set up the timer FCPU/8

    while (1)
    {
        //do something here if we want
    }
}

ISR(TIMER1_OVF_vect)
{
            PORTB ^= ( 1 << 1 );            //toggle the led
}
