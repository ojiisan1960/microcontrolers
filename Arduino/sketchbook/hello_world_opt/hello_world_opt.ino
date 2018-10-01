/*
 * Hello World!
 *
 * This is an optimised version of Hello World
 * replacing Arduino functions with C code
 * the original version size was 1,798 bytes 
 * this version is 558 bytes
 */

#define BAUD_RATE 9600
#define BAUD_RATE_DIVISOR (F_CPU / 16 / BAUD_RATE - 1)
//a function to send a single character
void usart_putc(char c) {
  loop_until_bit_is_set(UCSR0A, UDRE0); // wait for transmit buffer to be empty
  UDR0 = c; // transmit character out the serial port
}
// a function to send a string of characters
void usart_puts(char *s) {
  while(*s) {
    usart_putc(*s);
    s++;
  }
}
void setup()                    // run once, when the sketch starts
{
  UCSR0A = 0;
  //Enable transmit
  UCSR0B =  1<<TXEN0;
  // Set 8N1 - 8 bit , no parity, 1 stop bit
  UCSR0C = 1<<UCSZ01 | 1<<UCSZ00;
  
  UBRR0 = BAUD_RATE_DIVISOR;
  
  usart_puts("Hello, world!");

}

void loop()                       // run over and over again
{
     // do nothing!
}
