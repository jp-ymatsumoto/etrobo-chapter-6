#ifndef WALKER_H
#define WALKER_H

#include "Scene.h"

void walker_init();
void walker_reset();
void walker_set_command(command_t command);
void walker_run();

#endif
