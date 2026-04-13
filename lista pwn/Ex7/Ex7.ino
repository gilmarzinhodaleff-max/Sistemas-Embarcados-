const int led1 = 2;
const int botaoA = 3; 
const int botaoB = 4; 
unsigned long tempoInicioLED = 0;  
const long duracaoLED = 5000;       
bool ledligado = false;              

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(botaoB, INPUT_PULLUP);
}

void loop() {
  unsigned long atualMillis = millis();

  if (digitalRead(botaoA) == LOW && !ledligado) {
    digitalWrite(led1, HIGH);
    tempoInicioLED = atualMillis; 
    ledligado = true;
  }

 
  if (digitalRead(botaoB) == LOW && ledligado) {
    digitalWrite(led1, LOW);
    ledligado= false; 
  }

  
  if (ledligado) {
    if (atualMillis - tempoInicioLED >= duracaoLED) {
      digitalWrite(led1, LOW);
      ledligado = false; 
    }
  }
}