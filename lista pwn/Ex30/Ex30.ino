
const int pinoSensor = A0;
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;

void setup() {

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
 
  int leitura = analogRead(pinoSensor);
  float voltagem = leitura * (5.0 / 1023.0);
  float temperatura = (voltagem - 0.5) * 100.0;
  
  // Nível 1: Maior que 20°C
  if (temperatura >= 20.0) { digitalWrite(led1, HIGH); } 
  else { digitalWrite(led1, LOW); }

  // Nível 2: Maior que 30°C
  if (temperatura >= 30.0) { digitalWrite(led2, HIGH); } 
  else { digitalWrite(led2, LOW); }

  // Nível 3: Maior que 40°C
  if (temperatura >= 40.0) { digitalWrite(led3, HIGH); } 
  else { digitalWrite(led3, LOW); }

  // Nível 4: Maior que 50°C
  if (temperatura >= 50.0) { digitalWrite(led4, HIGH); } 
  else { digitalWrite(led4, LOW); }

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" C");

  delay(200);
}