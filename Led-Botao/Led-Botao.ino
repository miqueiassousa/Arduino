const int ledPin = A5;     // Pino do LED
const int botaoPin = 8;   // Pino do botão
int estadoBotao = 0;      // Variável para armazenar o estado do botão

void setup() {
    pinMode(ledPin, OUTPUT);   // Define o LED como saída
    pinMode(botaoPin, INPUT);  // Define o botão como entrada
}

void loop() {
    estadoBotao = digitalRead(botaoPin); // Lê o estado do botão
    
    if (estadoBotao == HIGH) { 
        digitalWrite(ledPin, HIGH); // Acende o LED se o botão for pressionado
    } else {
        digitalWrite(ledPin, LOW);  // Apaga o LED se soltar o botão
    }
}