const int pinoPot = A0;
const int ledVerde = 2;
const int ledVermelho = 3;
const int limiteCritico = 800; 
const int frequenciaAlerta = 100; 

unsigned long anteriorMillis = 0;
bool estadoPisca = false;

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(pinoPot);
  unsigned long atualMillis = millis();

  if (leitura > limiteCritico) {
    // --- ESTADO DE ALERTA ---
    digitalWrite(ledVerde, LOW); // Desliga o indicador normal

    // Lógica de pisca em alta frequência
    if (atualMillis - anteriorMillis >= frequenciaAlerta) {
      anteriorMillis = atualMillis;
      estadoPisca = !estadoPisca;
      digitalWrite(ledVermelho, estadoPisca);
    }
    
    Serial.print("!!! PERIGO !!! Valor: ");
  } 
  else {
    // --- ESTADO NORMAL ---
    digitalWrite(ledVerde, HIGH);   
    digitalWrite(ledVermelho, LOW); 
    
    Serial.print("Seguro. Valor: ");
  }

  Serial.println(leitura);
  delay(10);
}