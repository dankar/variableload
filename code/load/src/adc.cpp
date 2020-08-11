#include <Arduino.h>
#include "adc.h"
#include "pins.h"
#include "config.h"
#include "calibration.h"

uint16_t adc_get_reading(uint8_t pin)
{
    uint32_t value = 0;
    for(int i = 0; i < 20; i++)
    {
        value += analogRead(pin);
        delay(1);
    }
    return value / 20;
}

uint16_t adc_raw_voltage()
{
    return adc_get_reading(ANALOG_VOLTAGE);
}
uint16_t adc_raw_current()
{
    return adc_get_reading(ANALOG_CURRENT);
}

uint16_t adc_get_voltage()
{
  uint16_t raw = adc_raw_voltage();
  return calibrate_adc_value(raw, config.calibration.voltage);
}

uint16_t adc_get_current()
{
  uint16_t raw = adc_raw_current();
  return calibrate_adc_value(raw, config.calibration.current);
}