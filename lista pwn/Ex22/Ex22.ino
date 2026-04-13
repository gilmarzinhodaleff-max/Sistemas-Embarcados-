const int botaoA = 12;      
const int ledPressao = 2;   
const int ledSolda = 3;     
const int ledPronto = 4;    
const int potenciaFixa = 255; 

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(ledPressao, OUTPUT);
  pinMode(ledSolda, OUTPUT);
  pinMode(ledPronto, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(botaoA) == LOW) {
    Serial.println("Ciclo Iniciado...");

    delay(800);

    digitalWrite(ledPressao, HIGH);
    Serial.println("Pressurizando...");

    delay(200);

    analogWrite(ledSolda, potenciaFixa); 
    Serial.println("Soldando...");
    delay(1500);

    analogWrite(ledSolda, 0);
    Serial.println("Resfriando sob pressao...");

    delay(500);
    digitalWrite(ledPressao, LOW);
    digitalWrite(ledPronto, HIGH);
    Serial.println("Peca Pronta!");
    delay(2000);
    digitalWrite(ledPronto, LOW);
  }
}