#include <Arduino.h>
#include <EEPROM.h>
#include "config.h"

 config_t config = {0};

void config_save()
{
  uint8_t *ptr = (uint8_t*)&config;

  for(size_t i = 0; i < sizeof(config); i++)
  {
    EEPROM.write(i, ptr[i]);
  }
}

void config_load()
{
  uint8_t *ptr = (uint8_t*)&config;

  for(size_t i = 0; i < sizeof(config); i++)
  {
    ptr[i] = EEPROM.read(i);
  }
}