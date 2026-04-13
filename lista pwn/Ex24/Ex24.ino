const int pinoSensor = A0;
const int pinoVentilador = 3; 
void setup() {
  pinMode(pinoVentilador, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 
  int leitura = analogRead(pinoSensor);
  float voltagem = leitura * (5.0 / 1023.0);
  float temperatura = (voltagem - 0.5) * 100.0;
  int velocidadePWM = map(temperatura, 20, 50, 0, 255);
  velocidadePWM = constrain(velocidadePWM, 0, 255);
  analogWrite(pinoVentilador, velocidadePWM);

  Serial.print("Temp: ");
  Serial.print(temperatura);
  Serial.print(" C | Velocidade PWM: ");
  Serial.println(velocidadePWM);

  delay(200);
