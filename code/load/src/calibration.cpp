#include <Arduino.h>
#include "calibration.h"
#include "config.h"
#include "buttons.h"
#include "adc.h"
#include "load_control.h"

void do_calibration()
{
  /*for(int i = 0; i < NUM_CALIBRATION_POINTS; i++)
  {
    uint16_t voltage = MAX_VOLTAGE / NUM_CALIBRATION_POINTS * i;
    Serial.print("Set input voltage to ");
    Serial.print(voltage/10);
    Serial.println("0mV");
    button_wait_for_press(0);
    config.calibration.voltage[i].adc_value = adc_raw_voltage();
    config.calibration.voltage[i].out_value = voltage;
    Serial.print(config.calibration.voltage[i].adc_value);
    Serial.print(" = ");
    Serial.println(config.calibration.voltage[i].out_value);
  }*/

  /*for(int i = 0; i < NUM_CALIBRATION_POINTS; i++)
  {
    uint16_t current = MAX_CURRENT / NUM_CALIBRATION_POINTS * i;
    Serial.print("Set input current to ");
    Serial.print(current/10);
    Serial.println("0mA");
    button_wait_for_press(0);
    load_set_raw_pwm(1023);
    load_enable(true);
    delay(500);
    config.calibration.current[i].adc_value = adc_raw_current();
    load_enable(false);
    config.calibration.current[i].out_value = current;
    Serial.print(config.calibration.current[i].adc_value);
    Serial.print(" = ");
    Serial.println(config.calibration.current[i].out_value);
  }*/


    load_enable(true);
  for(int i = 0; i < NUM_CALIBRATION_POINTS; i++)
  {
    uint16_t pwm_value = 400 / NUM_CALIBRATION_POINTS * i;

    load_set_raw_pwm(pwm_value);
        
    delay(1000);
    uint16_t real_current = adc_get_current();
    
    config.calibration.current_set[i].adc_value = real_current;
    
    config.calibration.current_set[i].out_value = pwm_value;
    Serial.print(config.calibration.current_set[i].adc_value);
    Serial.print(" = ");
    Serial.println(config.calibration.current_set[i].out_value);
  }
  load_enable(false);
}

float lerp(float v0, float v1, float t) {
  return (1 - t) * v0 + t * v1;
}

uint16_t calibrate_adc_value(uint16_t value, calibration_point_t calibration[NUM_CALIBRATION_POINTS])
{
  int8_t calibration_index = -1;
  for(int i = 0; i < NUM_CALIBRATION_POINTS; i++)
  {
    if(value < calibration[i].adc_value)
    {
      calibration_index = i-1;
      break;
    }
    
  }

  if(calibration_index == -1 || calibration_index >= NUM_CALIBRATION_POINTS-1)
  {
    return -1;
  }

  value -= calibration[calibration_index].adc_value;
  uint16_t window_size = calibration[calibration_index+1].adc_value - calibration[calibration_index].adc_value;

  float t = float(value) / window_size;

  return uint16_t(lerp(calibration[calibration_index].out_value, calibration[calibration_index+1].out_value, t));
}