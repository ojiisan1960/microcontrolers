## Simple demo
## Sits forever listening to serial port
## When you press button, opens website of your choosing.
## Extend this to many buttons and you'll have a physical
##  web-launcher.  

BOSS_SITE = "http://www.cartalk.com/content/boss-redirect"
WORK = "http://www.cnet.com/topics/security/"
## or perhaps more topical...
XKCD = "http://xkcd.com/353/"

#SERIAL_PORT = "/dev/ttyUSB0"	# Linux
#SERIAL_PORT = 'COM5'                # windows using native python and command line
SERIAL_PORT = "/dev/ttyS4"           # windows cygwin /dev/ttyS0 = COM1
BAUD_RATE = 9600

import serial
import webbrowser

sp = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout = 5)
sp.flush()
print ("Boss Button")

while(1):                       # Sit and wait forever
    response = sp.read(1)       # get one byte
    if response == "O":
        print "Got OK Byte.  Waiting for button press."
    elif response == "X":
        print "Got Boss Byte!  Alarm!"
        webbrowser.open(WORK)
    else:
        print "Got nothing.  Still goofing off."


