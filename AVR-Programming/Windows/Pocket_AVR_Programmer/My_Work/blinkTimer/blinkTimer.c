/* 
    From AVR-Timers.pdf Chap 3
    using a timer with clock prescaler and polling ( no interrupts )
    */

#include <avr/io.h>

int main (void) {
    DDRB |= 0xff;                           // set all ports output
    TCCR1B |= (1 << CS10 ) | (1 << CS11 );  //set up the timer FCPU/64

    while (1)
    {
        if (TCNT1 >= 15624 )                //check the register count
        {
            PORTB ^= ( 1 << 0 );            //toggle the led
            TCNT1 = 0;                      //reset the timer
            }
    }
}

