#include <Arduino.h>
#include <TimerOne.h>
#include "pins.h"
#include "calibration.h"
#include "config.h"
#include "buttons.h"
#include "adc.h"
#include <U8glib.h>
#include "graph.h"
#include "sensors.h"
#include "sound.h"
#include "timer.h"

bool enabled = false;

timer_t temp_timer;
timer_t draw_timer;
error_t overcurrent_error;


struct load_draw_info_t
{
	uint32_t voltage;
	uint32_t requested_current;
	uint32_t current;
	uint32_t watts;
	uint32_t mah;
	int16_t temp;
	bool overcurrent_warning;
};

void load_enable(bool enable)
{
	bool play_sound = enable != enabled;
	if(enable && play_sound)
	{
		sound_play_note(440, 100);
		sound_play_note(460, 100);
		digitalWrite(LED_MAIN, HIGH);
		digitalWrite(LED_WARNING_ONE, LOW);
		digitalWrite(LED_WARNING_TWO, LOW);
	}
    enabled = enable;
    digitalWrite(OUTPUT_ENABLE, enable);
	if(!enable && play_sound)
	{
		digitalWrite(LED_MAIN, LOW);
		digitalWrite(LED_WARNING_ONE, HIGH);
		digitalWrite(LED_WARNING_TWO, HIGH);
		for(int i = 0; i < 10; i++)
		{
			sound_play_note(460, 20);
			sound_play_note(440, 20);
		}
	}
}

bool load_get_state()
{
    return enabled;
}

void load_set_raw_pwm(uint16_t pwm)
{
    Timer1.pwm(13, pwm);
}
void load_set_current(uint16_t current)
{
    load_set_raw_pwm(calibrate_adc_value(current, config.calibration.current_set));
}

uint32_t voltage = 0; // mV
uint32_t current = 0; // mA
uint32_t watts = 0; // mW
uint32_t uas = 0; // Microampereseconds
uint32_t mah = 0; // milliamperehours
uint32_t time = 0;
uint32_t requested_current = 0;

void load_init()
{
    requested_current = config.procedures[0].current;
    load_set_current(requested_current);
    uas = 0;
    mah = 0;
    time = millis();
    graph_init();

	timer_init(&temp_timer, SECONDS(5), true);
	timer_init(&draw_timer, SECONDS(1), true);
	error_init(&overcurrent_error, SECONDS(2));
}

void draw_measurements(U8GLIB *u8g, uint8_t x, uint8_t y, load_draw_info_t *info)
{
  // x = 70
  // y = 0
    u8g->setPrintPos(x+5, y+9);
    u8g->print(info->voltage / 10);
    u8g->print(".");
    u8g->print(info->voltage % 10);
    u8g->print("V");

    u8g->setPrintPos(x+5, y+19);
    u8g->print(info->watts / 10);
    u8g->print(".");
    u8g->print(info->watts % 10);
    u8g->print("W");
    
    u8g->setPrintPos(x+5, y+29);
    u8g->print(info->temp / 128);
    u8g->print(".");
    u8g->print(uint16_t((float(uint16_t(info->temp) % 128) / 128.0f) * 100));
    u8g->print("C");
    /*u8g->print("S");
    u8g->print(requested_current / 10);
    u8g->print(".");
    u8g->print(requested_current % 10);
    u8g->print("A");*/
    
	if(info->overcurrent_warning)
	{
		u8g->drawBox(x, y+32, 120, 10);
        u8g->setColorIndex(0);
	}
	else
	{
		u8g->setColorIndex(1);
	}
	
    u8g->setPrintPos(x+5, y+39);
    u8g->print(info->current / 10);
    u8g->print(".");
    u8g->print(info->current % 10);
    u8g->print("A");

	u8g->setColorIndex(1);

    u8g->setPrintPos(x+5, y+49);
    u8g->print(info->mah);
    u8g->print("mAh");

    u8g->drawFrame(x, y, 43, 55);
}

void draw(U8GLIB *u8g, load_draw_info_t *info)
{
    u8g->firstPage();

	do {
		draw_measurements(u8g, 85, 0, info);
       	graph_draw(u8g, 0, 0, 86, 55);
		if(load_get_state())
            buttons_draw(u8g, "", "Stop", "", "Exit");
       	else
           	buttons_draw(u8g, "Start", "", "", "Exit");
   	} while (u8g->nextPage());
}

uint32_t time_counter = 0;
load_draw_info_t load_draw_info;

bool load_run(U8GLIB *u8g, bool anything_updated)
{
    button_state_t buttons = buttons_get_reset();

    if(buttons.button[0] && !load_get_state())
    {
        load_enable(true);
        time = millis();
    }

    if(buttons.button[1] && load_get_state())
    {
        load_enable(false);
    }

    if(buttons.button[3])
    {
        load_enable(false);
        return false;
    }
    
    voltage = adc_get_voltage();
    current = adc_get_current();
    watts = voltage * current / 1000;

    if(load_get_state())
    {
        uint32_t new_time = millis();
        uint32_t length = new_time - time;
        time_counter += length;
        uas += current * length; // microampereseconds
        time = new_time;

		error_set(&overcurrent_error, current > requested_current * 1.05);
		if(error_get(&overcurrent_error))
		{
			load_enable(false);
			digitalWrite(LED_WARNING_ONE, LOW);
		}

		

        mah += uas / (1000UL*3600);
        uas %= 1000UL*3600;

		if(mah >= config.procedures[0].mah_limit)
		{
			load_enable(false);
			digitalWrite(LED_WARNING_TWO, LOW);
		}

        if(time_counter > graph_time_scale) // log interval
        {
            time_counter -= graph_time_scale;
            graph_add_point(voltage, current);
        }

    }

    if(load_get_state() && voltage <= config.procedures[0].end_voltage)
    {
        load_enable(false);
    }

	if(timer_elapsed(&temp_timer))
    {
        one_wire_get_temperatures(&load_draw_info.temp);
    }

    if(timer_elapsed(&draw_timer))
    {
		load_draw_info.current = float(current) / 100.0f + 0.5f;
		load_draw_info.mah = mah;
		load_draw_info.overcurrent_warning = overcurrent_error.warning;
		load_draw_info.requested_current = float(requested_current) / 100.0f + 0.5f;
		load_draw_info.voltage = float(voltage) / 100.0f + 0.5f;
		load_draw_info.watts = float(watts) / 100.0f + 0.5f;
        draw(u8g, &load_draw_info);
    }
    return true;
}