#include <WiFi.h>
#include <BluetoothSerial.h>

const char* ssid = "nombre_de_red";
const char* password = "contraseña_de_red";

const int ledPin = 2; // Pin del LED

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // Iniciar la conexión Bluetooth
  SerialBT.begin("ESP32_BT"); // Nombre del dispositivo Bluetooth

  // Conectar a la red Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }

  Serial.println("Conexión WiFi establecida");
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (SerialBT.available()) {
    char data = SerialBT.read();

    if (data == '1') {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED encendido");
    } else if (data == '0') {
      digitalWrite(ledPin, LOW);
      Serial.println("LED apagado");
    }
  }
}