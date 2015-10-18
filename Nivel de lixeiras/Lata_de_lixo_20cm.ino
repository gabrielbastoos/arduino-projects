
#include "Ultrasonic.h"

//criando objeto ultrasonic e definindo as portas digitais do Trigger - 6 - e Echo - 7
Ultrasonic ultrasonic(6,7);

//Declaração das constantes referentes aos pinos digitais.

const int ledVermelho = 11;

long microsec = 0;
float distanciaCM = 0;

void setup() {
  Serial.begin(9600); //Inicizando o serial monitor
  
  pinMode(ledVermelho,OUTPUT); //Definindo pino digital 11 como saída.
}

void loop() {  
  microsec = ultrasonic.timing(); //Lendo o sensor
  distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM); //Convertendo a distância em CM

  ledDistancia();

  //Serial.print(distanciaCM);
 // Serial.println(" cm");
  //delay(1000);
}

//Método que centraliza o controle de acendimento dos leds.
void ledDistancia() {
  
  //Apagando todos os leds
  digitalWrite(ledVermelho,LOW);
  
  
  if (distanciaCM < 20) {
    digitalWrite(ledVermelho,HIGH);
    Serial.println("A lata esta cheia!");
    //delay(5000);
  }
}
