                                                       /* Blinker Demo */

// ------- Preamble -------- //
#include <avr/io.h>                        /* Defines pins, ports, etc */
#include <util/delay.h>                     /* Functions to waste time */

#define RED 1
#define YEL 3
#define GRN 4

int main(void) {

  // -------- Inits --------- //
  // Enable port 1,3,4 as outputs
  DDRB = (1<<RED) | (1<<YEL) | (1<<GRN); 	//DDRB |= 0b0011010;            
                              

  // ------ Event loop ------ //

  while (1) {

    PORTB |= (1<<GRN);          //PB4 HIGH - PORTB = 0b00010000
    _delay_ms(1000);           
    PORTB &= ~(1<<GRN);         //PB4 LOW - PORTB = 0b00000000;      

    PORTB |= (1<<YEL);          //PB3 HIGH - PORTB = 0b00001000
    _delay_ms(1000);            
    PORTB &= ~(1<<YEL);         //PB3 LOW - PORTB = 0b00000000;         
    
    PORTB |= (1<<RED);          //PB1 HIGH - PORTB = 0b00000010
    _delay_ms(1000);          
    PORTB &= ~(1<<RED);         //PB1 LOW - PORTB = 0b00000000;        


  }                                                  /* End event loop */
  return (0);                            /* This line is never reached */
}
