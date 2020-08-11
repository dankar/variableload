#ifndef _BUTTONS_H_
#define _BUTTONS_H_

#include <U8glib.h>

typedef struct
{
  uint8_t button[4];
} button_state_t;

bool buttons_update();
bool button_get_state(uint8_t button);
button_state_t buttons_get_reset();
void button_wait_for_press(uint8_t button);
void buttons_draw(U8GLIB *u8g, const char* one, const char *two, const char *three, const char *four);

#endif