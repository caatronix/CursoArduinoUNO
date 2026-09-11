// SEMÁFORO DE TRÂNSITO - ARDUINO UNO
const int LED_VERMELHO = 9;
const int LED_AMARELO  = 10;
const int LED_VERDE    = 11;
void setup() {
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
}
void loop() {
  // 🔴 VERMELHO
  digitalWrite(LED_VERMELHO, HIGH);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERDE, LOW);
  delay(5000);
  // 🟡 AMARELO
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_AMARELO, HIGH);
  digitalWrite(LED_VERDE, LOW);
  delay(2000);
  // 🟢 VERDE
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERDE, HIGH);
  delay(5000);
}