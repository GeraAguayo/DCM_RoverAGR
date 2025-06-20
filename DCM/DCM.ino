//DATA COLLECTION MODULE
//Rover AGR
//Gerardo Aguayo
#include "BMP.h"

BMP bmp_sensor;

void setup() {
  Serial.begin(9600);
  delay(100);
  bmp_sensor.begin();
}

bool set_up = false;

//Serial Values Standard
//Temperature val - 0
//Pressure val - 1
//Altitude val - 2


void loop() {

  if (bmp_sensor.is_enabled()){
    bmp_data* data = bmp_sensor.read_values();
    Serial.println(data->temperature);
    Serial.println(data->pressure);
    Serial.println(data->altitude);
    delete data;
  }
  else{
    Serial.println("BMP280 sensor not enabled");
  }
  delay(2500);

}
