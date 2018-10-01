// control a servo using a Sony remote
//Uses IRLib libraries

#include <IRLib.h>
#include <Servo.h> 

#define MY_PROTOCOL NEC
#define RIGHT_ARROW 0xE1446E91   //Move several clockwise
#define LEFT_ARROW  0xE144AE51 //Move servo counterclockwise
#define SELECT_BUTTON 0xE1444EB1 //Center the servo
#define UP_ARROW      0xE144EE11 //Increased number of degrees servo moves
#define DOWN_ARROW  0xE1441EE1 //Decrease number of degrees servo moves
#define BUTTON_0 0xE144728D  //Pushing buttons 0-9 moves to fixed positions
#define BUTTON_1 0xE144A25D  // each 20 degrees greater
#define BUTTON_2 0xE144629D
#define BUTTON_3 0xE144E21D
#define BUTTON_4 0xE14412ED
#define BUTTON_5 0xE144926D
#define BUTTON_6 0xE14452AD
#define BUTTON_7 0xE144D22D
#define BUTTON_8 0xE14432CD
#define BUTTON_9 0xE144B24D

IRrecv My_Receiver(11);//Receive on pin 11
IRdecode My_Decoder; 
Servo My_Servo;  // create servo object to control a servo 
int pos;         // variable to store the servo position 
int Speed;       // Number of degrees to move each time a left/right button is pressed
long Previous;   // Stores previous code to handle NEC repeat codes
void setup() 
{ 
  Serial.begin(9600);
  My_Servo.attach(9);  // attaches the servo on pin 9 to the servo object 
  pos = 90;            // start at midpoint 90 degrees
  Speed = 3;           // servo moves 3 degrees each time left/right is pushed
  My_Servo.write(pos); // Set initial position
  My_Receiver.enableIRIn(); // Start the receiver
} 

void loop() 
{ 
  if (My_Receiver.GetResults(&My_Decoder)) {
    My_Decoder.decode();
    if(My_Decoder.decode_type==MY_PROTOCOL) {
      if(My_Decoder.value==0xFFFFFFFF)
        My_Decoder.value=Previous;
      switch(My_Decoder.value) {
      case LEFT_ARROW:    
        pos=min(180,pos+Speed); 
        break;
      case RIGHT_ARROW:   
        pos=max(0,pos-Speed); 
        break;
      case SELECT_BUTTON: 
        pos=90; 
        break;
      case UP_ARROW:      
        Speed=min(10, Speed+1); 
        Serial.print("Speed :");
        Serial.println(Speed);
        break;
      case DOWN_ARROW:    
        Speed=max(1, Speed-1);
        Serial.print("Speed :");
        Serial.println(Speed); 
        break;
      case BUTTON_0:      
        pos=0*20; 
        break;
      case BUTTON_1:      
        pos=1*20; 
        break;
      case BUTTON_2:      
        pos=2*20; 
        break;
      case BUTTON_3:      
        pos=3*20; 
        break;
      case BUTTON_4:      
        pos=4*20; 
        break;
      case BUTTON_5:      
        pos=5*20; 
        break;
      case BUTTON_6:      
        pos=6*20; 
        break;
      case BUTTON_7:      
        pos=7*20; 
        break;
      case BUTTON_8:      
        pos=8*20; 
        break;
      case BUTTON_9:      
        pos=9*20; 
        break;
      }
      Serial.print("Key code: ");
      Serial.print(My_Decoder.value,HEX);
      Serial.print(" Servo position:");
      Serial.println(pos);
      My_Servo.write(pos); // tell servo to go to position in variable 'pos' 
      Previous=My_Decoder.value;
    }
    My_Receiver.resume();
  }
}

