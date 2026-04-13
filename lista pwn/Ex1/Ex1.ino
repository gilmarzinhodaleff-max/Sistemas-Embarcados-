
const int BotaoA = 2;
const int BotaoB = 3;
const int Led1   = 13;
bool estadoLed1 = LOW;

void setup() {
  pinMode(BotaoA, INPUT_PULLUP); 
  pinMode(BotaoB, INPUT_PULLUP); 
  pinMode(Led1, OUTPUT);
}

void loop() {
  bool botaoAPressionado = (digitalRead(BotaoA) == LOW);
  bool botaoBPressionado = (digitalRead(BotaoB) == LOW);


  // O LED só liga se A E B estiverem pressionados.
  // Se B for solto, a condição "botaoBPressionado" torna-se falsa,
  // desligando o LED imediatamente no próximo ciclo do loop.
  
  if (botaoBPressionado && botaoAPressionado) {
    estadoLed1 = HIGH;
  } else {
    estadoLed1 = LOW;
  }


  digitalWrite(Led1, estadoLed1);

  
}