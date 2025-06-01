#include "BMP.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define SEA_LEVEL_PRESS_HPA (1013.25)

struct bmp_data{
  float temperature;// °C
  float pressure;// hPa
  float altitude;// m
};

BMP::BMP(){
  Serial.begin(9600);
  Serial.println("Intializing BMP sensor");
  
  //Initialize bmp sensor
  Adafruit_BMP280 bmp;
  bool status_sensor = bmp.begin(0x76);
  if (!status_sensor){
    Serial.println("BMP 280 sensor not found");
  } else {
    Serial.println("Senor found!");
  }
}

BMP::read_values(){
  bmp_data* d = new bmp_data;
  //Read from sensor
  d->temperature = bmp.readTemperature();
  d->pressure = bmp.readPressure() / 100.0f;
  d->altitude = bmp.readAltitude(SEA_LEVEL_PRESS_HPA);
  return d;
}