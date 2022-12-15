#include "SimpleTimer.h"

static int target_time = 0;       // タイマーの制限時間
static int current_time = 0;      // タイマーの経過時間
static bool_t is_started = false; // タイマーの動作状態

static void simple_timer_counter();

/**
 * コンストラクター
 */
void simple_timer_init()
{
}

/**
 * タイマーを開始する
 */
void simple_timer_start()
{
  if (is_started == false)
  {
    is_started = true;
  }
}

/**
 * タイマーを停止する
 */
void simple_timer_stop()
{
  if (is_started == true)
  {
    is_started = false;
  }
}

/**
 * タイマーの制限時間を設定する
 * @param time 制限時間
 */
void simple_timer_set_time(int time)
{
  if (is_started == false)
  {
    target_time = time;
  }
}

/**
 * タイマーが制限時間を超えているか
 * @return 制限時間を超えているか
 */
bool_t simple_timer_is_over_timed()
{
  if (is_started == true)
  {
    simple_timer_counter();
    if (target_time <= current_time)
    {
      return true;
    }
  }
  return false;
}

/**
 * タイマーの経過時間を更新する
 */
static void simple_timer_counter()
{
  current_time++;
}
