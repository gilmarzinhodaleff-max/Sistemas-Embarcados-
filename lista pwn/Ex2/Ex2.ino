const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;

unsigned long anteriorMillis = 0; 
const long intervalo = 200;      
int estado = 0; 

void setup() {
 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  unsigned long atualMillis = millis();

  if (atualMillis - anteriorMillis >= intervalo) {
    anteriorMillis = atualMillis;

    
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);

    
    if (estado == 0) {
      digitalWrite(led1, HIGH);
    } else if (estado == 1) {
      digitalWrite(led2, HIGH);
    } else if (estado == 2) {
      digitalWrite(led3, HIGH);
    } else if (estado == 3) {
      digitalWrite(led4, HIGH);
    }

   
    estado++;

    
    if (estado > 3) {
      estado = 0;
    }
  }
}