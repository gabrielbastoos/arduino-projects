/*
 AC Light Control
 
 Ryan McLaughlin <ryanjmclaughlin@gmail.com>
 
 Thanks to http://www.andrewkilpatrick.org/blog/?page_id=445 
   and http://www.hoelscher-hi.de/hendrik/english/dimmer.htm
  
*/

int AC_pin = 4;  // Output to Opto Triac
//int led = 3;      // LED for testing
int dim = 128;    // Dimming level (0-128)  0 = on, 128 = 0ff

void setup()                    // run once, when the sketch starts
{
 pinMode(AC_pin, OUTPUT);      // Set the light control pin as output
 //pinMode(led, OUTPUT);         // sets the LED as output
 
 attachInterrupt(0, light, RISING);  // Attach an Interupt to pin2 (interupt 0) for Zero Cross Detection
}

void light()  // function to be fired at the zero crossing to dim the light
{
 int dimtime = (65*dim);  // eval the proper pause to fire the triac
 delayMicroseconds(dimtime);  // delay the dim time
 digitalWrite(AC_pin, HIGH);  // fire the Triac
 delayMicroseconds(10);       // pause briefly to ensure the triac turned on
 digitalWrite(AC_pin, LOW);   // turn off the Triac gate (triac will not turn off until next zero cross)
}

void loop()
{
 if(dim > 0) { dim--; } else { dim=128; }  // Simple fade out from full brightness
}
