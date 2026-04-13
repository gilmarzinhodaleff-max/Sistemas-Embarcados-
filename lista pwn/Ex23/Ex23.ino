const int pinoNTC = A0;
const int ledAquecedor = 2;
const float LIMITE_SUPERIOR = 160.0;
const float LIMITE_INFERIOR = 150.0;


bool aquecendo = false;

void setup() {
  pinMode(ledAquecedor, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 
  int leitura = analogRead(pinoNTC);
  float temperatura = (leitura * 200.0) / 1023.0;

  
  if (temperatura < LIMITE_INFERIOR) {
    
    aquecendo = true;
  } 
  else if (temperatura > LIMITE_SUPERIOR) {
    
    aquecendo = false;
  }
  digitalWrite(ledAquecedor, aquecendo ? HIGH : LOW);
  Serial.print("Temp: ");
  Serial.print(temperatura);
  Serial.print(" C | Status: ");
  Serial.println(aquecendo ? "AQUECENDO" : "OFF");

  delay(500); 
  
}