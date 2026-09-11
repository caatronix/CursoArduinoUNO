#include <DHT.h>

// Pino do sensor DHT11
#define DHTPIN 2

// Tipo do sensor
#define DHTTYPE DHT11

// Pinos dos LEDs
const int LED_VERDE = 8;
const int LED_AMARELO = 9;
const int LED_VERMELHO = 10;

// Inicializa o sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Define os LEDs como saída
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);

  // Inicia o sensor
  dht.begin();

  // Comunicação com o computador
  Serial.begin(9600);
}

void loop() {

  // Faz a leitura da temperatura
  float temperatura = dht.readTemperature();

  // Verifica se houve erro na leitura
  if (isnan(temperatura)) {
    Serial.println("Erro ao ler o sensor DHT11!");
    return;
  }

  // Mostra a temperatura no Monitor Serial
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  // Apaga todos os LEDs
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERMELHO, LOW);

  // NORMAL
  if (temperatura <= 34) {
    digitalWrite(LED_VERDE, HIGH);
    Serial.println("Status: NORMAL");
  }

  // QUENTE
  else if (temperatura <= 37) {
    digitalWrite(LED_AMARELO, HIGH);
    Serial.println("Status: QUENTE");
  }

  // PERIGO
  else {
    digitalWrite(LED_VERMELHO, HIGH);
    Serial.println("Status: PERIGO");
  }

  // Aguarda 2 segundos antes da próxima leitura
  delay(2000);
}