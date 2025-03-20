// Definindo os pinos do sensor
const int trigPin = 9;
const int echoPin = 10;

void setup() {
  // Inicializando a comunicação serial
  Serial.begin(9600);
  
  // Configurando os pinos
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Limpa o pino trig
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Envia um pulso de 10 microssegundos no pino trig
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Lê o tempo de retorno do pulso no pino echo
  long duration = pulseIn(echoPin, HIGH);
  
  // Calcula a distância em centímetros
  // A velocidade do som é de 343 m/s ou 0.0343 cm/μs
  // A distância é o tempo de ida e volta, então dividimos por 2
  float distance = duration * 0.0343 / 2;
  
  // Exibe a distância no monitor serial
  Serial.print("Distância: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Aguarda um pouco antes de fazer a próxima leitura
  delay(500);
}