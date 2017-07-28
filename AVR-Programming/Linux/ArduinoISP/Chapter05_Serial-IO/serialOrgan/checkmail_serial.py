import imaplib, serial, struct, time

USER = 'mark.wogahn@gmail.com'
PASS = 'vSQTf9YhjEkB'

class Mail():
    def __init__(self):
        self.user= USER
        self.password= PASS
        self.ser = serial.Serial('/dev/ttyUSB0', 9600)
        self.M = imaplib.IMAP4_SSL('imap.gmail.com', '993')
        self.M.login(self.user, self.password)
        
    def checkMail(self):
        self.M.select()
        self.unRead = self.M.search(None, 'UnSeen')
        return len(self.unRead[1][0].split())
    
    def sendData(self):
        self.numMessages= self.checkMail()
        #turn the string into packed binary data to send int
        self.ser.write(struct.pack('B', self.numMessages))
        
email = Mail()

# check for new mail every minute
while 1:
    print 'Sending'
    email.sendData()
    time.sleep(60)
