#include <LoRa.h> // LoRa library

// LoRa module pins
#define LORA_SS 10        // LoRa chip select (NSS)
#define LORA_RST 3        // LoRa reset pin
#define LORA_DIO0 4       // LoRa DIO0 pin

// Buzzer pin
#define BUZZER_PIN 9      // Buzzer connected to pin 9

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Initialize LoRa module
  Serial.println("Initializing LoRa Receiver...");
  LoRa.setPins(LORA_SS, LORA_RST, LORA_DIO0);
  if (!LoRa.begin(433E6)) { // Adjust frequency as per your region
    Serial.println("LoRa initialization failed!");
    while (1);
  }
  Serial.println("LoRa Receiver initialized");

  // Initialize buzzer
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW); // Ensure buzzer is OFF initially
}

void loop() {
  // Check if there is any LoRa packet available
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    Serial.println("Received LoRa packet:");

    // Read the incoming LoRa packet
    String receivedData = "";
    while (LoRa.available()) {
      receivedData += (char)LoRa.read(); // Read the packet data
    }
    Serial.println(receivedData);

    // Process the received data
    processReceivedData(receivedData);

    // Print RSSI (Signal Strength)
    Serial.print("RSSI: ");
    Serial.println(LoRa.packetRssi());
  }

  // Small delay for stability
  delay(500);
}

void processReceivedData(String data) {
  // Example data format: "Temperature: 34.0;Humidity: 45.0;MQ135: 320;Flame Detected: Yes"
  float temperature = 0;
  int mq135Value = 0;
  bool flameDetected = false;

  // Parse temperature
  int tempIndex = data.indexOf("Temperature: ");
  if (tempIndex != -1) {
    int tempEndIndex = data.indexOf(" °C", tempIndex);
    temperature = data.substring(tempIndex + 13, tempEndIndex).toFloat();
  }

  // Parse MQ135 value
  int mqIndex = data.indexOf("MQ135 Value: ");
  if (mqIndex != -1) {
    int mqEndIndex = data.indexOf(",", mqIndex);
    mq135Value = data.substring(mqIndex + 13, mqEndIndex).toInt();
  }

  // Parse flame status
  int flameIndex = data.indexOf("Flame Detected: ");
  if (flameIndex != -1) {
    String flameStatus = data.substring(flameIndex + 16); // Extract substring
    flameStatus.trim(); // Trim whitespace
    flameDetected = (flameStatus == "Yes");
  }

  Serial.print("Parsed Temperature: ");
  Serial.println(temperature);
  Serial.print("Parsed MQ135 Value: ");
  Serial.println(mq135Value);
  Serial.print("Parsed Flame Detected: ");
  Serial.println(flameDetected ? "Yes" : "No");

  // Activate buzzer based on conditions
  if (temperature > 32 || mq135Value > 300 || flameDetected) {
    digitalWrite(BUZZER_PIN, HIGH); // Turn buzzer ON
    Serial.println("Buzzer ON: Alert received from transmitter!");
  } else {
    digitalWrite(BUZZER_PIN, LOW); // Turn buzzer OFF
  }
}
