#include <Arduino.h>
#include <Wire.h>
#include <BH1750.h>
#include "DHT.h"

// Pin Definitions
#define DHTPIN 4          // DHT22 Data pin
#define DHTTYPE DHT22
#define SOIL_PIN 34       // Analog Soil Moisture pin

// Initialize sensors
DHT dht(DHTPIN, DHTTYPE);
BH1750 lightMeter;

void setup() {
  // Serial baud rate must match platformio.ini
  Serial.begin(115200);
  
  // Initialize I2C for BH1750 (Default SDA=21, SCL=22)
  Wire.begin();
  
  // Initialize DHT22
  dht.begin();
  
  // Initialize BH1750
  if (lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
    Serial.println(F("BH1750 Initialized"));
  } else {
    Serial.println(F("Error initializing BH1750"));
  }

  Serial.println("--- System Online ---");
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  int soilValue = analogRead(SOIL_PIN);

  float lux = lightMeter.readLightLevel();

  Serial.print("Temp: "); Serial.print(temperature); Serial.print("°C | ");
  Serial.print("Hum: "); Serial.print(humidity); Serial.print("% | ");
  Serial.print("Light: "); Serial.print(lux); Serial.print(" lx | ");
  Serial.print("Soil Raw: "); Serial.println(soilValue);

  delay(2000);
}