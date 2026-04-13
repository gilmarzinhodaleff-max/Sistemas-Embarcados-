const int pinoPot = A0;   
const int led = 3;        

unsigned long anteriorMillis = 0;
const long velocidadePisca = 200; 
int estadoLed = LOW;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(pinoPot);
  

  float volts = (leitura * 5.0) / 1023.0;

  unsigned long atualMillis = millis();

  
  if (volts <= 2.0) {
    digitalWrite(led, LOW);
  }
  
  else if (volts > 2.0 && volts < 4.0) {
    if (atualMillis - anteriorMillis >= velocidadePisca) {
      anteriorMillis = atualMillis;
      estadoLed = !estadoLed;
      digitalWrite(led, estadoLed);
    }
  }
  
  
  else {
    digitalWrite(led, HIGH);
  }

  
  Serial.print("Tensao: ");
  Serial.print(volts); 
  Serial.println(" V");
}