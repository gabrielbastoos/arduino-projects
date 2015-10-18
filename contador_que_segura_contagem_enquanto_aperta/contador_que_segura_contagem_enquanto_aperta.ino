const int botao = 8;
int valor = 0;
int atual = 0;
int anterior = 0;

void setup(){
  Serial.begin(9600);
  pinMode(botao, INPUT);
  
}
void loop(){
  atual = digitalRead(botao);
  if(atual == LOW){
    valor++;
    Serial.println(valor);
  }

}
