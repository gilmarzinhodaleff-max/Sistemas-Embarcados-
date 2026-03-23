/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Botão com Pull-up e envio serial

Autor: Marcos Antonio Jeremias Coelho
Data: 06/03/2023
Versão: 1.0

************************************************************************ */

const int pin_botaoA = 2;
const int pin_botaoB = 3;

bool botaoA = false;
bool botaoB = false;

void setup() {
  pinMode(pin_botaoA, INPUT_PULLUP);
  pinMode(pin_botaoB, INPUT_PULLUP);
  Serial.begin(115200);  // Definição da velocide de transmissão em 115200 bps
}
void loop() {
  botaoA = digitalRead(pin_botaoA);  //
  botaoB = digitalRead(pin_botaoB);
  if (botaoA == 0 && botaoB) {
    digitalWrite();
  } 
  else
    digitalWrite();
  
