                                                       /* Blinker Demo */

// ------- Preamble -------- //
#include <avr/io.h>                        /* Defines pins, ports, etc */
#include <util/delay.h>                     /* Functions to waste time */
#define delaytime 500

int main(void) {

  // -------- Inits --------- //
  DDRB |= 0xff;            /* Data Direction Register B:
                                   writing a one to bit 5
                                   enables output to PB5 
				   D13 on the Arduino. */

  // ------ Event loop ------ //
  while (1) {

    //PORTB ^= 0b10101010;          /* Turn on the fifth LED bit/pin in PORTB */
    PORTB ^= (1 << 3) | (1 << 1);
    _delay_ms(delaytime);                                           /* wait */

  }                                                  /* End event loop */
  return (0);                            /* This line is never reached */
}
