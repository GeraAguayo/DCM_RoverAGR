//DATA COLLECTION MODULE
//Rover AGR
//Gerardo Aguayo
#include "BMP.h"

BMP bmp_sensor;

void setup() {
  Serial.begin(9600);
  delay(100);
  Serial.println("Data collection module - ROVER AGR");
  bmp_sensor.begin();
}

void loop() {
  if (bmp_sensor.is_enabled()){
    bmp_data* data = bmp_sensor.read_values();
    delete data;
  }
  else{
    Serial.println("BMP280 sensor not enabled");
  }

}
