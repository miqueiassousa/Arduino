// Projeto 1 - LED piscante
int ledPin = 11; // Pino no Arduino

void setup() { // Executada somente uma vez no início do programa
  pinMode(ledPin, OUTPUT); // Definir o mododo pino como Saída (Output)
}

void loop() { // Executa continuamente enquanto o Arduino estiver ligado
  digitalWrite(ledPin, HIGH); //HIGH Envia 5 volts pro pino 10
  delay(1000);
  digitalWrite(ledPin, LOW); // LOW, o pino se torna 0 volt, ou terra
  delay(1000);
}

/*
  Resistores diminui a voltagem ou a corrente para outros dispositivos.

  O pino digital 10 está emitindo 5 V de corrente contínua a 40 mA (miliampères;
  amperagem de acordo com o datasheet1 da Atmega), e seu LED requer (de acordo
  com o datasheet) uma voltagem de 2 V e uma corrente de 35 mA. Portanto, você
  necessita de um resistor que reduza os 5 V para 2 V, e a corrente de 40 mA para 35
  mA, caso queira exibir o LED com brilho máximo. Se você deseja um LED de menor
  luminosidade, pode utilizar um valor mais alto de resistência.

  Calculo para descobrir quando o LED precisa para ser ligado

  R = (5v - 2v) / 0.0035 (5v: Voltagem do Arduino | 2v: Voltagem do Led | 0.0035 mA: Corrente do Led)
  Vai dar o valor de 85,71
  Nesse caso o resistor tem que acimca desse valor, o padrão é de 100 Ω.

*/

