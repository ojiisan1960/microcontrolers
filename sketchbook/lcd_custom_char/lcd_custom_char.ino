#include <LiquidCrystal.h>

// initialize the library
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
LiquidCrystal lcd(12, 11, 8, 7, 6, 5);            

byte customChar[8] = {
  B01100,
    B01100,
    B00000,
    B01110,
    B11100,
    B01100,
    B11010,
    B10011 
};

void setup()
{
   pinMode(9, OUTPUT);
   analogWrite(9,50);
  // create a new custom character
  lcd.createChar(0, customChar);
  
  // set up number of columns and rows
  lcd.begin(16, 2);
  lcd.write((uint8_t)0);
}

void loop()
{

}


