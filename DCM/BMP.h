#ifndef BMP_H
#define BMP_H

//BMP280 sensor module
//Gerardo Aguayo

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

struct bmp_data{
  float temperature;// °C
  float pressure;// hPa
  float altitude;// m
};

class BMP{
  private:
    Adafruit_BMP280 bmp_sensor;
  public:
    BMP();
    ~BMP();
    begin();
    bmp_data* read_values();
    bool is_enabled();
};


#endif