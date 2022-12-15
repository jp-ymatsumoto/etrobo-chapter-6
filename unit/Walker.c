#include "ev3api.h"
#include "parameters.h"
#include "Walker.h"

static int l_power = 40;           // 左モーターのパワー
static int r_power = 40;           // 右モーターのパワー
static int is_initialized = false; // 回転角度のリセットの有無

static void walker_set_power(int left_motor_power, int right_motor_power);

/**
 * コンストラクター
 */
void walker_init()
{
}

/**
 * 左右のモーターの回転角度をリセットする
 */
void walker_reset()
{
  if (is_initialized == false)
  {
    ev3_motor_reset_counts(left_motor);
    ev3_motor_reset_counts(right_motor);
    is_initialized = true;
  }
}

/**
 * 走行コマンドから左右のモーターのパワーを設定する
 */
void walker_set_command(command_t command)
{
  switch (command)
  {
  case GO_STRAIGHT:
    walker_set_power(60, 60);
    break;
  case TURN_LEFT:
    walker_set_power(30, 60);
    break;
  case TURN_RIGHT:
    walker_set_power(60, 30);
    break;
  default:
    walker_set_power(0, 0);
    break;
  }
}

/**
 * 左右のモーターを回転させる
 */
void walker_run()
{
  ev3_motor_set_power(left_motor, l_power);
  ev3_motor_set_power(right_motor, r_power);
}

/**
 * 左右のモーターのパワーを設定する
 * @param left_motor_power 左モーターのパワー
 * @param right_motor_power 右モーターのパワー
 */
static void walker_set_power(int left_motor_power, int right_motor_power)
{
  l_power = left_motor_power;
  r_power = right_motor_power;
}
