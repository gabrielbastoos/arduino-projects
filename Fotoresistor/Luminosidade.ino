int lightPin = 0;  //define a pin for Photo resistor
int luminosidade;     //define a pin for LED

void setup()
{
    Serial.begin(9600);  //Begin serial communcation
}

void loop()
{
    //Serial.println(analogRead(lightPin));
    luminosidade=map(analogRead(lightPin),0,1023,0,100);
        Serial.print("Luminosidade:  ");
    Serial.print(luminosidade);
    Serial.println("%");
    
   delay(1000); 
}
