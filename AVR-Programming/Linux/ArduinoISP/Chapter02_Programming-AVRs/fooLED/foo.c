                                                       /* Blinker Demo */

// ------- Preamble -------- //
#include <avr/io.h>                        /* Defines pins, ports, etc */
#include <util/delay.h>                     /* Functions to waste time */
#define delaytime 250

int main(void) {

  // -------- Inits --------- //
  DDRB |= 0b0011000;            /* Data Direction Register B:
                                   writing a one to bit 5
                                   enables output to PB5 
				   D13 on the Arduino. */

  // ------ Event loop ------ //
  while (1) {

    PORTB = 0b00001000;          /* Turn on the fifth LED bit/pin in PORTB */
    _delay_ms(delaytime);                                           /* wait */

    PORTB = 0b00000000;          /* Turn off all B pins, including LED */
   // _delay_ms(1000);                                           /* wait */

    PORTB = 0b00010000;          /* Turn off all B pins, including LED */
    _delay_ms(delaytime);                                           /* wait */

    PORTB = 0b00000000;          /* Turn off all B pins, including LED */
    //_delay_ms(1000);                                           /* wait */

  }                                                  /* End event loop */
  return (0);                            /* This line is never reached */
}
