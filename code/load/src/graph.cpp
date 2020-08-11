
#include <Arduino.h>
#include <U8glib.h>
#include "graph.h"

#define NUM_GRAPH_POINTS 100

log_point_t dch_log[NUM_GRAPH_POINTS] = {0};
uint16_t current_point = 0;
uint32_t graph_time_scale = 500; // ms

void graph_init()
{
    graph_time_scale = 500;
    current_point = 0;
}

void graph_add_point(uint16_t voltage, uint16_t current)
{
    if(current_point < NUM_GRAPH_POINTS)
    {
        log_point_t point = {voltage, current};
        dch_log[current_point++] = point;
    }
    else
    {
        graph_time_scale *= 2;
        for(size_t i = 0; i < current_point / 2; i++)
        {
            dch_log[i] = dch_log[i*2];
        }
        current_point /= 2;
    }
}
void graph_draw(U8GLIB *u8g, uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{
    u8g->drawFrame(x, y, w, h);

    uint16_t max_voltage = 0;
    uint16_t min_voltage = 0xffff;

    if(current_point < 2)
        return;

    for(size_t i = 0; i < current_point; i++)
    {
        if(dch_log[i].voltage > max_voltage)
            max_voltage = dch_log[i].voltage;
        if(dch_log[i].voltage < min_voltage)
            min_voltage = dch_log[i].voltage;
    }

    max_voltage += 500;
    min_voltage -= 500;

    float x_scaling = float(w) / current_point;
    float y_scaling = float(h) / (max_voltage - min_voltage);

    for(size_t i = 0; i < current_point-1; i++)
    {
        u8g->drawLine(x + i * x_scaling, (y + h) - y_scaling * (dch_log[i].voltage - min_voltage), x + (i+1) * x_scaling, (y + h) - y_scaling * (dch_log[i+1].voltage - min_voltage) );
    }
}