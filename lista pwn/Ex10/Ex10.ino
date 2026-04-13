const int botaoA = 2;
const int led1 = 3;
const int led2 = 4;
unsigned long tempoApertado = 0;
unsigned long tempoSolto = 0;
unsigned long duracao = 0;
bool pressionado = false;

void setup() {
  Serial.begin(9600);
  pinMode(botaoA, INPUT_PULLUP); 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  int estadoBotao = digitalRead(botaoA);
  unsigned long atualMillis = millis();

 
  if (estadoBotao == LOW && !pressionado) {
    tempoApertado = atualMillis;
    pressionado = true;
    
    
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }

  
  if (estadoBotao == HIGH && pressionado) {
    tempoSolto = atualMillis;
    pressionado = false;
    
    
    duracao = tempoSolto - tempoApertado;
    
    Serial.print("Duração do clique: ");
    Serial.print(duracao);
    Serial.println(" ms");

    
    if (duracao > 2000) {
     
      digitalWrite(led2, HIGH);
      digitalWrite(led1, LOW);
    } 
    else if (duracao < 1000 && duracao > 50) { 

      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
    }
  }
}