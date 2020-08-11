#ifndef _ADC_H_
#define _ADC_H_

uint16_t adc_get_reading(uint8_t pin);
uint16_t adc_raw_voltage();
uint16_t adc_raw_current();
uint16_t adc_get_voltage();
uint16_t adc_get_current();

#endif