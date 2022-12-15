#ifndef SCENE_H
#define SCENE_H

typedef enum
{
  GO_STRAIGHT,
  TURN_LEFT,
  TURN_RIGHT,
  STOP
} command_t;

typedef struct
{
  command_t command;
  int time;
  scene_t *next;
} scene_t;

#endif
