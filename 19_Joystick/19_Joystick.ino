void setup() {
  Serial.begin(9600); // Inicia a comunicação serial
}

void loop() {
  // Lê os valores dos dois joysticks
  int leituraVRx1 = analogRead(A2); // Lê o VRx do primeiro joystick (pino A2)
  int leituraVRy1 = analogRead(A3); // Lê o VRy do primeiro joystick (pino A3)
  int leituraVRx2 = analogRead(A4); // Lê o VRx do segundo joystick (pino A4)
  int leituraVRy2 = analogRead(A5); // Lê o VRy do segundo joystick (pino A5)
  
  // Exibe os valores dos dois joysticks no Monitor Serial
  Serial.print("Joystick 1 - VRx: ");
  Serial.print(leituraVRx1);
  Serial.print("  VRy: ");
  Serial.println(leituraVRy1);
  
  Serial.print("Joystick 2 - VRx: ");
  Serial.print(leituraVRx2);
  Serial.print("  VRy: ");
  Serial.println(leituraVRy2);
  
  delay(900); // Pequeno atraso para facilitar a leitura
}
