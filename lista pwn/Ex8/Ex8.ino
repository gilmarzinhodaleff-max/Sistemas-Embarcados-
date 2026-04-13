const int pinoPot = A0;
const int led3 = 4;
int leiturasFeitas = 0;       
long somaLeituras = 0;        
int mediaFinal = 0;           
unsigned long anteriorMillis = 0;
const long intervaloAmostra = 20; 
void setup() {
  Serial.begin(9600);
  pinMode(led3, OUTPUT);
}

void loop() {
  unsigned long atualMillis = millis();

  
  if (leiturasFeitas < 10) {
    if (atualMillis - anteriorMillis >= intervaloAmostra) {
      anteriorMillis = atualMillis;

      int leituraAtual = analogRead(pinoPot);
      somaLeituras += leituraAtual; 
      leiturasFeitas++;             
    }
  } 
  else {
    mediaFinal = somaLeituras / 10;

    
    Serial.print("Média das 10 leituras: ");
    Serial.println(mediaFinal);

    
    if (mediaFinal > 700) {
      digitalWrite(led3, HIGH);
    } else {
      digitalWrite(led3, LOW);
    }

    
    leiturasFeitas = 0;
    somaLeituras = 0;
  }
}