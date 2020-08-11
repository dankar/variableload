#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "calibration.h"

typedef struct 
{
    uint32_t current; // mA
    uint32_t end_voltage; // mV
    uint32_t max_time; 
    uint32_t mah_limit;
} saved_procedure_t;


typedef struct 
{
    config_calibration_t calibration;
    saved_procedure_t procedures[10];
} config_t;

static_assert(sizeof(config_t) < 4096, "Config does not fit in EEPROM");

extern config_t config;

void config_save();
void config_load();

#endif