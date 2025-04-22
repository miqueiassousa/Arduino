// Motor A
#define IN1 5
#define IN2 6
#define ENA 3

// Motor B
#define IN3 9
#define IN4 8
#define ENB 10

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  Serial.println("Motor A frente");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 200);  // Velocidade (0–255)

  delay(2000);

  Serial.println("Motor A trás");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(2000);

  Serial.println("Parar Motor A");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(1000);

  Serial.println("Motor B frente");
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 200);
  delay(2000);

  Serial.println("Motor B trás");
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(2000);

  Serial.println("Parar Motor B");
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(1000);
}
