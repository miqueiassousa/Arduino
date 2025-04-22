/*
  A linha if (Serial.available() > 0) { é usada para verificar se há dados disponíveis na 
  comunicação serial, ou seja, se algo foi enviado para o Arduino via porta serial. 
  Aqui está o que acontece: 
    - Serial.available() retorna o número de bytes (caracteres) que foram recebidos e estão
    disponíveis para leitura.
    - > 0 garante que apenas quando houver pelo menos um byte recebido, o código dentro do 
    if será executado.
*/


void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {  // Verifica se há dados na porta serial
    char dadoRecebido = Serial.read();  // Lê o dado recebido
    Serial.print("Você digitou: ");
    Serial.println(dadoRecebido);  // Exibe o dado recebido
  }
}