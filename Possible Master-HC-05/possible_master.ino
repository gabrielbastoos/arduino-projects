#include <SoftwareSerial.h>
SoftwareSerial BTMasterHC05(8, 9); // RX do BT | TX do BT
 
void setup()
{
  Serial.begin(9600);
  BTMasterHC05.begin(38400);  
}
 
void loop()
{     
      BTMasterHC05.write(Serial.read());
}

