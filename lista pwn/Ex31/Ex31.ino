const int pinoNivel = A0;
const int pinoTemp = A1;
const int botaoHabilita = 12;
const int ledValvula = 2;  
const int ledAquecedor = 3;  
const int ledAlarme = 4;     
bool sistemaLigado = false;

void setup() {
  pinMode(ledValvula, OUTPUT);
  pinMode(ledAquecedor, OUTPUT);
  pinMode(ledAlarme, OUTPUT);
  pinMode(botaoHabilita, INPUT_PULLUP);
  
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(botaoHabilita) == LOW) {
    sistemaLigado = true;
  } else {
    sistemaLigado = false;
  }

  if (sistemaLigado) {
    int leituraNivel = analogRead(pinoNivel);
    int nivelPorcentagem = map(leituraNivel, 0, 1023, 0, 100);
    int leituraTemp = analogRead(pinoTemp);
    float voltagem = leituraTemp * (5.0 / 1023.0);
    float temperatura = (voltagem - 0.5) * 100.0; 

// Nível
    if (nivelPorcentagem < 20) {
      digitalWrite(ledValvula, HIGH); // Nível baixo: abre válvula
    } else if (nivelPorcentagem > 80) {
      digitalWrite(ledValvula, LOW);  // Nível alto: fecha válvula
    }

// Temperatura
    if (temperatura > 60.0) {
      // Temperatura ALTA: desliga aquecedor e ativa alarme
      analogWrite(ledAquecedor, 0);
      digitalWrite(ledAlarme, HIGH);
    } 
    else if (temperatura < 40.0) {
      // Temperatura BAIXA: liga aquecedor e desliga alarme
      analogWrite(ledAquecedor, 255); // 100% de potência
      digitalWrite(ledAlarme, LOW);
    }
    else {
      // Faixa segura: Alarme desligado, aquecedor mantém estado
      digitalWrite(ledAlarme, LOW);
    }

    // Monitoramento
    Serial.print("Nivel: "); Serial.print(nivelPorcentagem);
    Serial.print("% | Temp: "); Serial.print(temperatura);
    Serial.println(" C");

  } else {
    // SISTEMA DESABILITADO: Desliga tudo por segurança
    digitalWrite(ledValvula, LOW);
    analogWrite(ledAquecedor, 0);
    digitalWrite(ledAlarme, LOW);
  }

  delay(200);
}