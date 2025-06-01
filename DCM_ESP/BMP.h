#ifndef BMP_H
#define BMP_h

//BMP280 sensor module
//Gerardo Aguayo

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

class BMP{
  public:
    BMP();
    ~BMP();
    read_values();
    struct bmp_data;
};


#endif