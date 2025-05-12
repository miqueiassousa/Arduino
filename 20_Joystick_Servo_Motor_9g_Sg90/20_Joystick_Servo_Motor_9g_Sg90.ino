#include <Servo.h>

Servo meuServo; // Cria um objeto Servo

// Pinos dos dois joysticks
const int pinoJoystick1X = A2;  // Joystick 1 no eixo X (A2)
const int pinoJoystick1Y = A3;  // Joystick 1 no eixo Y (A3)
const int pinoJoystick2X = A4;  // Joystick 2 no eixo X (A4)
const int pinoJoystick2Y = A5;  // Joystick 2 no eixo Y (A5)

// Variáveis para armazenar as leituras dos joysticks
int leituraJoystick1X;
int leituraJoystick1Y;
int leituraJoystick2X;
int leituraJoystick2Y;

void setup() {
  Serial.begin(9600); // Inicia a comunicação serial
  meuServo.attach(9); // Conecta o servo ao pino digital 9
}

void loop() {
  // Lê os valores dos dois joysticks
  leituraJoystick1X = analogRead(pinoJoystick1X); // Lê o VRx do joystick 1
  leituraJoystick1Y = analogRead(pinoJoystick1Y); // Lê o VRy do joystick 1
  leituraJoystick2X = analogRead(pinoJoystick2X); // Lê o VRx do joystick 2
  leituraJoystick2Y = analogRead(pinoJoystick2Y); // Lê o VRy do joystick 2
  
  // Exibe os valores dos dois joysticks no Monitor Serial
  Serial.print("Joystick 1 - VRx: ");
  Serial.print(leituraJoystick1X);
  Serial.print("  VRy: ");
  Serial.println(leituraJoystick1Y);
  
  Serial.print("Joystick 2 - VRx: ");
  Serial.print(leituraJoystick2X);
  Serial.print("  VRy: ");
  Serial.println(leituraJoystick2Y);

  // Mapeia os valores de ambos os joysticks para controlar o servo (0 a 180 graus)
  int anguloServo1 = map(leituraJoystick1X, 0, 1023, 0, 180); // Mapeia o joystick 1
  int anguloServo2 = map(leituraJoystick2X, 0, 1023, 0, 180); // Mapeia o joystick 2
  
  // Calcular a média dos dois joysticks para controlar o servo
  int anguloServo = (anguloServo1 + anguloServo2) / 2; // Média para controlar o servo com base nos dois joysticks
  
  anguloServo = constrain(anguloServo, 0, 180); // Garante que o valor esteja entre 0 e 180 graus
  meuServo.write(anguloServo); // Envia o valor mapeado para o servo motor

  delay(15); // Pequeno atraso para evitar tremores do servo
}
