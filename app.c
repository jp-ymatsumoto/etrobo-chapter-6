#include "app.h"
#include <stdio.h>
#include "parameters.h"

/**
 * 通常タスクで実行される関数
 */
void main_task(intptr_t unused)
{
  // センサーの入力ポートを設定する
  ev3_sensor_config(color_sensor, COLOR_SENSOR);

  // モーターの出力ポートを設定する
  ev3_motor_config(left_motor, MEDIUM_MOTOR);
  ev3_motor_config(right_motor, MEDIUM_MOTOR);

  // 周期タスクを開始する
  sta_cyc(RUN_TASK_CYC);

  // 通常タスクを待機状態にする
  slp_tsk();

  // 周期タスクを停止する
  stp_cyc(RUN_TASK_CYC);

  // モーターを停止する
  ev3_motor_stop(left_motor, true);
  ev3_motor_stop(right_motor, true);

  // タスクを終了する
  ext_tsk();
}

/**
 * 周期タスクで実行される関数
 */
void run_task(intptr_t unused)
{
  // 右ボタンの押下状態を取得する
  if (ev3_button_is_pressed(RIGHT_BUTTON))
  {
    // 通常タスクの待機状態を解除する
    wup_tsk(MAIN_TASK);
  }

  // 反射光の強さを取得する
  int reflect = ev3_color_sensor_get_reflect(color_sensor);
  // ターミナルにログを出力する
  printf("reflect: %3d\n", reflect);
  if (reflect > 20)
  {
    // 右上に前進する
    ev3_motor_set_power(left_motor, 60);
    ev3_motor_set_power(right_motor, 30);
  }
  else
  {
    // 左上に前進する
    ev3_motor_set_power(left_motor, 30);
    ev3_motor_set_power(right_motor, 60);
  }

  // タスクを終了する
  ext_tsk();
}
