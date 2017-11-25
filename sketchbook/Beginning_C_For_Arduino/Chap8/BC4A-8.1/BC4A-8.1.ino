/*
 * Purpose: Simple program to demonstrate using a pointer
 * Dr. Purdum, Nov 22, 2014
 * */
#include <stdio.h>
int counter = 0;
void setup() {

  int k;
  int number = 5;
  int *ptrNumber;
  
  Serial.begin(115200);
  
  Serial.print("The lvalue for ptrNumber is: ");
  Serial.print((long) &ptrNumber, DEC);
  Serial.print(" and the rvalue is ");
  Serial.println((long) ptrNumber, DEC);
  
  //=== Put new statements here!
  ptrNumber = &number;
  *ptrNumber = 10;
  k = *ptrNumber;
  
  Serial.print("The lvalue for k is: ");
  Serial.print((long) &k, DEC);
  Serial.print(" and has an rvalue ");
  Serial.println(k, DEC);
  
  Serial.print("The lvalue for number is: ");
  Serial.print((long) &number, DEC);
  Serial.print(" and has an rvalue of ");
  Serial.println((int) number, DEC);
  }
  void loop() {}
