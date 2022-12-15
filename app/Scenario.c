#include "Scenario.h"

scene_t *top_scene;     // 先頭のシーン
scene_t *current_scene; // 現在のシーン

static scene_t *scenario_current_scene();
static scene_t *scenario_top_scene();

/**
 * コンストラクター
 * @param scene 先頭のシーン
 */
void scenario_init(scene_t *scene)
{
  top_scene = scene;
  current_scene = scene;
}

/**
 * シーンの追加
 * @param scene 追加するシーン
 */
void scenario_add_scene(scene_t *scene)
{
  if (top_scene == 0)
  {
    top_scene = scene;
  }
  else
  {
    scene_t *s = scenario_top_scene();
    while (s->next != scenario_top_scene())
    {
      s = s->next;
    }
    s->next = scene;
  }
  scene->next = scenario_top_scene();
}

/**
 * 次のシーンに進める
 * @return
 */
scene_t *scenario_next_scene()
{
  if (current_scene != 0)
  {
    current_scene = current_scene->next;
  }
  else
  {
    current_scene = top_scene;
  }
  return current_scene;
}

/**
 * 現在のシーンの実行コマンドを取得する
 * @return 実行コマンド
 */
command_t scenario_current_scene_command()
{

  return current_scene == 0 ? GO_STRAIGHT : current_scene->command;
}

/**
 * 現在のシーンの実行時間を取得する
 * @return 実行時間
 */
int scenario_current_scene_time()
{
  return current_scene == 0 ? 0 : current_scene->time;
}

static scene_t *scenario_current_scene()
{
  return current_scene;
}

static scene_t *scenario_top_scene()
{
  return top_scene;
}
