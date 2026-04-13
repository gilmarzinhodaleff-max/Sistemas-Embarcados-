const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int pinoPot = A0;

unsigned long anteriorMillis = 0;
const long intervaloLeitura = 100; 

void setup() {
  Serial.begin(9600); 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  unsigned long atualMillis = millis();

  if (atualMillis - anteriorMillis >= intervaloLeitura) {
    anteriorMillis = atualMillis;

    int leitura = analogRead(pinoPot);
    
    int porcentagem = map(leitura, 0, 1023, 0, 100);

    
    Serial.print("Leitura: ");
    Serial.print(leitura);
    Serial.print(" e Porcentagem: ");
    Serial.println(porcentagem);

    
    digitalWrite(led1, (porcentagem >= 25) ? HIGH : LOW);
    digitalWrite(led2, (porcentagem >= 50) ? HIGH : LOW);
    digitalWrite(led3, (porcentagem >= 75) ? HIGH : LOW);
    digitalWrite(led4, (porcentagem > 90) ? HIGH : LOW);
  }
}