#ifndef SCENARIO_H
#define SCENARIO_H

#include "Scene.h"

void scenario_init(scene_t *scene);
void scenario_add_scene(scene_t *scene);
scene_t *scenario_next_scene();
command_t scenario_current_scene_command();
int scenario_current_scene_time();

#endif
