#ifndef SCENE_H
#define SCENE_H

typedef enum
{
  GO_STRAIGHT,
  TURN_LEFT,
  TURN_RIGHT,
  STOP
} command_t;

typedef struct scene_tt
{
  command_t command;
  int time;
  struct scene_tt *next;
} scene_t;

#endif
