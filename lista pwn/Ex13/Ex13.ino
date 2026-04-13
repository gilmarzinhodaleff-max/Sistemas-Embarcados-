const int pinoSilo = A0;   
const int ledValvula = 2;  
const int ledAlarme = 5;   


unsigned long anteriorMillis = 0;
const long intervaloAlarme = 250; 
int estadoAlarme = LOW;


bool valvulaAberta = false;

void setup() {
  pinMode(ledValvula, OUTPUT);
  pinMode(ledAlarme, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(pinoSilo);
  float nivel = (leitura * 100.0) / 1023.0;
  unsigned long atualMillis = millis();
  if (nivel < 30.0) {
    valvulaAberta = true;
  } 
  else if (nivel >= 80.0 && nivel < 95.0 && valvulaAberta) {
  }
  if (nivel >= 95.0) {
    valvulaAberta = false;
  }
  digitalWrite(ledValvula, valvulaAberta ? HIGH : LOW);
  if (nivel >= 95.0) {
    if (atualMillis - anteriorMillis >= intervaloAlarme) {
      anteriorMillis = atualMillis;
      estadoAlarme = !estadoAlarme;
      digitalWrite(ledAlarme, estadoAlarme);
    }
  } else {
    digitalWrite(ledAlarme, LOW);
  }
  Serial.print("Nivel do Silo: ");
  Serial.print(nivel);
  Serial.println("%");
}