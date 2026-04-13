const int pinoNTC = A0;
const int ledResistencia = 2; 
const int ledNaFaixa = 3;     // LED 2
const int botaoA = 12;
bool sistemaLigado = false;
bool aquecendo = false;

void setup() {
  pinMode(ledResistencia, OUTPUT);
  pinMode(ledNaFaixa, OUTPUT);
  pinMode(botaoA, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(pinoNTC);
  float temperatura = (leitura * 200.0) / 1023.0;
  if (digitalRead(botaoA) == LOW) {
    delay(200); 
    sistemaLigado = !sistemaLigado; 
    
    if (!sistemaLigado) {
      aquecendo = false; 
    }
  }

  if (sistemaLigado) {
    if (temperatura <= 150.0) {
      aquecendo = true;
    } 
    else if (temperatura >= 160.0) {
      aquecendo = false;
    }
  } else {
    aquecendo = false;
  }
  if (temperatura >= 150.0 && temperatura <= 160.0 && sistemaLigado) {
    digitalWrite(ledNaFaixa, HIGH);
  } else {
    digitalWrite(ledNaFaixa, LOW);
  }
  digitalWrite(ledResistencia, aquecendo ? HIGH : LOW);
  Serial.print("Temp: ");
  Serial.print(temperatura);
  Serial.print(" C | Aquecendo: ");
  Serial.println(aquecendo ? "SIM" : "NAO");
  delay(100);
}