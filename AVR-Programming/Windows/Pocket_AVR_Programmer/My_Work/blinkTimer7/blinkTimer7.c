/* 
    From AVR-Timers.pdf Chap 5
    using a timer with clock prescaler and CTC with interrupts
    instead of counting from 0 to 65535 set the start count to 
    a different value
    */

#include <avr/io.h>
#include <avr/interrupt.h>

int main (void) {
    DDRB |= 0xff;                           //set all ports output
    TIMSK1 |= ( 1 << TOIE1 );               //enable overflow interrupt
    sei();                                  //enable global interrupts
    TCCR1B |= ( 1 << CS10 ) | (1 << CS11 ); //set up the timer FCPU/64
    TCNT1 = 49910;  // preload the timer start value 

    while (1)
    {
        //do something here if we want
    }
}

ISR(TIMER1_OVF_vect)
{
            PORTB ^= ( 1 << 1 );            //toggle the led
            TCNT1 = 49910;                  //reset the timer start value
}
