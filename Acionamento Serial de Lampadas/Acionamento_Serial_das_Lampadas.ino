int lampada1=7;
int lampada2=6;
int lampada3=5;
char leitura;
void setup(){
  Serial.begin(9600);
pinMode(lampada1,OUTPUT);
pinMode(lampada2,OUTPUT);
pinMode(lampada3,OUTPUT);
digitalWrite(lampada1,HIGH);
digitalWrite(lampada2,HIGH);
digitalWrite(lampada3,HIGH);
}
void loop(){
  while(Serial.available()>0) {
   leitura=Serial.read();
   
   if(leitura=='1'){
  digitalWrite(lampada1,LOW);
   }
   if(leitura=='2'){
  digitalWrite(lampada2,LOW);
   }
   if(leitura=='3'){
  digitalWrite(lampada3,LOW);
   }
   if(leitura=='d'){
     digitalWrite(lampada1,HIGH);
   }
   if(leitura=='f'){
digitalWrite(lampada2,HIGH);
   }
      if(leitura=='g'){
  digitalWrite(lampada3,HIGH);
   }
}
}
