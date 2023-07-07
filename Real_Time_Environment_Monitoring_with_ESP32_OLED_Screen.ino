#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <DHT.h>

#define DHTPIN 4       // Pin connected to the DHT11 sensor
#define DHTTYPE DHT11  // DHT sensor type

DHT dht(DHTPIN, DHTTYPE);

#define OLED_SDA 21
#define OLED_SCL 22
Adafruit_SH1106 display(21, 22);

#define GAS_PIN 35        // Analog pin connected to MQ-2 Gas Sensor
#define LIGHT_PIN 2      // Analog pin connected to Photosensitive Sensor

void setup() {
  Serial.begin(115200);
  display.begin(SH1106_SWITCHCAPVCC);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Environmental Monitoring");
  display.display();
  delay(2000);

  dht.begin();
  pinMode(GAS_PIN, INPUT);
  pinMode(LIGHT_PIN, INPUT);
}

void loop() {
  float temperature = dht.readTemperature();  // Read temperature in Celsius
  float humidity = dht.readHumidity();        // Read relative humidity
  int gasLevel = analogRead(GAS_PIN);         // Read gas level
  int lightLevel = analogRead(LIGHT_PIN);     // Read light level

  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Temperature: ");
  display.print(temperature);
  display.println("C");

  display.print("Humidity: ");
  display.print(humidity);
  display.println("%");

  display.print("Gas Level: ");
  display.println(gasLevel);

  display.print("Light Level: ");
  display.println(lightLevel);
  
  display.display();

  delay(5000);  // Delay for 5 seconds before next reading
}
