const int ledEsteira = 2; 
const int botaoA = 12;    
const int botaoB = 13;    
int contaLote = 0;  
int totalCaixas = 0; 
unsigned long tempoParada = 0;
bool esteiraLigada = false;
bool bloqueioLote = false;
bool bloqueioTotal = false; 


bool botaoB_ant = HIGH;

void setup() {
  pinMode(ledEsteira, OUTPUT);
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(botaoB, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  unsigned long agora = millis();
  bool leituraB = digitalRead(botaoB);

  
  if (digitalRead(botaoA) == LOW) {
    if (bloqueioTotal) {
      
      totalCaixas = 0;
      contaLote = 0;
      bloqueioTotal = false;
      Serial.println("Sistema Resetado!");
    }
    esteiraLigada = true;
  }

  
  if (esteiraLigada && !bloqueioLote && !bloqueioTotal) {
    if (leituraB == LOW && botaoB_ant == HIGH) {
      contaLote++;
      totalCaixas++;
      Serial.print("Caixa detectada! Lote: ");
      Serial.print(contaLote);
      Serial.print(" | Total: ");
      Serial.println(totalCaixas);
      delay(50); 
    }
  }
  botaoB_ant = leituraB; 
  if (contaLote >= 5 && !bloqueioLote) {
    esteiraLigada = false;
    bloqueioLote = true;
    tempoParada = agora;
    contaLote = 0; 
    Serial.println("Lote completo! Empurrando...");
  }

  
  if (bloqueioLote && !bloqueioTotal) {
    if (agora - tempoParada >= 3000) {
      bloqueioLote = false;
      esteiraLigada = true;
      Serial.println("Esteira retomada.");
    }
  }
  if (totalCaixas >= 20) {
    esteiraLigada = false;
    bloqueioTotal = true;
    if (leituraB == LOW && botaoB_ant == HIGH) {
       Serial.println("Capacidade Máxima Atingida! Aguardando Reset.");
    }
  }

  if (esteiraLigada) {
    digitalWrite(ledEsteira, HIGH);
  } else {
    digitalWrite(ledEsteira, LOW);
  }
}