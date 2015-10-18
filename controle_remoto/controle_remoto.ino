#include <LiquidCrystal.h>
#include <IRremote.h>
#define luzfundo 7
LiquidCrystal lcd (12,11,6,5,4,2);
const int  buttonPin = 8;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
IRsend irsend;




void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(luzfundo,OUTPUT);
  digitalWrite(luzfundo,HIGH);
}




void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
      buttonPushCounter++;
      //Serial.println("on");
      Serial.print("Apertos:  ");
      Serial.println(buttonPushCounter);
      lcd.setCursor(0,0);
      lcd.print("Contagem");
      lcd.setCursor(0,1);
      lcd.print(buttonPushCounter);
    } 
    else {
      // if the current state is LOW then the button
      // wend from on to off:
     // Serial.println("off"); 
    }
  }
  lastButtonState = buttonState;

  
  // turns on the LED every four button pushes by 
  // checking the modulo of the button push counter.
  // the modulo function gives you the remainder of 
  // the division of two numbers:
  if(buttonPushCounter == 7){
     irsend.sendRC5(0x80C, 12);
  }
    if(buttonPushCounter == 6){
     irsend.sendRC5(0xC, 12);
  }
    if(buttonPushCounter ==5){
     irsend.sendRC5(0x805, 12);
  }
    if(buttonPushCounter ==4){
     irsend.sendRC5(0x804, 12);
  }
  if (buttonPushCounter % 4 == 0) {
    digitalWrite(ledPin, HIGH);
  } else {
   digitalWrite(ledPin, LOW);
  }
  
}
