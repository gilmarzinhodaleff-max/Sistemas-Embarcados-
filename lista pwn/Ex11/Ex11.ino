const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int botao1 = 12; 
const int botao2 = 13; 


unsigned long anteriorMillis = 0;
const long intervalo = 1000; 
int ledligado = 0;              // Guarda qual o próximo LED que deve acender (de 0 a 4)
bool acontecendo = false;      // Diz se a sequência está rodando ou se está parada

void setup() {
  pinMode(led1, OUTPUT);      
  pinMode(led2, OUTPUT);       
  pinMode(led3, OUTPUT);       
  pinMode(led4, OUTPUT);       
  
  pinMode(botao1, INPUT_PULLUP); 
  pinMode(botao2, INPUT_PULLUP); 
}

void loop() {
  unsigned long atualMillis = millis(); 

 
  if (digitalRead(botao1) == LOW && !acontecendo && ledligado == 0) { // Se apertar o botão, não estiver rodando e estiver no início
    acontecendo = true;           // Sequência começou
    anteriorMillis = atualMillis; // Salva o tempo exato em que a sequência deu o primeiro passo
    ledligado = 1;                 // Próximo passo é o número 1
    digitalWrite(led1, HIGH);     
  }

  
  if (digitalRead(botao2) == LOW) { 
    digitalWrite(led1, LOW);      
    digitalWrite(led2, LOW);      
    digitalWrite(led3, LOW);     
    digitalWrite(led4, LOW);     
    acontecendo = false;          // A sequência não está mais rodando
    ledligado = 0;                 // Reseta a contagem para começar do zero na próxima vez
  }

  
  if (acontecendo) { // Se a sequência estiver ativa 
    if (atualMillis - anteriorMillis >= intervalo) { 
      anteriorMillis = atualMillis; // 
      
      ledligado++; 

      if (ledligado == 2) {
        digitalWrite(led2, HIGH); 
      }
        
      if (ledligado == 3) {
        digitalWrite(led3, HIGH);
      } 
      if (ledligado == 4) {                         
        digitalWrite(led4, HIGH);                  
        acontecendo = false;                       
      }
    }
  }
}