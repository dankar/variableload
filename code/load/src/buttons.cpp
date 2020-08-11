#include <Arduino.h>
#include "buttons.h"
#include "pins.h"

#define DEBOUNCE_DELAY 50

typedef struct
{
    uint32_t last[4];
} debounce_t;


debounce_t debounce = {0};
button_state_t button_state = {0};
button_state_t button_last_state = {0};
button_state_t button_state_reset = {0};


bool buttons_update()
{
    button_state_t buttons = {!digitalRead(BUTTON_ONE), !digitalRead(BUTTON_TWO), !digitalRead(BUTTON_THREE), !digitalRead(BUTTON_FOUR)};
    bool anything_updated = false;

    for(int i = 0; i < 4; i++)
    {
        if(buttons.button[i] != button_last_state.button[i])
        {
            debounce.last[i] = millis();
        }

        if((millis() - debounce.last[i]) > DEBOUNCE_DELAY)
        {
            if(button_state.button[i] != buttons.button[i])
            {
                anything_updated = true;
                button_state_reset.button[i] = buttons.button[i];
                button_state.button[i] = buttons.button[i];
            }
        }
    }

    button_last_state = buttons;

    return anything_updated;
}
bool button_get_state(uint8_t button)
{
    return button_state.button[button];
}
void button_wait_for_press(uint8_t button)
{
    do
    {
        buttons_update();
    } while (!button_state.button[button]);

    do
    {
        buttons_update();
    } while (button_state.button[button]);
}

button_state_t buttons_get_reset()
{
    button_state_t buttons = button_state_reset;
    button_state_reset = {0};
    return buttons;
}

void buttons_draw(U8GLIB *u8g, const char* one, const char *two, const char *three, const char *four)
{
    u8g->drawFrame(0, 54, 128, 10);

    u8g->setPrintPos(2, 61);
    u8g->print(one);
    u8g->setPrintPos(36, 61);
    u8g->print(two);
    u8g->setPrintPos(66, 61);
    u8g->print(three);
    u8g->setPrintPos(96, 61);
    u8g->print(four);
}