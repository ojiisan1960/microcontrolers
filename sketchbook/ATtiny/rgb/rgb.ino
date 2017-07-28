/* 
 *  RGB LED mood light
 *  http://www.instructables.com/id/3-Easy-ATTiny-Holiday-Gifts/step3/The-Color-Scroller/
 */
#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>

void PWM() //Setup PWM
{

  GTCCR = 0b00000000;
  TCCR0A = 0b10000001;
  TCCR0B = 0b00000001;
  OCR0A = 0xFF;

  TCCR1 = 0b01010111;
  GTCCR = 0b01010000;
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
  char y = 50; //This controls speed
  char c = 1;
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
