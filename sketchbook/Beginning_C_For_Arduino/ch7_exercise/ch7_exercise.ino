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
  int charcode;
  
// You need to provide the Process Step
  while(index < sizeof(message)) {
    charcode = message[index];
    if ( charcode == 44 ){
      Serial.print(" ");
    }
    Serial.print(charcode);
   index++;
  
}
  
 
  //Serial.print("The temperature is = ");
  //Serial.print(temperature);
  //Serial.print(" with humidity = ");
  //Serial.print(humidity);
  //Serial.print(" at ");
  //Serial.print(&message[holdIndex]);

}

void loop(){
 
}

