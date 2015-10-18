int pinoLed = 12;
int pinoSensor = 8;    
  void setup(){
    Serial.begin(9600);
    pinMode(pinoLed, OUTPUT);
    pinMode(pinoSensor, INPUT);
  }
       
  void loop(){
      if (digitalRead(pinoSensor)==1){
         digitalWrite(pinoLed, LOW);}
      else{
         digitalWrite(pinoLed, HIGH);
      }  
    }

