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

bool enabled = false;

void load_enable(bool enable)
{
    enabled = enable;
    digitalWrite(OUTPUT_ENABLE, enable);
    digitalWrite(OUTPUT_ENABLE, enable);
    digitalWrite(OUTPUT_ENABLE, enable);
    digitalWrite(OUTPUT_ENABLE, enable);
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
}

void draw_measurements(U8GLIB *u8g, uint8_t x, uint8_t y, uint32_t voltage, uint32_t requested_current, uint32_t current, uint32_t watts, uint32_t mah, int16_t temp)
{
  // x = 70
  // y = 0
    u8g->setPrintPos(x+5, y+9);
    u8g->print(voltage / 10);
    u8g->print(".");
    u8g->print(voltage % 10);
    u8g->print("V");

    u8g->setPrintPos(x+5, y+19);
    u8g->print(watts / 10);
    u8g->print(".");
    u8g->print(watts % 10);
    u8g->print("W");
    
    u8g->setPrintPos(x+5, y+29);
    u8g->print(temp / 128);
    u8g->print(".");
    u8g->print(uint16_t((float(uint16_t(temp) % 128) / 128.0f) * 100));
    u8g->print("C");
    /*u8g->print("S");
    u8g->print(requested_current / 10);
    u8g->print(".");
    u8g->print(requested_current % 10);
    u8g->print("A");*/
    
    u8g->setPrintPos(x+5, y+39);
    u8g->print(current / 10);
    u8g->print(".");
    u8g->print(current % 10);
    u8g->print("A");

    u8g->setPrintPos(x+5, y+49);
    u8g->print(mah);
    u8g->print("mAh");

    u8g->drawFrame(x, y, 43, 55);
}

int16_t temp = 0;
uint8_t temp_update = 0;

void draw(U8GLIB *u8g, uint32_t voltage, uint32_t requested_current, uint32_t current, uint32_t watts, uint32_t mah)
{
    voltage = float(voltage) / 100.0f + 0.5f;
    requested_current = float(requested_current) / 100.0f + 0.5f;
    current = float(current) / 100.0f + 0.5f;
    watts = float(watts) / 100.0f + 0.5f;
    //Write text. (x, y, text)

    if(temp_update == 0)
    {
        one_wire_get_temperatures(&temp);
    }

    u8g->firstPage();
    do {
        draw_measurements(u8g, 85, 0, voltage, requested_current, current, watts, mah, temp);
        graph_draw(u8g, 0, 0, 86, 55);
        if(load_get_state())
            buttons_draw(u8g, "", "Stop", "", "Exit");
        else
            buttons_draw(u8g, "Start", "", "", "Exit");
        
    } while (u8g->nextPage());
    
}

uint32_t frame_counter = 0;
uint32_t time_counter = 0;

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
        Serial.println("Disabling!");
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

        mah += uas / (1000UL*3600);
        uas %= 1000UL*3600;

        if(time_counter > graph_time_scale) // log interval
        {
            time_counter -= graph_time_scale;
            graph_add_point(voltage, current);
        }

    }

    

    if(load_get_state() && voltage <= config.procedures[0].end_voltage)
    {
        Serial.println("Disabling!");
        load_enable(false);
    }

    if(frame_counter % 5 == 0)
    {
        draw(u8g, voltage, requested_current, current, watts, mah);
    }
    frame_counter++;
    return true;
}