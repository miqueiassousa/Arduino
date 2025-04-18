#include <AFMotor.h>

const int ledPin = A1;     // Pino do LED
const int interuptor = 8;  // Pino do botão
int estadoBotao = 0;       // Variável para armazenar o estado do botão

// Define os pinos dos LEDs RGB
const int redPin = A2;    // Pino do vermelho (red)
const int bluePin = A3;   // Pino do azul (blue)
const int greenPin = A4;  // Pino do verde (green)

bool farolLigado = false;  // Variável para controlar o estado do farol (ligado/desligado)

char command;  // Variável para armazenar o comando recebido via Bluetooth

void setup() {  
  Serial.begin(9600);  // Inicializa a comunicação serial com taxa de 9600 bauds

  pinMode(ledPin, OUTPUT);     // Define o LED como saída
  pinMode(interuptor, INPUT);  // Define o botão como entrada

  // Configuração do Led
  pinMode(redPin, OUTPUT);    // Configura o pino do vermelho como saída
  pinMode(bluePin, OUTPUT);   // Configura o pino do azul como saída
  pinMode(greenPin, OUTPUT);  // Configura o pino do verde como saída
}

void ligarFarol() {
  analogWrite(redPin, 255);    // Vermelho no máximo
  analogWrite(greenPin, 255);  // Verde no máximo
  analogWrite(bluePin, 255);   // Azul no máximo
}

void desligarFarol() {
  analogWrite(redPin, 0);    // Vermelho no máximo
  analogWrite(greenPin, 0);  // Verde no máximo
  analogWrite(bluePin, 0);   // Azul no máximo
}


void freioLigado() {
  digitalWrite(ledPin, HIGH);  // Acende o LED se o botão for pressionado
}

void freioDesligado() {
  digitalWrite(ledPin, LOW);  // Acende o LED se o botão for pressionado
}

void modoAutomatico() {
  int x = 0;
  while (x < 70) {
    
    estadoBotao = digitalRead(interuptor);  // Atualiza o estado do botão

    if (estadoBotao != 0) {
      freioLigado();
      delay(500);
      freioDesligado();
      delay(500);
      x++;
    }else{
      return;
    }
  }
}

void modoBluetooth() {
  freioDesligado();
  if (Serial.available() > 0) {
    command = Serial.read();  // Lê o comando recebido


    // Executa o comando recebido
    switch (command) {
      case 'X':                      // Liga/desliga o farol (comando personalizado)
        farolLigado = !farolLigado;  // Alterna o estado do farol
        if (farolLigado) {
          ligarFarol();  // Liga o farol
        } else {
          desligarFarol();  // Desliga o farol
        }
        break;
    }
  }
}

void loop() {
  estadoBotao = digitalRead(interuptor);  // Lê o estado do botão

  if (estadoBotao == 0) {
    modoBluetooth();
  } else {
    modoAutomatico();
  }
}