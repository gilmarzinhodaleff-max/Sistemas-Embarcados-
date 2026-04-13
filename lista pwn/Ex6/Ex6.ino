const int led2 = 3;      
const int pinoPot = A0;
unsigned long anteriorMillis = 0;
int estadoLed2 = LOW;

void setup() {
  Serial.begin(9600); 
  pinMode(led2, OUTPUT);
  pinMode(pinoPot, INPUT);
}

void loop() {
 
  int leitura = analogRead(pinoPot);

 
  long intervalo = map(leitura, 0, 1023, 2000, 100);

  
  unsigned long atualMillis = millis();

  
  if (atualMillis - anteriorMillis >= (unsigned long)intervalo) {
    anteriorMillis = atualMillis;

    
    estadoLed2 = !estadoLed2; 
    digitalWrite(led2, estadoLed2);
    
  
    Serial.print("Intervalo: ");
    Serial.println(intervalo);
  }
}