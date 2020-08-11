#ifndef _MENU_H_
#define _MENU_H_
#include <Arduino.h>
#include <U8glib.h>

typedef enum
{
    APPLICATION,
    SUB_MENU,
    INTEGER,
    MENU_END
} menu_item_type_t;

typedef struct 
{
    void (*init)();
    bool (*run)(U8GLIB *u8g, bool anything_updated);
} application_t;


struct menu_t;

typedef struct menu_item_t
{
    menu_item_type_t type;
    const char *name;
    menu_t *sub_menu;
    application_t *application;
    const char *integer_suffix;
    uint16_t integer_scaling;
    uint16_t integer_decimal;
    uint32_t *integer;
} menu_item_t;

struct menu_t
{
    menu_item_t items[5];
    menu_t *parent;
    uint8_t selected_item;
} ;

extern menu_t main_menu;
extern menu_t *active_menu;
extern application_t *active_application;

void menu_run(U8GLIB *u8g, bool anything_updated);
void menu_update();

#endif