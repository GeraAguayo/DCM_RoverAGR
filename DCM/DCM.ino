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

bool set_up = false;

void loop() {

  if (bmp_sensor.is_enabled()){
    bmp_data* data = bmp_sensor.read_values();
    Serial.println("Temperature:");
    Serial.println(data->temperature);
    Serial.println("Pressure:");
    Serial.println(data->pressure);
    Serial.println("Altitude:");
    Serial.println(data->altitude);
    delete data;
  }
  else{
    Serial.println("BMP280 sensor not enabled");
  }
  delay(2500);

}
