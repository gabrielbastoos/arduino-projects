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

int volumemedida;

int volumeanterior;
int variacao;

  int volume = 500; //mL SETAR O VOLUME DO RECIPIENTE
  int altura = 10;//cm SETAR A ALTURA DO RECIPIENTE
  //500mL esta para 10cm assim como o volume contido esta para cmMsec
  

  
  
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
bool disableSD = false;

// Only run 50 time so we can reburn the code easily.
#define CYCLES         100
size_t count = 0;




int sensordechuva = 3;





void setup()
  {
  Serial.begin(9600);
  Serial.println("Comecando a medida do ultrassom...");
  
  
  
pinMode(sensordechuva,INPUT);




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
  
    int volumemedida = (volume*cmMsec)/altura;
     
    int volumeanterior = (volume*cmMsec)/altura;
  
  //if(digitalRead(sensordechuva) == 0)
    if(count < CYCLES)
   {
    if(disableSD)
      {
      Serial.print("Distancia: ");
      Serial.println(cmMsec);
      }
    else
      {      
      cmStdDev = ultrasonic.unbiasedStdDev(cmMsec, BUFFER_02);
      Serial.print(count + 1);
      Serial.print("- Distancia: ");
      Serial.println(cmMsec);    
      
      Serial.print("Volume primeira medida: ");
      Serial.print(volumeanterior);
      Serial.println("mL ");
      
      delay(10000);
      

      Serial.print("Volume segunda medida:  ");
      Serial.print(volumemedida);
      Serial.println("mL ");
    if(volumemedida-volumeanterior!=0)
    {
    int dimi = volumemedida-volumeanterior;
    int variacao = dimi/5;
    Serial.print("Variacao de volume entre a medida anterior foi:   ");
    Serial.print(variacao);
    Serial.println("mL ");
    
    
    
    
    
    
    }
    else{
      
    Serial.println("o volume nao alterou");
      }
      }
      count++;
      }
  
  delay(1000);
  }
