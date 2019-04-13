
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX


char serial_input;
char myserial_input;
boolean myserial_flag = false;
String contact = "09173174911";
String msg = "";
String sms = "";

void setup() {
  
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
    
  }
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  digitalWrite(13, LOW);
}

void loop() { 
  
  if (Serial.available() > 0)
  {
    serial_input = Serial.read();
    msg += String(serial_input);
    if (serial_input == '\n')
    {
      Serial.println(msg);
      sms = msg;
      msg = "";
      sendmsg(sms);
    } 
    
  }
  
}

void sendmsg(String sms_)
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);
  mySerial.println("AT+CMGS=" + String('"') + String(contact) + String('"') + "\r");
  delay(1000);
  mySerial.println(sms_);
  delay(100);
  mySerial.println((char)26);
  
}
