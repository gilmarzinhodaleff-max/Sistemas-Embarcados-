const int pinoPot = A0;
const int ledVermelho = 2; 
const int ledAmarelo = 3;  
const int ledVerde = 4;    
unsigned long anteriorMillis = 0;
bool estadoPisca = false;

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(pinoPot);
  int nivel = map(leitura, 0, 1023, 0, 100);
  unsigned long atualMillis = millis();


  if (atualMillis - anteriorMillis >= 250) {
    anteriorMillis = atualMillis;
    estadoPisca = !estadoPisca;
  }

  // --- CLASSIFICAÇÃO DOS NÍVEIS ---

  if (nivel <= 10) { 
    // CRÍTICO BAIXO: Vermelho Pisca
    digitalWrite(ledVermelho, estadoPisca);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
  } 
  else if (nivel > 10 && nivel <= 30) {
    // BAIXO: Vermelho Fixo
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
  } 
  else if (nivel > 30 && nivel <= 70) {
    // MÉDIO: Amarelo Fixo
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, LOW);
  } 
  else if (nivel > 70 && nivel <= 90) {
    // ALTO: Verde Fixo
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, HIGH);
  } 
  else {
    // CRÍTICO ALTO: Verde Pisca
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, estadoPisca);
  }


  Serial.print("Nível do Reservatório: ");
  Serial.print(nivel);
  Serial.println("%");
  
  delay(50); 
}