/*****
Chapter 7 exercise
Data in: "tempurature,humidity,time"
Print out the message information to the serial terminal in the format
Temp: <tempurature>
Humidity: <humidity>
Time: <time>
*****/

void setup() { 
  Serial.begin(9600); 
  char message[] = "70.0,95,15:00";
  int index = 0;
  int holdIndex = 0;
  int temperature;
  int humidity;
 
 
  // You need to provide the Process Step
    Serial.print("Data in: ");
    Serial.println(message);
    Serial.print("The string length is:");
    Serial.println(strlen(message));
    
    while (index < strlen(message))  //read the message character array
    {
      
      if ( message[index] != ',')   // if its not a ',' print it
        {
          Serial.print(message[index]);
          
        } else
          Serial.println("");       // else print a newline
    index++;
  
   
    }
 
/* 
  while(index < sizeof(message)) {
    charcode = message[index];
    if ( charcode == 44 ){
      Serial.println(" ");
      charcode = ' ';
    }
  Serial.print(charcode);
   index++;
  
} */
  
 
  //Serial.print("The temperature is = ");
  //Serial.print(temperature);
  //Serial.print(" with humidity = ");
  //Serial.print(humidity);
  //Serial.print(" at ");
  //Serial.print(&message[holdIndex]);

}

void loop(){
 
}

