int mq3_analogPin = A0; // connected to the output pin of MQ3 

void setup(){
  Serial.begin(9600); // open serial at 9600 bps
}

void loop()
{
  // give ample warmup time for readings to stabilize

  int mq3_value = analogRead(mq3_analogPin);
  Serial.print("Porcentagem de CO:  ");
  int valor = map(mq3_value,0,1023,0,100);
  Serial.println(valor);

  delay(100); //Just here to slow down the output.
}
