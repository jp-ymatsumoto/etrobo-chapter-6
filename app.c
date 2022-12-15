#include "app.h"
#include <stdio.h>
#include "parameters.h"
#include "ScenarioTracerWithStarter.h"

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

  scenario_tracer_with_starter_init();

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

  scenario_tracer_with_starter_run();

  // タスクを終了する
  ext_tsk();
}
