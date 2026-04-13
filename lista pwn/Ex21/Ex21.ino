const int pinoLDR = A0;   
const int ledLuz = 3;     
const int botaoA = 12;    

void setup() {
  pinMode(ledLuz, OUTPUT);
  pinMode(botaoA, INPUT_PULLUP);
  Serial.begin(9600);
}
void loop() {
  int leituraLDR = analogRead(pinoLDR);
  bool ocupado = !digitalRead(botaoA); 
  int brilhoLED = 0;
  if (ocupado) {
    brilhoLED = map(leituraLDR, 0, 1023, 255, 0);
  } 
  else {
    brilhoLED = 25; 
  }
  analogWrite(ledLuz, brilhoLED);
  Serial.print("Luz Natural: ");
  Serial.print(leituraLDR);
  Serial.print(" | Brilho LED: ");
  Serial.print((brilhoLED * 100) / 255);
  Serial.println("%");
  delay(100);
}