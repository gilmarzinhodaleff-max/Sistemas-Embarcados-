const int led1 = 3;      
const int botaoA = 2; 


int nivelBrilho = 0;     
int valorPWM = 0;        


unsigned long ultimoTempoDebounce = 0;
const long tempoDebounce = 50; 
int ultimoEstadoBotao = HIGH;  

void setup() {
  pinMode(led1, OUTPUT);
 
  pinMode(botaoA, INPUT_PULLUP);
  
 
  analogWrite(led1, 0);
}

void loop() {
  int leitura = digitalRead(botaoA);
  unsigned long tempoAtual = millis();

  
  if (leitura != ultimoEstadoBotao) {
   
    if ((tempoAtual - ultimoTempoDebounce) > tempoDebounce) {
      
      
      if (leitura == LOW) {
        nivelBrilho++; 

        
        if (nivelBrilho > 4) {
          nivelBrilho = 0;
        }

       
        valorPWM = nivelBrilho * 63.75; 
        
        analogWrite(led1, valorPWM);
      }
       
      ultimoTempoDebounce = tempoAtual;
    }
  }

  ultimoEstadoBotao = leitura;
}