float tempC;
int tempPin = 0;
int redPin= 11;
int greenPin= 10;
int bluePin= 9;

int blueTemp= 0; int greenTemp= 0; int redTemp= 0;

void setup()
{
Serial.begin(9600); //opens serial port, sets data rate to 9600 bps
}

void loop()
{
tempC = analogRead(tempPin);           //read the value from the sensor
tempC = (5.0 * tempC * 100.0)/1024.0;
Serial.print("Temperatura:" );//convert the analog data to temperature
Serial.println((byte)tempC);             //send the data to the computer

if(tempC<5){
analogWrite(bluePin, 255);}
else if(tempC>0&&tempC<=15){
blueTemp= map(tempC, 0, 15, 255, 0);
analogWrite(bluePin, blueTemp);}
else if(tempC>15){
analogWrite(bluePin, 0);}

if(tempC<15){
analogWrite(greenPin, 0);}
else if(tempC>15&&tempC<=35){
greenTemp = map(tempC, 15, 35, 1, 254);
analogWrite(greenPin, greenTemp);}
else if(tempC>35&&tempC<=55){
greenTemp = map(tempC, 35, 55, 255, 0);
analogWrite(greenPin, greenTemp);}
else if(tempC>55){
analogWrite(greenPin, 0);}

if(tempC<25){
analogWrite(redPin, 0);}
else if(tempC>=25){
redTemp= map(tempC, 25, 55, 1, 255);
analogWrite(redPin, redTemp);}
else if(tempC>55){
analogWrite(redPin, 255);}
Serial.print("Green temp:" );
Serial.println(greenTemp);
Serial.print("Red temp:" );
Serial.println(redTemp);
Serial.print("Blue temp:" );
Serial.println(blueTemp);
Serial.println(" ");
delay(500);                           //wait 200 ms before sending new data
}
