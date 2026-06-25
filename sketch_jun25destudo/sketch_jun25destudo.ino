 Alarme com Sensor Ultrassônico (HC-SR04) sem TravamentosAqui, 
 o sensor ultrassônico mede a distância continuamente. 
 Se um objeto chegar a menos de 20cm, um LED pisca como alerta.
  A grande vantagem é que, mesmo enquanto o LED está piscando ou aceso,
   o sensor continua lendo distâncias,
    permitindo que o alarme desligue instantaneamente quando o objeto se afasta.
    cppconst int pinoTrig = 4;
    
const int pinoEcho = 5;
const int pinoLed = 13;

unsigned long tempoAnterior = 0;
int estadoLed = LOW;
const long intervaloBlink = 200; // Pisca o LED a cada 200ms

void setup() {
  pinMode(pinoTrig, OUTPUT);
  pinMode(pinoEcho, INPUT);
  pinMode(pinoLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // 1. Dispara o pulso do sensor ultrassônico
  digitalWrite(pinoTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinoTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoTrig, LOW);

  // Lê a duração do pulso
  long duracao = pulseIn(pinoEcho, HIGH);
  // Calcula a distância em centímetros
  int distancia = duracao * 0.034 / 2;

  // 2. Lógica sem delay para acionar o LED baseado na distância
  if (distancia < 20) {
    // Se está muito perto, faz o LED piscar sem travar o Arduino
    unsigned long tempoAtual = millis();
    if (tempoAtual - tempoAnterior >= intervaloBlink) {
      tempoAnterior = tempoAtual;
      if (estadoLed == LOW) {
        estadoLed = HIGH;
      } else {
        estadoLed = LOW;
      }
      digitalWrite(pinoLed, estadoLed);
    }
  } else {
    // Se está longe, desliga o LED
    digitalWrite(pinoLed, LOW);
    estadoLed = LOW;
  }