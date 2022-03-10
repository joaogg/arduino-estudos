//Sensor de luz com LDR
#define tempo 10
int frequencia = 0;
int Pinofalante = 10; 
int ledPin = 7; //Led no pino 7
int ldrPin = 0; //LDR no pino analígico 8
int ldrValor = 0; //Valor lido do LDR

 
void setup() {
 pinMode(ledPin,OUTPUT); //define a porta 7 como saída
 Serial.begin(9600); //Inicia a comunicação serial
 pinMode(Pinofalante,OUTPUT); //Pino do buzzer
}
 
void loop() {
 ///ler o valor do LDR
 ldrValor = analogRead(ldrPin); //O valor lido será entre 0 e 1023
 
 //se o valor lido for maior que 500, liga o led
 if (ldrValor>= 500){
  digitalWrite(ledPin,HIGH);
  
   for (frequencia = 150; frequencia < 1800; frequencia += 1) 
  {
    tone(Pinofalante, frequencia, tempo); 
    delay(1);
  }
  for (frequencia = 1800; frequencia > 150; frequencia -= 1) 
  {
    tone(Pinofalante, frequencia, tempo); 
    delay(1);
  }
 }else{
  digitalWrite(ledPin,LOW);
 }
 
 //imprime o valor lido do LDR no monitor serial
 Serial.println(ldrValor);
 //delay(1000);
}
