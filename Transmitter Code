#include <LoRa.h>         // LoRa library
#include <DHT.h>          // DHT11 library

// Sensor pins
#define DHTPIN 2          // DHT11 data pin connected to Arduino pin 2
#define MQ135_PIN A0      // MQ135 sensor analog pin connected to A0
#define BUZZER_PIN 9      // Buzzer connected to Arduino pin 9
#define FLAME_SENSOR_PIN 8 // Flame sensor connected to Arduino pin 8

// LoRa module pins
#define LORA_SS 10        // LoRa chip select (NSS)
#define LORA_RST 3        // LoRa reset pin
#define LORA_DIO0 4       // LoRa DIO0 pin

// DHT sensor type
#define DHTTYPE DHT11     // DHT 11 sensor

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor

void setup() {
  // Serial Monitor setup
  Serial.begin(9600);

  // Initialize sensors and buzzer
  dht.begin();
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(FLAME_SENSOR_PIN, INPUT);

  // Initialize LoRa module
  Serial.println("Initializing LoRa...");
  LoRa.setPins(LORA_SS, LORA_RST, LORA_DIO0);
  if (!LoRa.begin(433E6)) { // Adjust frequency as per your region
    Serial.println("LoRa initialization failed!");
    while (1);
  }
  Serial.println("LoRa initialized");
}

void loop() {
  // Real-time data acquisition
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  int mq135Value = analogRead(MQ135_PIN);
  int flameStatus = digitalRead(FLAME_SENSOR_PIN); // LOW = Flame detected

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Display data on Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.print(" %, MQ135 Value: ");
  Serial.print(mq135Value);
  Serial.print(", Flame Status: ");
  Serial.println(flameStatus == LOW ? "Detected" : "Not Detected");

  // Activate buzzer if thresholds are exceeded
  if (mq135Value > 300 || flameStatus == LOW || temperature > 32) {
    digitalWrite(BUZZER_PIN, HIGH); // Turn on buzzer
    if (mq135Value > 300) Serial.println("Gas concentration exceeded threshold!");
    if (flameStatus == LOW) Serial.println("Flame detected!");
    if (temperature > 32) Serial.println("Temperature exceeded 30°C!");
  } else {
    digitalWrite(BUZZER_PIN, LOW); // Turn off buzzer
  }

  // Transmit data via LoRa
  Serial.println("Transmitting data via LoRa...");
  LoRa.beginPacket();
  LoRa.print("Temperature: ");
  LoRa.print(temperature);
  LoRa.print(" °C, Humidity: ");
  LoRa.print(humidity);
  LoRa.print(" %, MQ135 Value: ");
  LoRa.print(mq135Value);
  LoRa.print(", Flame Detected: ");
  LoRa.print(flameStatus == LOW ? "Yes" : "No");
  LoRa.endPacket();
  Serial.println("Data transmitted via LoRa!");

  // Delay for stability
delay(2000);
}
