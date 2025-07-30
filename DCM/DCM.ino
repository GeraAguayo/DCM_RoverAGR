//DATA COLLECTION MODULE
//Rover AGR
//Gerardo Aguayo
#include "BMP.h"

BMP bmp_sensor;

void raise_error();

enum error_ids {
  BMP_ERROR = 2,
};

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
    Serial.println("DATA");
    Serial.println(data->temperature);
    Serial.println(data->pressure);
    Serial.println(data->altitude);
    Serial.println("END");
    delete data;
  }
  else{
    //Raise BMP error and try again
    raise_error(BMP_ERROR);
    bmp_sensor.begin();
  }
}

void raise_error(error_ids id){
  Serial.println("SYSLOG");
  Serial.println(id);
  Serial.println("END");

}
