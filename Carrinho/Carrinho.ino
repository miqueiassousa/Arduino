#include <SoftwareSerial.h>
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

// Configuração do SoftwareSerial para o Bluetooth
SoftwareSerial bluetoothSerial(10, 11); // RX no pino 10, TX no pino 11

// Pinos de controle dos motores
int in1 = 5;
int in2 = 6;
int in3 = 9;
int in4 = 10;

void setup() {
  // Configura os pinos dos motores como saída
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Inicializa a comunicação serial para depuração
  Serial.begin(9600);

  // Inicializa a comunicação com o módulo Bluetooth
  bluetoothSerial.begin(9600);

  // Inicializa o Dabble usando o SoftwareSerial
  Dabble.begin(bluetoothSerial);

  Serial.println("Sistema inicializado. Aguardando comandos...");
}

void loop() {
  // Processa os dados recebidos do Dabble
  Dabble.processInput();

  // Verifica os comandos do GamePad
  if (GamePad.isUpPressed()) {
    Serial.println("Movendo para frente");
    moveParaFrente();
  } else if (GamePad.isDownPressed()) {
    Serial.println("Movendo para trás");
    moveParaTras();
  } else if (GamePad.isLeftPressed()) {
    Serial.println("Movendo para esquerda");
    moveParaEsquerda();
  } else if (GamePad.isRightPressed()) {
    Serial.println("Movendo para direita");
    moveParaDireita();
  } else {
    parar();
  }

  // Pequeno delay para evitar leituras muito rápidas
  delay(100);
}

void moveParaFrente() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void moveParaTras() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void moveParaEsquerda() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void moveParaDireita() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void parar() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}