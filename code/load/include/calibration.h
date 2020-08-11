#ifndef _CALIBRATION_H_
#define _CALIBRATION_H_

#define MAX_VOLTAGE              20000 // mV
#define MAX_CURRENT              5000 // mA
#define NUM_CALIBRATION_POINTS   20

typedef struct
{
  uint16_t adc_value;
  uint16_t out_value;
} calibration_point_t;

typedef struct 
{
  calibration_point_t voltage[NUM_CALIBRATION_POINTS];
  calibration_point_t current[NUM_CALIBRATION_POINTS];
  calibration_point_t current_set[NUM_CALIBRATION_POINTS];
} config_calibration_t;

void do_calibration();
uint16_t calibrate_adc_value(uint16_t value, calibration_point_t calibration[NUM_CALIBRATION_POINTS]);

#endif