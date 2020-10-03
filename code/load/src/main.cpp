#include <Arduino.h>
#include <TimerOne.h>
#include <U8glib.h>
#include "pins.h"
#include "buttons.h"
#include "adc.h"
#include "config.h"
#include "load_control.h"
#include "menu.h"
#include "sensors.h"
#include "sound.h"

U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0);

void setup() {

  u8g.setFont(u8g_font_04b_03);
  
  Timer1.initialize(20);
  //analogReadResolution(10);
  pinMode(BUTTON_ONE, INPUT_PULLUP);
  pinMode(BUTTON_TWO, INPUT_PULLUP);
  pinMode(BUTTON_THREE, INPUT_PULLUP);
  pinMode(BUTTON_FOUR, INPUT_PULLUP);
  pinMode(ANALOG_VOLTAGE, INPUT);
  pinMode(ANALOG_CURRENT, INPUT);
  pinMode(OUTPUT_ENABLE, OUTPUT);
  pinMode(CURRENT_SET, OUTPUT);
  pinMode(SPEAKER_DRIVE, OUTPUT);
  pinMode(LED_MAIN, OUTPUT);
  pinMode(LED_WARNING_ONE, OUTPUT);
  pinMode(LED_WARNING_TWO, OUTPUT);
  analogReference(INTERNAL2V56);
  Serial.begin(115200);
  one_wire_setup();

	digitalWrite(LED_WARNING_ONE, HIGH);
	digitalWrite(LED_WARNING_TWO, HIGH);
  sound_play_note(440, 100);
  sound_play_note(450, 100);
  sound_play_note(460, 100);
}

int fadeValue = 0;
int dir = 1;
void loop() {

  config_load();

  bool anything_updated = true;
  for(;;)
  {
      menu_run(&u8g, anything_updated);
      anything_updated = buttons_update();
  }

  /*if(dir == 1)
  {
    // sets the value (range from 0 to 255):
    analogWrite(LED_MAIN, fadeValue);
    analogWrite(LED_WARNING_ONE, 255-fadeValue);
    analogWrite(LED_WARNING_TWO, 255-fadeValue);
    
    if(++fadeValue == 255)
    {
      dir = 0;
    }
  }
  else if(dir == 0)
  {
    // sets the value (range from 0 to 255):
    analogWrite(LED_MAIN, fadeValue);
    analogWrite(LED_WARNING_ONE, 255-fadeValue);
    analogWrite(LED_WARNING_TWO, 255-fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    if(--fadeValue == 0)
    {
      dir = 1;
    }
  }

  delay(1);*/
}
