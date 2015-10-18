/*
 * HCSR04Ultrasonic/examples/UltrasonicStdDev/UltrasonicStdDev.pde
 *
 * SVN Keywords
 * ----------------------------------
 * $Author: cnobile $
 * $Date: 2011-09-17 02:43:12 -0400 (Sat, 17 Sep 2011) $
 * $Revision: 29 $
 * ----------------------------------
 */

#include <Ultrasonic.h>

#define TRIGGER_PIN    12
#define ECHO_PIN       13

#define NUMBER_BUFFERS 1
#define BUFFER_SIZE    1

#define BUFFER_02      1


int volumenovo;

int volumeanterior = 0;

  int volumecheio = 500; //mL SETAR O VOLUME DO RECIPIENTE
  int alturavazio = 10;//cm SETAR A ALTURA DO RECIPIENTE
  //500mL esta para 10cm assim como o volume contido esta para cmMsec
  
  int alturacheio = 2 ;
  
  int  percentual;
  
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
bool disableSD = false;

// Only run 50 time so we can reburn the code easily.



void setup()
  {
  Serial.begin(9600);
  
  /*
   * If NUMBER_BUFFERS is 2 then it must be followed by two size variables
   * one for each buffer to be created. The size variables do not need to be
   * the same value.
   *
   * Example: ultrasonic.sampleCreate(3, 20, 10, 3) is valid.
   *
   * Note: The minimum size for any buffer is 2. Using less than 2 will waist
   *       resources and the buffer will be ignored.
   */
  if(!ultrasonic.sampleCreate(NUMBER_BUFFERS, BUFFER_SIZE, BUFFER_SIZE,
      BUFFER_SIZE))
    {
    disableSD = true;
    Serial.println("Could not allocate memory.");
    }
  }

void loop()
  {
     
  float cmMsec;
  float cmStdDev;
  long microsec = ultrasonic.timing();

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
   
// Serial.println("Medindo volume");

    if(disableSD)
      {
  //    Serial.print("Distancia entre a agua: ");
      Serial.println(cmMsec);
      }
    else
      {      
      cmStdDev = ultrasonic.unbiasedStdDev(cmMsec, BUFFER_02);
    //  Serial.print("Distancia entre o lixo: ");
      Serial.println(cmMsec);    
      
      volumenovo = map(cmMsec,alturavazio,alturacheio,0,volumecheio);
      int variacao = abs(volumenovo-volumeanterior);
      volumeanterior=volumenovo;
      //Serial.print("Lixo obtido em 0,5s: ");
     // Serial.print(variacao);
     //Serial.println("mL ");
   //  Serial.print("Percentual:  ");
     int percentual=abs((1-(cmMsec/16.68))*100);
   //  Serial.print(percentual);
   //  Serial.println("%");
    // Serial.println("");

      
     
      }
  delay(500);
  
  
  }
