#include "timer.h"
#include <Arduino.h>

void timer_init(timer_t *timer, uint32_t set_time, bool initial)
{
	timer->set_time = set_time;
	
	if(initial)
	{
		timer->deadline = 0;
	}
	else
	{
		timer_reset(timer);
	}
}

void timer_reset(timer_t *timer)
{
	timer->deadline = millis() + timer->set_time;
}

bool timer_elapsed(timer_t *timer)
{
	if(timer->deadline < millis())
	{
		timer_reset(timer);
		return true;
	}
	else
	{
		return false;
	}
}

void error_init(error_t *error, uint32_t timeout)
{
	error->warning = false;
	error->timeout = timeout;
}
void error_set(error_t *error, bool value)
{
	if(value)
	{
		if(!error->warning)
		{
			error->warning = true;
			error->warn_time = millis();
		}
	}
	else
	{
		error->warning = false;
	}
}
bool error_get(error_t *error)
{
	if(!error->warning)
	{
		return false;
	} 
	else if(millis() > (error->warn_time + error->timeout))
	{
		return true;
	}
	else
	{
		return false;
	}
}