/*
    Learing about timers

   PB5 and PB1 flash using delay_ms()
   PB3 flashes using timer1
   timer1 is 16 bit - count is 65535 to overflow
   
*/

// ------- Preamble -------- //
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "pinDefines.h"

#define delaytime 2000

// Initialize the timer, setting the clock prescale and timer interupt
static inline void initTimer1(void) {
               /* Normal mode (default), just counting */
//  TCCR1B |= (1 << CS10); 	/* clock speed: 1MHz / 1 ~= 65 ms */
//  TCCR1B |= (1 << CS11);	/* clock speed: 1MHz / 8 ~= 524 ms */
  TCCR1B |= (1 << CS11) | (1 << CS10); /* Clock speed: 1 MHz / 64 ~=4 s */
  
     /* each tick is 64 microseconds ~= 15.6 per ms  */
                                            /* No special output modes */
  // enable Timer1 overflow interrupt:
      TIMSK1 = (1 << TOIE1);
}

int main(void) {
  // -------- Inits --------- //

  cli();             				// disable global interrupts
  initTimer1();					// initialize timer1
  LED_DDR = 0xff;                               /* all LEDs for output */
  sei();					// enable interupts

  // ------ Event loop ------ //
  while (1) {

        PORTB ^= (1 << 5) | (1 << 1); 	/* blink every 'delaytime' */ 
	_delay_ms(delaytime); 

  }                                                  /* End event loop */

  return (0);                            /* This line is never reached */
}
  
ISR(TIMER1_OVF_vect) {

  	PORTB ^= ( 1 << 3 );			/* run at every timer1 overflow */
}
