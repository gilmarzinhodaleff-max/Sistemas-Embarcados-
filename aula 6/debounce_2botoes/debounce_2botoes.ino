const int botao = 2;
const int botao2 = 3;

const int ledY = 8;
const int ledR = 11;

int estado_led = LOW;
int estado_led2 = LOW;

int estado_botao;
int estado_botao2;

int ultimo_estado_botao = HIGH;
int ultimo_estado_botao2 = HIGH;
unsigned long tempo_debounce = 0;
unsigned long tempo_debounce2 = 0;
unsigned long atraso = 50;
void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(ledY, OUTPUT);
  pinMode(ledR, OUTPUT);
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

 int leitura2 = digitalRead(botao2);
  if (leitura2 != ultimo_estado_botao2) {
    tempo_debounce = millis();
  
  }
if ((millis()- tempo_debounce) > atraso)
{
  if (leitura2 != estado_botao2){
    estado_botao2 = leitura2;
    if (estado_botao2 == LOW){
      estado_led2 = !estado_led2;
    }
  }
}
digitalWrite (ledY, estado_led);
ultimo_estado_botao = leitura;
digitalWrite (ledR, estado_led2);
ultimo_estado_botao2 = leitura2;
}

