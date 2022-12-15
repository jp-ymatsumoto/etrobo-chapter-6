#ifndef SIMPLE_TIMER_H
#define SIMPLE_TIMER_H

#include "ev3api.h"

void simple_timer_init();
void simple_timer_start();
void simple_timer_stop();
void simple_timer_set_time(int time);
bool_t simple_timer_is_over_timed();

#endif
