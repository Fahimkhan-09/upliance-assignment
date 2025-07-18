#include <OneWire.h>
#include <DallasTemperature.h>

#define DATA_PIN 2       
#define HEATER_LED 3     

OneWire oneWire(DATA_PIN);
DallasTemperature sensor(&oneWire);

void setup() {
  Serial.begin(9600);
  sensor.begin();
  pinMode(HEATER_LED, OUTPUT);
}

void loop() {
  sensor.requestTemperatures();
  float temp = sensor.getTempCByIndex(0);

  Serial.print("Temp: "); Serial.print(temp); Serial.print("°C ");

  if (temp >= 60) {
    Serial.println("| State: OVERHEAT");
    digitalWrite(HEATER_LED, LOW);
  } else if (temp >= 40) {
    Serial.println("| State: TARGET REACHED");
    digitalWrite(HEATER_LED, LOW);
  } else if (temp >= 37) {
    Serial.println("| State: STABILIZING");
    digitalWrite(HEATER_LED, HIGH);
  } else if (temp >= 25) {
    Serial.println("| State: HEATING");
    digitalWrite(HEATER_LED, HIGH);
  } else {
    Serial.println("| State: IDLE");
    digitalWrite(HEATER_LED, LOW);
  }

  delay(1000);
}
