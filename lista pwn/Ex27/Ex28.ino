const int botaoSobe = 12;   
const int botaoDesce = 13;  
const int ledMotor = 3;     
int velocidade = 0;         
const int passo = 25;       

void setup() {
  pinMode(botaoSobe, INPUT_PULLUP);
  pinMode(botaoDesce, INPUT_PULLUP);
  pinMode(ledMotor, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Controle de Velocidade Iniciado");
}

void loop() {
 
  if (digitalRead(botaoSobe) == LOW) {
    velocidade = velocidade + passo;
    
   
    if (velocidade > 255) velocidade = 255;
    
    atualizarMotor();
    delay(200); 
  }

 
  if (digitalRead(botaoDesce) == LOW) {
    velocidade = velocidade - passo;
    
    
    if (velocidade < 0) velocidade = 0;
    
    atualizarMotor();
    delay(200); 
  }
}
void atualizarMotor() {
  analogWrite(ledMotor, velocidade);
  
  int porcentagem = map(velocidade, 0, 255, 0, 100);
  
  Serial.print("Velocidade: ");
  Serial.print(porcentagem);
  Serial.println("%");
}