/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */
#include <LiquidCrystal.h>
#include <IRremote.h>
#define luzdefundo 7
LiquidCrystal lcd(12,11,5,4,3,2);
const int button = 8;
int valor = 0;
IRsend irsend;
int estadoatual = 0;
int estadoanterior= 0;

void setup()
{
  lcd.begin(16,2);
  pinMode(luzdefundo,OUTPUT);
  digitalWrite(luzdefundo,HIGH);
  pinMode(button,INPUT);
  Serial.begin(9600);
}

void loop(){
  estadoatual = digitalRead ( button );
  if (estadoatual=!estadoanterior){
    if(estadoatual ==HIGH){
     valor ++;
  lcd.print(valor);
  Serial.println(valor);
  }
  }
  estadoanterior=estadoatual;
  lcd.clear();
}
  
//  if(button =!0){
    
    //  irsend.sendRC5(0x100C, 12); // Sony TV power code
   //   delay(40);
  //  }
 
