#define ledR 8 // Cada um dos Led que são os pinose
#define ledG 9
#define ledB 10

void vermelho() {
  digitalWrite(ledR, HIGH);  // Acende vermelho
  digitalWrite(ledG, LOW);   // Apaga azul
  digitalWrite(ledB, LOW);   // Apaga verde 
}

void azul() {
  digitalWrite(ledR, LOW);
  digitalWrite(ledG, LOW);  
  digitalWrite(ledB, HIGH); // Acende azul
}

void verde() {
  digitalWrite(ledR, LOW);
  digitalWrite(ledG, HIGH); // Acende verde
  digitalWrite(ledB, LOW); 
}

void amarelo() {
  digitalWrite(ledR, HIGH);  // Acende vermelho
  digitalWrite(ledG, HIGH);  // Acende verde
  digitalWrite(ledB, LOW);   // Apaga azul
}

void branco() {
  digitalWrite(ledR, HIGH);  // Acende vermelho
  digitalWrite(ledG, HIGH);  // Acende verde
  digitalWrite(ledB, HIGH);  // Acende azul
}

void magenta() {
  digitalWrite(ledR, HIGH);  // Acende vermelho
  digitalWrite(ledG, LOW);   // Apaga verde
  digitalWrite(ledB, HIGH);  // Acende azul
}

void ciano() {
  digitalWrite(ledR, LOW);   // Apaga vermelho
  digitalWrite(ledG, HIGH);  // Acende verde
  digitalWrite(ledB, HIGH);  // Acende azul
}


void setup(){
  pinMode(ledR, OUTPUT);  
  pinMode(ledG, OUTPUT);  
  pinMode(ledB, OUTPUT);
}

void loop(){

  vermelho();
  delay(500);

  azul();
  delay(500);

   verde();
  delay(500);

  magenta();
  delay(500);

  branco();
  delay(500);

  amarelo();
  delay(500);

  ciano();
  delay(500);

}