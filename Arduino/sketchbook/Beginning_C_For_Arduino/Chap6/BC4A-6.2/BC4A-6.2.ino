
/**

Program: test user input for leap year. The code assumes the 
user is not an idiot and only enters valid numbers

**/

#define MAXCHARS 10

void setup() 
{
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0){
  int bufferCount;
  int year;
  char myData[MAXCHARS + 1];  //save room for null
  bufferCount = ReadLine(myData);
  year = atoi(myData);      //convert to int

  Serial.print("Year: ");
  Serial.print(year);
  Serial.print(" is ");

  if (IsLeapYear(year) == 0){
    Serial.print(" not ");
  }
    Serial.println("a leap year");
    }
}

/****
Function: IsLeapYear
Purpose: Determine is year is a leapyear
Parameters:
  int yr  - The year to test
Return value:
  int - 1 if the year is a leapyear, otherwise 0
*****/

int IsLeapYear(int yr)
{
  if(yr % 4 == 0 && yr % 100 != 0 || yr % 400 == 0){
    return 1; // its a leapyear
  } else {
    return 0; // not a leapyear
    }
}
  
/*****
Function: ReadLine
Purpose: Read data from the serial port until a newline is read
Parameters: 
  char str[] - character array that will be treated as a 
  terminated string
Return value:
  int - the numbers of characters read for the string
*****/

int ReadLine(char str[])
{
  char c;
  int index = 0;

  while(true){
    if (Serial.available() > 0){
      index = Serial.readBytesUntil('\n', str, MAXCHARS);
      str[index] = '\0'; //null termination character
      break;
      }
  }
  return index;
} 

