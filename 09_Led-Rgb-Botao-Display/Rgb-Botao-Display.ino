#include <LiquidCrystal.h>

// Ligações do Arduino
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define ledR 8
#define ledB 9
#define ledG 10
#define maximo 7
#define botao 1

int btnclicado = 0;
int btnliberado = 0;
int ciclo = 0;

void vermelho() {
  digitalWrite(ledR, 1);
  digitalWrite(ledB, 0);
  digitalWrite(ledG, 0);
}

void azul() {
  digitalWrite(ledR, 0);
  digitalWrite(ledB, 1);
  digitalWrite(ledG, 0);
}

void verde() {
  digitalWrite(ledR, 0);
  digitalWrite(ledB, 0);
  digitalWrite(ledG, 1);
}

void amarelo() {
  digitalWrite(ledR, 1);
  digitalWrite(ledB, 0);
  digitalWrite(ledG, 1);
}

void branco() {
  digitalWrite(ledR, 1);
  digitalWrite(ledB, 1);
  digitalWrite(ledG, 1);
}

void magenta() {
  digitalWrite(ledR, 1);
  digitalWrite(ledB, 1);
  digitalWrite(ledG, 0);
}

void ciano() {
  digitalWrite(ledR, 0);
  digitalWrite(ledB, 1);
  digitalWrite(ledG, 1);
}


int nomeDisplay(int x) {
  switch (x) {
    case 0:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Vermelho");
      break;
    case 1:
      // Código a ser executado se a expressão for igual a valor2
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Azul");
      break;
    case 2:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Verde");
      break;
    case 3:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Amarelo");
      break;
    case 4:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Branco");
      break;
    case 5:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Magenta");
      break;
    case 6:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Ciano");
      break;
    default:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Aperte o Botão");
      break;
  }
}


void trocaLed() {
  if (ciclo == 0) {
    vermelho();
    nomeDisplay(ciclo);
  } else if (ciclo == 1) {
    azul();
    nomeDisplay(ciclo);
  } else if (ciclo == 2) {
    verde();
    nomeDisplay(ciclo);
  } else if (ciclo == 3) {
    amarelo();
    nomeDisplay(ciclo);

  } else if (ciclo == 4) {
    branco();
    nomeDisplay(ciclo);

  } else if (ciclo == 5) {
    magenta();
    nomeDisplay(ciclo);

  } else if (ciclo == 6) {
    ciano();
    nomeDisplay(ciclo);
  }

  ciclo++;
  if (ciclo > maximo - 1) {
    ciclo = 0;
  }
}

void checabtn() {
  if (digitalRead(botao) == HIGH) {
    btnclicado = 1;
    btnliberado = 0;
  } else {
    btnliberado = 1;
  }
  if ((btnclicado == 1 and btnliberado == 1)) {
    btnclicado = 0;
    btnliberado = 0;
    trocaLed();
  }
}

void setup() {

  lcd.begin(16, 2);  // Aqui informo que são 16 caracteres e 2 linhas

  pinMode(ledR, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(botao, INPUT);
}

void loop() {
  static bool mensagemExibida = false;  // Variável para garantir que a mensagem inicial só aparece uma vez

  if (!mensagemExibida) {
    lcd.setCursor(0, 0);
    lcd.print("Seja Bem Vindo");
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("Aperte o botao");
    mensagemExibida = true; // Marca que a mensagem foi exibida
  }

  checabtn();  // Função que verifica o botão e exibe a cor
}




