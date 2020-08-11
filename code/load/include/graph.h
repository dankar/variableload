#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <U8glib.h>

typedef struct 
{
    uint16_t voltage;
    uint16_t current;
} log_point_t;

extern uint32_t graph_time_scale;

void graph_init();
void graph_add_point(uint16_t voltage, uint16_t current);
void graph_draw(U8GLIB *u8g, uint16_t x, uint16_t y, uint16_t w, uint16_t h);

#endif