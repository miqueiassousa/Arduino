#include <Servo.h>

Servo meuServo; // cria o objeto do servo

void setup() {
  meuServo.attach(9); // pino 9 conectado ao fio de sinal do servo
}

void loop() {
  // meuServo.write(90); // coloca o servo no meio (90 graus)
  // delay(1000);
  meuServo.write(90); // gira para 0 graus
  delay(1000);
  // meuServo.write(180); // gira para 180 graus
  // delay(1000);
}
