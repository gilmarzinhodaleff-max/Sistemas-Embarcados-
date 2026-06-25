Controle automático de uma planta de nível Programe um Arduino para controlar uma planta de nível.
 Esta planta de nível têm as seguintes característica: • Uma entrada de líquido controlada por uma eletroválvula, caso nível lógico 0 não passa líquido, 
 caso nível lógico 1 passa líquido. • Uma saída de líquido controlada por uma eletroválvula, caso nível lógico 0 não passa líquido,
  caso nível lógico 1 passa líquido. A saída do líquido só é permitida na seguinte condição:
   ◦ Caso o tanque esteja com mais de 40 % de sua capacidade preenchida e a temperatura esteja correta, entre 25 e 27 ºC. 
   • Para medição do nível do tanque é utilizado um sensor ultrassônico no topo apontado para baixo.
    O tanque é cilíndrico e tem volume de armazenamento é de 2π metros cúbicos e diâmetro da base de 2 metros •
     A medição de temperatura é realizada por um potenciômetro (0 ºC = 0 V, 50 ºC = 5 V). 
     • O tanque possui um elemento de aquecimento para ajustar a temperatura, caso nível lógico 1 o elemento liga e esquenta o líquido, 
     caso nível lógico 0 desliga. ◦ O elemento de aquecimento não pode ligar caso o tanque esteja com menos de 10 % de líquido.
      • O sistema tem dois alarmes: ◦ O primeiro visual, um LED amarelo indicando que o nível de líquido está abaixo de 20 %; ◦ O segundo, 
      um LED vermelho que indica que o nível de líquido está abaixo de 10 %.
       ◦ Se o segundo alarme só desliga se o operador pressionar o botão A deve ser ligado em uma interrupção
]
const int TRIG = 9;
const int ECHO = 10;

const int TEMP_PIN = A0;

const int VALVULA_ENTRADA = 3;
const int VALVULA_SAIDA   = 4;
const int AQUECEDOR       = 5;

const int LED_AMARELO = 6;
const int LED_VERMELHO = 7;

const int BOTAO = 2; // interrupção externa

// ----------------------
// VARIÁVEIS
// ----------------------
volatile bool resetAlarme = false;

bool alarmeCriticoTravado = false;

float temperatura = 0;
float nivelPercentual = 0;

// tanque altura = 2 m = 200 cm
const float ALTURA_TANQUE = 200.0;

// ----------------------
// INTERRUPÇÃO
// ----------------------
void ISR_ResetAlarme()
{
    resetAlarme = true;
}

// ----------------------
// SETUP
// ----------------------
void setup()
{
    Serial.begin(9600);

    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);

    pinMode(VALVULA_ENTRADA, OUTPUT);
    pinMode(VALVULA_SAIDA, OUTPUT);
    pinMode(AQUECEDOR, OUTPUT);

    pinMode(LED_AMARELO, OUTPUT);
    pinMode(LED_VERMELHO, OUTPUT);

    pinMode(BOTAO, INPUT_PULLUP);

    attachInterrupt(
        digitalPinToInterrupt(BOTAO),
        ISR_ResetAlarme,
        FALLING
    );
}

// ----------------------
// LEITURA ULTRASSÔNICO
// ----------------------
float lerNivel()
{
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);

    digitalWrite(TRIG, LOW);

    long tempo = pulseIn(ECHO, HIGH, 30000);

    float distancia =
        tempo * 0.0343 / 2.0;

    float alturaLiquido =
        ALTURA_TANQUE - distancia;

    if (alturaLiquido < 0)
        alturaLiquido = 0;

    if (alturaLiquido > ALTURA_TANQUE)
        alturaLiquido = ALTURA_TANQUE;

    return (alturaLiquido / ALTURA_TANQUE) * 100.0;
}

// ----------------------
// LOOP
// ----------------------
void loop()
{
    static unsigned long ultimaLeitura = 0;

    if (millis() - ultimaLeitura >= 200)
    {
        ultimaLeitura = millis();

        // -------------------
        // TEMPERATURA
        // -------------------
        int adc = analogRead(TEMP_PIN);

        temperatura =
            map(adc, 0, 1023, 0, 500) / 10.0;

        // -------------------
        // NÍVEL
        // -------------------
        nivelPercentual = lerNivel();

        // -------------------
        // ALARME AMARELO
        // -------------------
        digitalWrite(
            LED_AMARELO,
            nivelPercentual < 20
        );

        // -------------------
        // ALARME VERMELHO
        // -------------------
        if (nivelPercentual < 10)
        {
            alarmeCriticoTravado = true;
        }

        if (resetAlarme)
        {
            resetAlarme = false;

            if (nivelPercentual >= 10)
            {
                alarmeCriticoTravado = false;
            }
        }

        digitalWrite(
            LED_VERMELHO,
            alarmeCriticoTravado
        );

        // -------------------
        // VÁLVULA DE ENTRADA
        // -------------------
        if (nivelPercentual < 80)
        {
            digitalWrite(
                VALVULA_ENTRADA,
                HIGH
            );
        }
        else
        {
            digitalWrite(
                VALVULA_ENTRADA,
                LOW
            );
        }

        // -------------------
        // CONTROLE TEMPERATURA
        // -------------------
        if (nivelPercentual >= 10)
        {
            if (temperatura < 25)
            {
                digitalWrite(
                    AQUECEDOR,
                    HIGH
                );
            }
            else
            {
                digitalWrite(
                    AQUECEDOR,
                    LOW
                );
            }
        }
        else
        {
            digitalWrite(
                AQUECEDOR,
                LOW
            );
        }

        // -------------------
        // VÁLVULA DE SAÍDA
        // -------------------
        bool nivelOK =
            nivelPercentual > 40;

        bool tempOK =
            temperatura >= 25 &&
            temperatura <= 27;

        if (nivelOK && tempOK)
        {
            digitalWrite(
                VALVULA_SAIDA,
                HIGH
            );
        }
        else
        {
            digitalWrite(
                VALVULA_SAIDA,
                LOW
            );
        }

        // -------------------
        // MONITOR SERIAL
        // -------------------
        Serial.print("Nivel: ");
        Serial.print(nivelPercentual);
        Serial.print("% ");

        Serial.print(" Temp: ");
        Serial.print(temperatura);
        Serial.println(" C");
    }
}