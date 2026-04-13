const int botaoA = 12;
const int ledAtuador = 2;
unsigned long tempoInicio = 0;   
const long duracaoCiclo = 5000;  
bool cicloAtivo = false;         

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(ledAtuador, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long tempoAtual = millis();

  if (digitalRead(botaoA) == LOW && !cicloAtivo) {
    cicloAtivo = true;
    tempoInicio = tempoAtual; 
    digitalWrite(ledAtuador, HIGH);
    Serial.println("Ciclo Iniciado...");
    delay(200); 
  }

 
  if (cicloAtivo) {
   
    if (tempoAtual - tempoInicio >= duracaoCiclo) {
      digitalWrite(ledAtuador, LOW);
      cicloAtivo = false; 
      Serial.println("Ciclo Finalizado automaticamente.");
    }
  }
}