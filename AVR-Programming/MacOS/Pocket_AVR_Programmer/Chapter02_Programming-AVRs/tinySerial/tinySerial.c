// http://www.ernstc.dk/arduino/tinycom.html
//
#include <SoftwareSerial.h>

const int rx=3; //PB3 as rx
const int tx=1; //PB1 as tx
// set to -1 to disable either one

SoftwareSerial mySerial(rx,tx);
int i=0;
char buf[12];

void setup()
{
    pinMode(rx,INPUT);
    pinMode(tx,OUTPUT);
    mySerial.begin(9600);
}

void loop()
{
    if (mySerial.available()>0){
        buf[i]= mySerial.read();
        if (int(buf[i])==13 || int(buf[i])==10 ){ //If Carriage return has been reached
            mySerial.println(buf);
            for(int x=0;x<=10;x++){
                buf[x]=' ';
            }
            i=0; //start over again

        } //if enter
        i++;
    } //If mySerial.available
}//LOOP
