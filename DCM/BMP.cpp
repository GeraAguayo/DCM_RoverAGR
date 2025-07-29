#include "BMP.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define SEA_LEVEL_PRESS_HPA (1013.25)
bool enabled = false;

BMP::BMP(){
  enabled = false;
}

BMP::begin(){
  //Initialize bmp sensor
  //Here beacause if intialized in constructor causes conflict with Serial
  bool status_sensor = this->bmp_sensor.begin(0x76);
  if (!status_sensor){
    enabled = false;
  } else {
    enabled = true;
  }
}

BMP::~BMP() {
  //Destructor
}

bmp_data* BMP::read_values(){
  bmp_data* d = new bmp_data;
  //Read from sensor
  d->temperature = bmp_sensor.readTemperature();
  d->pressure = bmp_sensor.readPressure() / 100.0f;
  d->altitude = bmp_sensor.readAltitude(SEA_LEVEL_PRESS_HPA);
  return d;
}

bool BMP::is_enabled(){
  if (this->bmp_sensor.begin(0x76)){
    return true;
  }else{
    return false;
  }
}