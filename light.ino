#define LIGHT_PIN 2  // Digital pin connected to Photosensitive Sensor

void setup() {
  Serial.begin(115200);
  pinMode(LIGHT_PIN, INPUT);
}

void loop() {
  int lightLevel = digitalRead(LIGHT_PIN);  // Read light level (HIGH or LOW)

  if (lightLevel == HIGH) {
    Serial.println("No Light Detected");
  } else {
    Serial.println("Light Detected!");
  }

  delay(2000);  // Delay for 2 seconds before next reading
}
