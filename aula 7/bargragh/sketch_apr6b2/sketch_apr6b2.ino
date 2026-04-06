int pin_sensor = A0;
int valor_sensor = 0;
const int pin_led_1 = 11;			
const int pin_led_2 = 10;			
const int pin_led_3 = 9;			


void setup() {
 pinMode(pin_sensor, INPUT);
 pinMode(pin_led_1, OUTPUT);		
 pinMode(pin_led_2, OUTPUT);			
 pinMode(pin_led_3, OUTPUT);	
 Serial.begin(115200);

}

void loop() {
  valor_sensor = analogRead(pin_sensor);
  float valor_tensao = (valor_sensor * 5.0)/1023;
  Serial.print("valor tensao =");
  Serial.println(valor_tensao);
  if (valor_tensao >=4){
    digitalWrite(pin_led_1, 1);
    digitalWrite(pin_led_2, 1);
    digitalWrite(pin_led_3, 1);
  }
  else if (valor_tensao >=3) {
     digitalWrite(pin_led_1, 0);
     digitalWrite(pin_led_2, 0);
     digitalWrite(pin_led_3, 1);
  }
  else if (valor_tensao >=2) {
     digitalWrite(pin_led_1, 0);
     digitalWrite(pin_led_2, 1);
     digitalWrite(pin_led_3, 0);
  }
  else if (valor_tensao >=1) {
     digitalWrite(pin_led_1, 1);
     digitalWrite(pin_led_2, 0);
     digitalWrite(pin_led_3, 0);
  }
  else {
     digitalWrite(pin_led_1, 0);
     digitalWrite(pin_led_2, 0);
     digitalWrite(pin_led_3, 0);
  }
}
