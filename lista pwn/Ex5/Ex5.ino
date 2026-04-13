const int pinNTC = A1; 
const int led4 = 5;    
unsigned long anteriorMillisPisca = 0;
const long intervaloPisca = 100; 
int estadoLed4 = LOW;
const int referenciaTemp = 200; /

void setup() {
  Serial.begin(9600);
  pinMode(led4, OUTPUT);
}

void loop() {

  int leituraNTC = analogRead(pinNTC);
   Serial.println(leituraNTC);
  if (leituraNTC > referenciaTemp) {
    
    unsigned long atualMillis = millis();
    
    if (atualMillis - anteriorMillisPisca >= intervaloPisca) {
      anteriorMillisPisca = atualMillis; 

      if (estadoLed4 == LOW) {
        estadoLed4 = HIGH;
      } else {
        estadoLed4 = LOW;
      }
      
      digitalWrite(led4, estadoLed4);
    }
  } 
  else {
    
    estadoLed4 = LOW;
    digitalWrite(led4, LOW);
  }
}