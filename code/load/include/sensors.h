#ifndef _SENSORS_H_
#define _SENSORS_H_

#include <Arduino.h>

void one_wire_setup();
uint8_t one_wire_get_num_sensors();
bool one_wire_get_temperatures(int16_t *temps);

#endif