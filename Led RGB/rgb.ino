 
// declarando variaveis valores iniciais.
int menor_valor_lido=0;              SETAR VALOR MINIMO
int maior_valor_lido=100;                   SETAR VALOR MAXIMO
 
//---------------Setup
void setup() {
 
  Serial.begin(9600);
  referencia();
}
//---------------- void loop:
void loop() {
 
  int mq7 = analogRead(1);
  func_ajuste_de_limites(mq7); // função ajusta os valores máximos e mínimos
 
  //referência: map(valor lido, menor_valor_lido,maior_valor_lido, minimo%, maximo%)
  mq7 = map(mq7,menor_valor_lido, maior_valor_lido,0, 100);
 
  Serial.print(mq7);
  Serial.println("% de CO no ar");
  delay(200);
}
//----------------------------Funções:
void func_ajuste_de_limites(int mq7){ //Simples ajuste automático do máximos e mínimos
 
  if(mq7> maior_valor_lido){
    maior_valor_lido=mq7;
  }
  if(mq7< menor_valor_lido){
    menor_valor_lido= mq7;    
  }
}
 
void referencia(){
 
  Serial.println(">>---------------------------<<");
  Serial.println("Programa mosta % de gas CO no Ar");
  delay(1000);
}
