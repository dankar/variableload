#include <Arduino.h>
#include "pins.h"
#include "sound.h"

void sound_play_note(float frequency, uint16_t ms)
{
  uint32_t start = millis();
  uint32_t delay_length = 1000UL * 1000UL / frequency / 2;

  while(millis() < (start + ms))
  {
    if(frequency != 0)
    {
      digitalWrite(SPEAKER_DRIVE, 1);
      delayMicroseconds(delay_length);
      digitalWrite(SPEAKER_DRIVE, 0);
      delayMicroseconds(delay_length);
    }
    else
    {
      delay(1);
    }
    
  }
}