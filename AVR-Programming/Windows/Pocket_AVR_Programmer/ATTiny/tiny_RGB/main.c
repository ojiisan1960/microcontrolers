/* 
 *  RGB LED mood light
 *  http://www.instructables.com/id/3-Easy-ATTiny-Holiday-Gifts/step3/The-Color-Scroller/
 */
#include <avr/io.h>
#include <util/delay.h>

void PWM() //Setup PWM
{

  GTCCR = 0b00000000;   //General Timer/Counter Control Register
  //TCCR0A = 0b10000001;
  TCCR0A |= ( 1 << COM0A1 ) | ( 1 << WGM00 );
 // TCCR0B = 0b00000001;
  TCCR0B |= ( 1 << CS00 );  //No clock prescaling, full speed
  OCR0A = 0xFF;         //Output Compare Register set to 255
  //TCCR1 = 0b01010111;   
  TCCR1 |= ( 1 << PWM1A )|(1 <<COM1A0 );
  TCCR1 |= ( 1 << CS12 )|( 1 << CS11 )|( 1 << CS10 );
  //GTCCR = 0b01010000;
  GTCCR |= ( 1 << PWM1B )|( 1 << COM1B0 );
  OCR1B = 0x00;
  OCR1A = 0xFF;
}

#define blue OCR1B
#define green OCR0A
#define red OCR1A

int main()
{
  blue = ~0;
  green = 0;
  red = 0;
  uint8_t y = 50; //This controls speed
  uint8_t c = 1;
  DDRB = 0xFF;
  unsigned int x = 0;

  PWM(); //This initiates PWM

  while(1)
    {
      while(c == 1) //Blue to red
  {
    x++;
    blue = x;
    red = ~x;
    _delay_ms(y);
    if(x == 255)
      c++;
  }
     while(c == 2) //Red to green
  {
    x--;
    red = ~x;
    green = ~(255-x);
    _delay_ms(y);
    if(x == 0)
      c++;
  }
      while(c == 3) //Green to blue 
  {
    x++;
    green = ~(255-x);
    blue = ~(x);
    _delay_ms(y);
    if(x == 255)
      c++;
  } 
      while(c == 4) //Restart code
  { 
    x = 0;
    c = 1;
  }
    }
}
