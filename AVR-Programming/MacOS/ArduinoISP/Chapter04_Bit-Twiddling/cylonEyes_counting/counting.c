#include <avr/io.h>                        /* Defines pins, ports, etc */
#define F_CPU 1000000UL          /* Sets up the chip speed for delay.h */
#include <util/delay.h>                     /* Functions to waste time */

#define DELAYTIME 500

int main(void) {
  DDRB = 0b11111111;		/*set all pins for PORTB output*/
  PORTB = 0;

  while (1) {
  	PORTB += 1;
    	_delay_ms(DELAYTIME);
    }
  }
