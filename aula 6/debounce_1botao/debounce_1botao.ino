const int botao = 2;
const int ledY = 8;
int estado_led = LOW;
int estado_botao;
int ultimo_estado_botao = HIGH;
unsigned long tempo_debounce = 0;
unsigned long atraso = 50;
void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(ledY, OUTPUT);
  digitalWrite(ledY, estado_led);
}

void loop() {
  int leitura = digitalRead(botao);
  if (leitura != ultimo_estado_botao) {
    tempo_debounce = millis();
  
  }
if ((millis()- tempo_debounce) > atraso)
{
  if (leitura != estado_botao){
    estado_botao = leitura;
    if (estado_botao == LOW){
      estado_led = !estado_led;
    }
  }
}
digitalWrite (ledY, estado_led);
ultimo_estado_botao = leitura;
}

