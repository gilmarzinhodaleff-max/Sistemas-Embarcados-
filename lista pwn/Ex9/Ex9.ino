const int led1 = 3; 
const int led2 = 5;
const int pinoPot = A0;
unsigned long anteriorMillis = 0;
const long intervaloLeitura = 30; 

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  analogWrite(led1, 0);
  analogWrite(led2, 0);
}

void loop() {
  unsigned long atualMillis = millis();

  if (atualMillis - anteriorMillis >= intervaloLeitura) {
    anteriorMillis = atualMillis;

    int leitura = analogRead(pinoPot);

   
    if (leitura < 512) {
      
      int brilho1 = map(leitura, 512, 0, 0, 255);
      analogWrite(led1, brilho1);
      analogWrite(led2, 0);
    } 
    
    else if (leitura > 512) {
     
      int brilho2 = map(leitura, 512, 1023, 0, 255);
      analogWrite(led2, brilho2);
      analogWrite(led1, 0); 
    } 
    
    else {
      analogWrite(led1, 0);
      analogWrite(led2, 0);
    }
  }
}