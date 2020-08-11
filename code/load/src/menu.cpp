#include "menu.h"
#include "buttons.h"
#include "load_control.h"
#include "config.h"

menu_t settings = 
{
    .items = {
        {.type = SUB_MENU, .name = "Calibrate"},
        {.type = INTEGER, .name = "Min voltage", .sub_menu = NULL, .application = NULL, .integer_suffix = "V", .integer_scaling = 1000, .integer_decimal = 100, .integer = &config.procedures[0].end_voltage },
        {.type = INTEGER, .name = "Max current", .sub_menu = NULL, .application = NULL, .integer_suffix = "A", .integer_scaling = 1000, .integer_decimal = 10, .integer = &config.procedures[0].current },
        {.type = INTEGER, .name = "Max mAh", .sub_menu = NULL, .application = NULL, .integer_suffix = "mAh", .integer_scaling = 1, .integer_decimal = 1, .integer = &config.procedures[0].mah_limit },
        {.type = MENU_END }
    },
    .parent = &main_menu
};

application_t load_application =
{
    .init = load_init,
    .run = load_run
};

menu_t main_menu = {
    .items = {
        {.type = APPLICATION, .name = "Start", .sub_menu = NULL, .application = &load_application },
        {.type = SUB_MENU, .name = "Settings", .sub_menu = &settings},
        {.type = MENU_END },
    }
};

menu_t *active_menu = &main_menu;
application_t *active_application = NULL;
uint32_t active_edit_integer = 0;

menu_item_t *menu_get_item(uint8_t item)
{
    return &active_menu->items[item];
}

void menu_update()
{
    button_state_t buttons = buttons_get_reset();

    if(buttons.button[0])
    {
        menu_item_t *item = menu_get_item(active_menu->selected_item);
        if(item && item->type == SUB_MENU && item->sub_menu)
        {
            active_menu = item->sub_menu;
            active_menu->selected_item = 0;
        }
        if(item && item->type == APPLICATION && item->application)
        {
            active_application = item->application;
            active_application->init();
        }
        if(item && item->type == INTEGER)
        {
            active_edit_integer = 1;
        }
    }

    if(buttons.button[1] && active_menu->selected_item > 0)
    {
        active_menu->selected_item--;
    }

    if(buttons.button[2])
    {
        if(menu_get_item(active_menu->selected_item+1)->type != MENU_END)
        {
            active_menu->selected_item++;
        }
    }

    if(buttons.button[3])
    {
        if(active_menu->parent)
        {
            if(active_menu == &settings)
            {
                config_save();
            }
            active_menu = active_menu->parent;
        }
    }
}

uint32_t edit_integer_scaling = 1;

void menu_edit_integer(U8GLIB *u8g, bool anything_updated)
{
    button_state_t buttons = buttons_get_reset();
    menu_item_t *item = menu_get_item(active_menu->selected_item);

    if(buttons.button[0])
    {
        edit_integer_scaling *= 10;
        if(edit_integer_scaling > 10000)
        {
            edit_integer_scaling = 1;
        }
    }

    if(buttons.button[1])
    {
        *item->integer += edit_integer_scaling;
    }

    if(buttons.button[2])
    {
        *item->integer -= edit_integer_scaling;
    }

    if(buttons.button[3])
    {
        active_edit_integer = 0;
    }
    
    if(anything_updated)
    {
        u8g->firstPage();
        do {
            u8g->setPrintPos(10, 10);
            u8g->printf("%d%s", *item->integer);
            u8g->setPrintPos(10, 20);
            u8g->printf("%dx", edit_integer_scaling);
            buttons_draw(u8g, "Scale", "Inc", "Dec", "Back");
        } while (u8g->nextPage());
    }
}

void menu_draw(U8GLIB *u8g)
{
    menu_item_t *item = NULL;
    u8g->firstPage();
    do {
        uint32_t i = 0;
        do
        {
            item = menu_get_item(i);
            if(active_menu->selected_item == i)
            {
                u8g->drawBox(0, i*10+2, 120, 10);
                u8g->setColorIndex(0);
            }
            else
            {
                u8g->setColorIndex(1);
            }

            u8g->setPrintPos(5, (i+1)*10);
            u8g->print(item->name);
            if(item->type == INTEGER)
            {
                uint32_t integer_scaled = *item->integer / (item->integer_scaling / item->integer_decimal);
                u8g->setPrintPos(60, (i+1)*10);
                u8g->print("= ");
                u8g->print(integer_scaled/item->integer_decimal);
                u8g->print(".");
                u8g->print(integer_scaled%item->integer_decimal);
                if(item->integer_suffix)
                {
                    u8g->print(item->integer_suffix);
                }
            }
            i++;
        } while(item && item->type != MENU_END);

        buttons_draw(u8g, "Enter", "Up", "Down", "Back");
    } while (u8g->nextPage());
}

void menu_run(U8GLIB *u8g, bool anything_updated)
{
    if(active_edit_integer)
    {
        menu_edit_integer(u8g, anything_updated);
    }
    else if(active_application)
    {
        if(!active_application->run(u8g, anything_updated))
        {
            active_application = NULL;
        }
    }
    else
    {
        if(anything_updated)
        {
            menu_update();
            menu_draw(u8g);
            
        }
    }
}

