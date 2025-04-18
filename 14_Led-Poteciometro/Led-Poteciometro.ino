// Definir el pin al que está conectado el LED y el potenciómetro
const int ledPin = 2;     // Pin PWM para el LED
const int potPin = A5;    // Pin analógico para el potenciómetro

void setup() {
  // Configuramos el pin del LED como salida
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Leemos el valor del potenciómetro (0 a 1023)
  int potValue = analogRead(potPin);
  
  // Mapeamos el valor del potenciómetro (0-1023) a un valor PWM (0-255)
  int brightness = map(potValue, 0, 1023, 0, 255);
  
  // Ajustamos el brillo del LED usando PWM
  analogWrite(ledPin, brightness);
  
  // Pequeña pausa para estabilidad
  delay(10);
}
