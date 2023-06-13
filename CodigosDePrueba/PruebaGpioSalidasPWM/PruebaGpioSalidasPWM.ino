#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

#define PULSO_PWM 200
#define FRECUENCIA_PWM 1000
#define RESOLUCION_PWM 8
#define CANAL_PWM_A 0
#define CANAL_PWM_B 1
#define CANAL_PWM_C 2
#define CANAL_PWM_D 3
#define PIN_PWM_A 27
#define PIN_PWM_B 26
#define PIN_PWM_C 25
#define PIN_PWM_D 33
int pwmA = 200;
int pwmB = 200;
int pwmC = 200;
int pwmD = 200;


void setup() {
  Serial.begin(115200); 
  SerialBT.begin("ESP32_BT");

  pinMode(PIN_PWM_A, OUTPUT);
  pinMode(PIN_PWM_B, OUTPUT);
  pinMode(PIN_PWM_B, OUTPUT);
  pinMode(PIN_PWM_B, OUTPUT);

  ledcSetup(CANAL_PWM_A, FRECUENCIA_PWM, RESOLUCION_PWM);
  ledcSetup(CANAL_PWM_B, FRECUENCIA_PWM, RESOLUCION_PWM);
  ledcSetup(CANAL_PWM_C, FRECUENCIA_PWM, RESOLUCION_PWM);
  ledcSetup(CANAL_PWM_D, FRECUENCIA_PWM, RESOLUCION_PWM);

  ledcAttachPin(PIN_PWM_A, CANAL_PWM_A);
  ledcAttachPin(PIN_PWM_B, CANAL_PWM_B);
  ledcAttachPin(PIN_PWM_C, CANAL_PWM_C);
  ledcAttachPin(PIN_PWM_D, CANAL_PWM_D);
}

void loop() {
  if (SerialBT.available())
  {
    SerialBT.println("Seleccione el canal PWM a modificar(1/2/3/4): ");
    int option = SerialBT.read();
    SerialBT.println("Seleccione el nuevo PWM del canal(0-255): ");
    int newPwm = SerialBT.read();

    if(newPwm > 255) newPwm = 255;

    if(option == 1) pwmA = newPwm;
    if(option == 2) pwmB = newPwm;
    if(option == 3) pwmC = newPwm;
    if(option == 4) pwmD = newPwm;

  }

  Serial.println(pwmA);
  Serial.println(pwmB);
  Serial.println(pwmC);
  Serial.println(pwmD);
  //ledcWrite(CANAL_PWM_A, pwmA);
  //ledcWrite(CANAL_PWM_B, pwmB);
  //ledcWrite(CANAL_PWM_C, pwmC);
  //ledcWrite(CANAL_PWM_D, pwmD);
  
}
