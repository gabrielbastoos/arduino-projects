/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int r = 8;
int g = 7;
int b = 6;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(r, OUTPUT);     
  pinMode(g, OUTPUT);    
  pinMode(b, OUTPUT);    
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(r, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);               // wait for a second
  digitalWrite(r, LOW);    // turn the LED off by making the voltage LOW
  delay(200);               // wait for a second
    digitalWrite(g, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);               // wait for a second
  digitalWrite(g, LOW);    // turn the LED off by making the voltage LOW
  delay(200);               // wait for a second
    digitalWrite(b, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);               // wait for a second
  digitalWrite(b, LOW);    // turn the LED off by making the voltage LOW
  delay(200);               // wait for a second
}
