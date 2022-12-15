#include "ScenarioTracerWithStarter.h"
#include "Starter.h"
#include "ScenarioTracer.h"

typedef enum
{
  UNDEFINED,
  WAITING_FOR_START,
  WALKING
} state_t;

static state_t state = UNDEFINED; // 状態

/**
 * コンストラクター
 */
void scenario_tracer_with_starter_init()
{
  starter_init();
  scenario_tracer_init();
}

/**
 * スタート指示を待ってシナリオに沿って走行する
 */
void scenario_tracer_with_starter_run()
{
  switch (state)
  {
  case UNDEFINED:
    state = WAITING_FOR_START;
    break;
  case WAITING_FOR_START:
    if (starter_is_pressed())
    {
      state = WALKING;
    }
    break;
  case WALKING:
    scenario_tracer_run();
    break;
  default:
    break;
  }
}
