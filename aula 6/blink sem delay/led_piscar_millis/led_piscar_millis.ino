const int ledY = 8;
const int ledW = 9;
const int ledG = 10;
const int ledR = 11;
unsigned long intervalo = 1000;
unsigned long tempo_anterior = 0;
bool estado = 0;

void setup() {
  pinMode(ledY, OUTPUT);
  pinMode(ledW, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledR, OUTPUT);

}

void loop() {
  unsigned long tempo_atual = millis();
  if (tempo_atual - tempo_anterior >= intervalo) {
    estado = !estado;
    digitalWrite(ledY, estado);
    digitalWrite(ledR, estado);
    tempo_anterior = tempo_atual;
  
  }
}
