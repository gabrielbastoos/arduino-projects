int led=7;
char leitura;

void setup(){
  Serial.begin(38400);
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);

}
void loop(){    
  while(Serial.available()>0) {
   leitura=Serial.read();  
   if(leitura=='l'){    //L
  digitalWrite(led,HIGH);
  }
   
   if(leitura=='d'){
     digitalWrite(led,LOW);  
  }
  }
   }
        

