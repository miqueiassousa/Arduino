// Pinos dos motores
#define IN1 7
#define IN2 8
#define IN3 5
#define IN4 6
#define ENA 9   // PWM
#define ENB 10  // PWM

#define velocidade 80

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  analogWrite(ENA, velocidade);
  analogWrite(ENB, velocidade);

  Serial.begin(9600); // Adicione se quiser ver os prints no monitor serial
}

void loop() {

  Serial.println("FRENTE");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(2000);

  Serial.println("VIRANDO PARA DIREITA");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(2000);

  Serial.println("VIRANDO PARA ESQUERDA");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(2000);
}
