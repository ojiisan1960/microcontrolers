/*
A simple test of serial-port functionality.
Takes in a character at a time and sends it right back out,
 displaying the ASCII value on the LEDs.
*/

// ------- Preamble -------- //
#include <avr/io.h>
#include <util/delay.h>
#include "pinDefines.h"
#include "USART.h"
#include <avr/power.h>

int main(void) {
  char serialCharacter;
//  clock_prescale_set(clock_div_1);                       /* full speed */


  // -------- Inits --------- //
  LED_DDR = 0xff;                            /* set up LEDs for output */
  initUSART();
  printString("Hello World!\r\n");                          /* to test */

  // ------ Event loop ------ //
  while (1) {

    serialCharacter = receiveByte();
    transmitByte(serialCharacter);
    LED_PORT = serialCharacter;		 /* display ascii/numeric value of character */

  }                                                  /* End event loop */
  return (0);
}
