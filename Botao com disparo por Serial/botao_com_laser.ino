int Led=7; 
int buttonpin=8; 
int val; 
void setup() 
{ 
pinMode(Led,OUTPUT); 
pinMode(buttonpin,INPUT); 
} 
void loop() 
{ 
val=digitalRead(buttonpin); 
if(val==HIGH) 
{ 
digitalWrite(Led,HIGH); 
} 
else 
{ 
digitalWrite(Led,LOW); 
} 
}
