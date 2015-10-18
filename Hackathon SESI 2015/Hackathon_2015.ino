#include <SoftwareSerial.h>
SoftwareSerial bluetooth(10, 11);
int rele=8; 
char leitura;
void setup(){
  bluetooth.begin(9600);
  pinMode(rele,OUTPUT);
  digitalWrite(rele,LOW);
}
void loop(){
  while(bluetooth.available()>0) {
   leitura=bluetooth.read();  
   if(leitura=='l'){    //L
  digitalWrite(rele,HIGH);
  }
   
   if(leitura=='d'){     //D
     digitalWrite(rele,LOW); 
   }
   }
}
        

