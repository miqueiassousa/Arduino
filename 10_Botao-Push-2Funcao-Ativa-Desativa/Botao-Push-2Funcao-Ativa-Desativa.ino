// #define ledBluetooth A1
#define ledDemo A5
#define botaoUm 8


int estadoLED = LOW;  // Estado atual do LED
int btnAnterior = LOW;  // Estado anterior do botão
int btnAtual = LOW;  // Estado atual do botão
bool executarFuncaoUm = true;  // Controla qual função deve ser executada

void setup() {
  pinMode(botaoUm, INPUT);
  
  // pinMode(ledBluetooth, INPUT);
  pinMode(ledDemo, OUTPUT);
  
  //digitalWrite(led, estadoLED);  // Inicializa o LED com o estado desligado
}

void loop() {
  btnAtual = digitalRead(botaoUm);  // Lê o estado atual do botão

  // Verifica se o botão foi pressionado (transição de LOW para HIGH)
  if (btnAnterior == LOW && btnAtual == HIGH) {
    if (executarFuncaoUm) {
      modoBluetooth();  // Executa a função 1
    } else {
      modoDemo();  // Executa a função 2
    }
    executarFuncaoUm = !executarFuncaoUm;  // Alterna entre as funções
  }

  btnAnterior = btnAtual;  // Atualiza o estado anterior do botão
}

void modoBluetooth() {
  // Ação da função 1: liga o LED
 
  // digitalWrite(ledBluetooth, HIGH);
   digitalWrite(ledDemo, LOW);
  Serial.println("Modo Bluetooth Ativado");
}

void modoDemo() {
  // Ação da função 2: desliga o LED
  // digitalWrite(ledBluetooth, LOW);
  digitalWrite(ledDemo, HIGH);
  Serial.println("Modo Demo Ativado");
}