const int led1 = 2; 
const int led2 = 3; 
const int led3 = 5; 
const int led4 = 6; 
const int botaoA = 12;
enum Estados { PARADO, ENCHIMENTO, LAVAGEM, DRENAGEM };
Estados estadoAtual = PARADO;
unsigned long tempoInicioEstado = 0;
unsigned long anteriorMillisPisca = 0;
bool alternarLed = false;
void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(botaoA, INPUT_PULLUP);
}
void loop() {
  unsigned long agora = millis();
  switch (estadoAtual) {
    case PARADO:
      if (digitalRead(botaoA) == LOW) {
        estadoAtual = ENCHIMENTO;
        tempoInicioEstado = agora;
        digitalWrite(led1, HIGH); 
      }
      break;
    case ENCHIMENTO:
      if (agora - tempoInicioEstado >= 4000) {
        digitalWrite(led1, LOW);
        estadoAtual = LAVAGEM;
        tempoInicioEstado = agora;
      }
      break;
    case LAVAGEM:
      if (agora - tempoInicioEstado < 8000) {
        if (agora - anteriorMillisPisca >= 500) {
          anteriorMillisPisca = agora;
          alternarLed = !alternarLed;
        }
        if (alternarLed) {
          analogWrite(led2, 127); 
          analogWrite(led3, 0);
        } else {
          analogWrite(led2, 0);
          analogWrite(led3, 127);
        }
      } else {
        analogWrite(led2, 0);
        analogWrite(led3, 0);
        estadoAtual = DRENAGEM;
        tempoInicioEstado = agora;
        digitalWrite(led4, HIGH);
      }
      break;
    case DRENAGEM:
      if (agora - tempoInicioEstado >= 4000) {
        digitalWrite(led4, LOW);
        estadoAtual = PARADO; 
      }
      break;
  }
}