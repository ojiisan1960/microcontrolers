## Scripting in python to drive the serial-port organ

## So far, the "protocol" is simple.  
## Python routine sends a note, waits for a return character, then sends next, etc.
## Organ listens for notes, when it gets one sends an 'N' to say it's ready
 
import serial

def playString(noteString, serialPort):
  for letter in noteString:
    print letter
    serialPort.write(letter)
    returnValue = serialPort.read(1)
    
if __name__ == "__main__":

  import time, urllib2

  ## Need to consider alternatives for Mac / Windows
  PORT = "/dev/ttyUSB0"
  BAUD = 9600

  s = serial.Serial(PORT, BAUD)
  s.flush()                     
  ## flush clears the buffer so that we're starting fresh
  ## More on serial buffers later.

  ## An intentional example.  You can use this for playing music on purpose.
  ##playString("f g h j k l ; ]'[", s)
  ##raw_input("Press enter for next demo\n")

  ## A fun / stupid example.  You can just type stuff and see what comes out.
  #3playString("hello there, this is a random string turned into 'music'", s)
  #3raw_input("Press enter for next demo\n")

  ## A really frivolous example.  Play websites!
  ## Bonus points for first person to tweet themselves a song.
  #3print ("Downloading song data from http://serialorgansongs.jottit.com/...")
  #3import re
  #3contentFilter = re.compile(r'<p>(.*?)</p>')
  #3songSite = urllib2.urlopen("http://serialorgansongs.jottit.com/").read()
  #3songText = contentFilter.findall(songSite)[0]
  #3playString(songText, s)
 
  ## Or interactive
  mySong = raw_input("\nType in your own song: ")
  playString(mySong, s)
