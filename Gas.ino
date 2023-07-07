#include <MQ2.h>

#define GAS_PIN 32   // Analog pin connected to MQ-2 Gas Sensor

MQ2 mq2(GAS_PIN);

void setup() {
  Serial.begin(115200);
  mq2.begin();
}

void loop() {
  float lpg, co, smoke;

  lpg = mq2.readLPG();
  co = mq2.readCO();
  smoke = mq2.readSmoke();

  Serial.print("LPG: ");
  Serial.print(lpg);
  Serial.print(" ppm\tCO: ");
  Serial.print(co);
  Serial.print(" ppm\tSmoke: ");
  Serial.print(smoke);
  Serial.println(" ppm");

  delay(1000);  // Delay for 1 second before next reading
}
