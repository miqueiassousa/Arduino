#include <AFMotor.h> // Inclui a biblioteca AFMotor para controlar os motores

// Inicializa os motores M3 e M4
AF_DCMotor motor3(3, MOTOR34_1KHZ); // Motor M3 no canal 3
AF_DCMotor motor4(4, MOTOR34_1KHZ); // Motor M4 no canal 4

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial com taxa de 9600 bauds
  Serial.println("Iniciando demonstração...");
  demo(); // Chama a função de demonstração
}

void loop() {
  // O loop principal pode ficar vazio ou você pode adicionar outras funcionalidades
}

void demo() {
  Serial.println("Movendo para frente...");
  forward();
  delay(2000); // Move para frente por 2 segundos
  Stop();

  Serial.println("Movendo para trás...");
  back();
  delay(2000); // Move para trás por 2 segundos
  Stop();

  Serial.println("Girando para a esquerda...");
  left();
  delay(1000); // Gira para a esquerda por 1 segundo
  Stop();

  Serial.println("Girando para a direita...");
  right();
  delay(1000); // Gira para a direita por 1 segundo
  Stop();

  Serial.println("Demonstração concluída.");
}

// Função para mover o carro para frente
void forward() {
  Serial.println("Motor 3: Frente, Motor 4: Frente");
  motor3.setSpeed(255); // Define a velocidade máxima para M3
  motor3.run(FORWARD);  // Move M3 para frente
  motor4.setSpeed(255); // Define a velocidade máxima para M4
  motor4.run(FORWARD);  // Move M4 para frente
}

// Função para mover o carro para trás
void back() {
  Serial.println("Motor 3: Trás, Motor 4: Trás");
  motor3.setSpeed(255); // Define a velocidade máxima para M3
  motor3.run(BACKWARD); // Move M3 para trás
  motor4.setSpeed(255); // Define a velocidade máxima para M4
  motor4.run(BACKWARD); // Move M4 para trás
}

// Função para mover o carro para esquerda
void left() {
  Serial.println("Motor 3: Frente, Motor 4: Trás");
  motor3.setSpeed(255); // Define a velocidade máxima para M3
  motor3.run(FORWARD);  // Move M3 para frente
  motor4.setSpeed(255); // Define a velocidade máxima para M4
  motor4.run(BACKWARD); // Move M4 para trás
}

// Função para mover o carro para direita
void right() {
  Serial.println("Motor 3: Trás, Motor 4: Frente");
  motor3.setSpeed(255); // Define a velocidade máxima para M3
  motor3.run(BACKWARD); // Move M3 para trás
  motor4.setSpeed(255); // Define a velocidade máxima para M4
  motor4.run(FORWARD);  // Move M4 para frente
}

// Função para parar os motores
void Stop() {
  Serial.println("Parando motores...");
  motor3.setSpeed(0); // Define a velocidade mínima para M3
  motor3.run(RELEASE); // Para M3
  motor4.setSpeed(0); // Define a velocidade mínima para M4
  motor4.run(RELEASE); // Para M4
}