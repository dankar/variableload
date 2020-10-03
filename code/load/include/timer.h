#ifndef _TIMER_H_
#define _TIMER_H_

#include <stdint.h>

#define SECONDS(x) (x * 1000)

struct timer_t
{
	uint32_t deadline;
	uint32_t set_time;
};

struct error_t
{
	bool warning;
	uint32_t timeout;
	uint32_t warn_time;
};

void timer_init(timer_t *timer, uint32_t set_time, bool initial);
void timer_reset(timer_t *timer);
bool timer_elapsed(timer_t *timer);

void error_init(error_t *error, uint32_t timeout);
void error_set(error_t *error, bool value);
bool error_get(error_t *error);

#endif