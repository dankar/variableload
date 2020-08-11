#ifndef _LOAD_CONTROL_H_
#define _LOAD_CONTROL_H_

#include <U8glib.h>

void load_enable(bool enable);
bool load_get_state();
void load_set_raw_pwm(uint16_t pwm);
void load_set_current(uint16_t current);

void load_init();
bool load_run(U8GLIB *u8g, bool anything_updated);

#endif