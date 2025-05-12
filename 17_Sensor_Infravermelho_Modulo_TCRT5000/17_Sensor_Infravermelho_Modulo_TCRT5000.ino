#define sensorLinha 11  // Substitua pelo pino onde o sensor está conectado

void setup() {
  pinMode(sensorLinha, INPUT);
  Serial.begin(9600); // Inicializa a comunicação serial
}

void loop() {
  int leitura = digitalRead(sensorLinha); // Lê o sensor (0 ou 1)
  Serial.println(leitura);               // Exibe no monitor serial
  delay(200);                            // Aguarda um pouco entre leituras
}
