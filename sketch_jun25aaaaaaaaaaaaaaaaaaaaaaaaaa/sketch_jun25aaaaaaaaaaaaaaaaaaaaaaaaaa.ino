const int trig = 9;
const int echo = 10;
const int led = 13;

unsigned long ultimoPisca = 0;
bool estadoLed = false;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  // Pisca LED sem delay
  if (millis() - ultimoPisca >= 1000) {
    ultimoPisca = millis();

    estadoLed = !estadoLed;
    digitalWrite(led, estadoLed);
  }

  // Leitura do ultrassônico
  static unsigned long ultimaLeitura = 0;

  if (millis() - ultimaLeitura >= 100) {
    ultimaLeitura = millis();

    digitalWrite(trig, LOW);
    delayMicroseconds(2);

    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    long tempo = pulseIn(echo, HIGH, 30000);

    float distancia = tempo * 0.0343 / 2;

    Serial.println(distancia);
  }
}
