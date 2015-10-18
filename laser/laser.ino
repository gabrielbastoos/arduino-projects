int led=11;
int lightPin = 0;  
char leitura;
void setup(){
  Serial.begin(9600);
pinMode(led,OUTPUT);
digitalWrite(led,LOW);
}
void loop(){
  
  
        Serial.println(analogRead(lightPin)); //Write the value of the photoresistor to the serial monitor.
    delay(500);
    
  while(Serial.available()>0) {
   leitura=Serial.read();  
   if(leitura=='l'){    //L
  digitalWrite(led,HIGH);
  }
   }
   if(leitura=='d'){
     digitalWrite(led,LOW);  
  }


   }
        

