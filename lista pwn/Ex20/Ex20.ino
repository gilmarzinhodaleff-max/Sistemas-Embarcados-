const int pinoPot = A0;   
const int ledVerde = 2;    
const int ledAmarelo = 3;  
const int ledVermelho = 4; 
const int ledChave = 5;    
unsigned long tempoForaDaFaixa = 0; 
bool sistemaAtivo = true;           
void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledChave, OUTPUT);
  digitalWrite(ledChave, HIGH);
  Serial.begin(9600);
}
void loop() {
  int leitura = analogRead(pinoPot);
  float tensao = map(leitura, 0, 1023, 0, 250);
  unsigned long agora = millis();

  if (sistemaAtivo) {
    digitalWrite(ledVerde, (tensao >= 210 && tensao <= 230));
    digitalWrite(ledAmarelo, (tensao < 210));
    digitalWrite(ledVermelho, (tensao > 230));
    if (tensao < 180 || tensao > 240) {
      if (tempoForaDaFaixa == 0) tempoForaDaFaixa = agora;
      if (agora - tempoForaDaFaixa >= 2000) {
        sistemaAtivo = false;
        digitalWrite(ledChave, LOW); 
      }
    } else {
      tempoForaDaFaixa = 0; 
    }
  } else {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
  }
  Serial.println(tensao);
  delay(50);
}