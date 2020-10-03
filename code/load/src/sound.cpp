#include <Arduino.h>
#include "pins.h"
#include "sound.h"

const bool sound_enabled = true;

void sound_play_note(float frequency, uint16_t ms)
{
	if(sound_enabled)
	{
		tone(SPEAKER_DRIVE, frequency, ms);
		delay(ms);
	}
}