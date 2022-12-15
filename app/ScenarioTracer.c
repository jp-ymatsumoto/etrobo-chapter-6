#include "ScenarioTracer.h"
#include "Scenario.h"
#include "Walker.h"
#include "SimpleTimer.h"
#include "Scene.h"

typedef enum
{
  UNDEFINED,
  INITIALIZE,
  WALKING
} state_t;

static state_t state = UNDEFINED; // 状態

static scene_t scenes[] = {
    {TURN_LEFT, 3000 / 10, 0},   // 左旋回3秒
    {GO_STRAIGHT, 1000 / 10, 0}, // 直進1秒
    {TURN_LEFT, 3000 / 10, 0},   // 左旋回3秒
    {GO_STRAIGHT, 1000 / 10, 0}  // 直進1秒
};

/**
 * コンストラクター
 */
void scenario_tracer_init()
{
  scenario_init(0);
  walker_init();
  simple_timer_init();

  for (int i = 0; i < (sizeof(scenes) / sizeof(scene_t)); i++)
  {
    scenario_add_scene(&scenes[i]);
  }
}

/**
 * シナリオに沿って走行する
 */
void scenario_tracer_run()
{
  switch (state)
  {
  case UNDEFINED:
    state = INITIALIZE;
    break;
  case INITIALIZE:
    walker_reset();
    state = WALKING;

    scenario_next_scene();
    walker_set_command(scenario_current_scene_command());
    simple_timer_set_time(scenario_current_scene_time());
    simple_timer_start();
    break;
  case WALKING:
    walker_run();
    if (simple_timer_is_over_timed())
    {
      simple_timer_stop();

      scenario_next_scene();
      walker_set_command(scenario_current_scene_command());
      simple_timer_set_time(scenario_current_scene_time());
      simple_timer_start();
    }
    break;
  default:
    break;
  }
}
