
# Can I check Google mail for new mail from
# https://mail.google.com/mail/feed/atom
# and have an alert sent to the MCU via serial?

# Found this bit of code at
# http://j4mie.org/blog/how-to-make-a-physical-gmail-notifier/

import serial, sys, feedparser

#Settings - Change these to match your account details
USERNAME="mark.wogahn@gmail.com"
PASSWORD="freakjob2011"
PROTO="https://"
SERVER="mail.google.com"
PATH="/gmail/feed/atom"

SERIALPORT = "/dev/ttyUSB0" # Change this to your serial port!

# Set up serial port
try:
    ser = serial.Serial(SERIALPORT, 9600)
except serial.SerialException:
    sys.exit()

newmails = int(feedparser.parse(
    PROTO + USERNAME + ":" + PASSWORD + "@" + SERVER + PATH
)["feed"]["fullcount"])

# Output data to serial port
if newmails > 0: ser.write('M')
else: ser.write('N')

# Close serial port
ser.close()
