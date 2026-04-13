const int pinoNTC = A0;
const int ledExaustor = 3; 
const int ledAlerta = 4;   

void setup() {
  pinMode(ledExaustor, OUTPUT);
  pinMode(ledAlerta, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(pinoNTC);
  float temperatura = (leitura * 100.0) / 1023.0;
  int potenciaPWM = 0;
  if (temperatura < 30.0) {
    potenciaPWM = (255 * 0.20); 
    digitalWrite(ledAlerta, LOW);
  }
  else if (temperatura >= 30.0 && temperatura <= 60.0) {
    potenciaPWM = map(temperatura, 30, 60, 51, 255);
    digitalWrite(ledAlerta, LOW);
  }
  else {
    potenciaPWM = 255;
    digitalWrite(ledAlerta, HIGH);
  }
  analogWrite(ledExaustor, potenciaPWM);
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" C | Potencia PWM: ");
  Serial.println(potenciaPWM);
  
  delay(100); 
}