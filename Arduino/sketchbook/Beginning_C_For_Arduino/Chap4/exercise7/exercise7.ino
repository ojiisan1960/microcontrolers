/*****
Enter the number 5 in the serial console
What does it do?

*****/

void setup() {

  Serial.begin(9600);
}

void loop() {
  
  char c;
  int num;
  int code;

  if (Serial.available() > 0) {
    c = Serial.read();            // This fetches the '5'
  
  // some code to make sure it was a digit character...

    code = (int)(c);
    num = (int) (c -'0');
    
    Serial.print("Character entered is: ");
    Serial.println(c);
    
    Serial.print("ASCII code for ");
    Serial.print(c);
    Serial.print(" is: ");
    Serial.println(code);
    
    Serial.print((int)c);
    Serial.print(" - ");
    Serial.print((int) '0');
    Serial.print(" = ");
    Serial.println((int)(c-'0'));
    
    Serial.print("num is: ");
    Serial.println(num);
  }
}
