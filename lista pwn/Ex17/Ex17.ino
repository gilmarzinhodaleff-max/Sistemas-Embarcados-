const int pinoPot = A0;      
const int ledMotor = 3;      
const int botaoEmergencia = 2;
const int ledFalha = 4;      
bool emergenciaAtiva = false;
unsigned long anteriorMillis = 0;
const long intervaloPisca = 200; 
int estadoLedFalha = LOW;

void setup() {
  pinMode(ledMotor, OUTPUT);
  pinMode(ledFalha, OUTPUT);
  pinMode(botaoEmergencia, INPUT_PULLUP); 
  Serial.begin(9600);
}

void loop() {
  unsigned long atualMillis = millis();
  if (digitalRead(botaoEmergencia) == LOW) {
    emergenciaAtiva = true;
  }

  
  if (!emergenciaAtiva) {
    int leitura = analogRead(pinoPot);
    int velocidade = map(leitura, 0, 1023, 0, 255); 
    
    analogWrite(ledMotor, velocidade);
    digitalWrite(ledFalha, LOW); 
  } 
  else {
    
    analogWrite(ledMotor, 0); 
    if (atualMillis - anteriorMillis >= intervaloPisca) {
      anteriorMillis = atualMillis;
      estadoLedFalha = !estadoLedFalha;
      digitalWrite(ledFalha, estadoLedFalha);
    }
    
    
    Serial.println("EMERGÊNCIA ATIVA! Verifique o sistema.");
  }
}