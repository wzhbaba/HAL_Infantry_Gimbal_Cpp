/**
 *******************************************************************************
 * @file      : Remote_Keyboard.cpp
 * @brief     :
 * @history   :
 *  Version     Date            Author          Note
 *  V0.9.0      yyyy-mm-dd      <author>        1. <note>
 *******************************************************************************
 * @attention :
 *******************************************************************************
 *  Copyright (c) 2023 Reborn Team, USTB.
 *  All Rights Reserved.
 *******************************************************************************
 */
/* Includes ------------------------------------------------------------------*/
#include "Remote_Keyboard.h"

#include "DR16.h"
#include "Infantry_Gimbal.h"
#include "Referee.h"
#include "tim.h"
/* Private macro -------------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private types -------------------------------------------------------------*/
void RemoteChassisCtrl();
void RemoteGimbalCtrl();
void RemoteShootCtrl();
void KeyboardChassisCtrl();
void KeyboardGimbalCtrl();
void KeyboardShootCtrl();
/* Private variables ---------------------------------------------------------*/
/* External variables --------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

void ModeTask()
{
    if (Remote.Pack.s2 == 1) {
        RemoteChassisCtrl();
        RemoteGimbalCtrl();
        RemoteShootCtrl();
    } else if (Remote.Pack.s2 == 3) {
        KeyboardChassisCtrl();
        KeyboardGimbalCtrl();
        KeyboardShootCtrl();
    } else if (Remote.Pack.s2 == 2) {
        Infantry_Gimbal.Stop();
    }
}

void RemoteChassisCtrl()
{
    Chassis.Pack.x_target = Remote.Pack.ch2 * 1.5f;
    Chassis.Pack.y_target = Remote.Pack.ch3 * 1.5f;
}

void RemoteGimbalCtrl()
{
    Gimbal.SetPitchPosition((Remote.Pack.ch1 / 660.0f) * 0.25f);
    Gimbal.SetYawPosition((Remote.Pack.ch0 / 660.0f) * 0.25f);
}

/**
 * @brief
 *   @arg       None
 * @retval      None
 * @note        None
 */
void RemoteShootCtrl()
{
    static uint8_t flag = 0;
    Shoot.SetFricSpeed(4950.0f);
    if (Remote.Pack.s1 == 1) {
        flag = 1;
        Shoot.Shoot_Flag = ANGLE_FLAG;
        Shoot.SetTriggerPos(0.0f);
        __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 810);
    }
    if (Remote.Pack.s1 == 3 && flag == 1) {
        Shoot.Shoot_Flag = ANGLE_FLAG;
        Shoot.SetTriggerPos(45 * 36.0f);
        flag = 0;
        __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 810);
    }
    if (Remote.Pack.s1 == 2) {
        Shoot.Shoot_Flag = SPEED_FLAG;
        Shoot.SetTriggerSpeed(3.125f * 60 * 36.0f);
        __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 520);
    }
}

void KeyboardChassisCtrl()
{
    if (Referee.KeyState[REFEREE_KEY_W].isPressed == 1) {
        Chassis.Pack.y_target = 660;
    } else if (Referee.KeyState[REFEREE_KEY_S].isPressed == 1) {
        Chassis.Pack.y_target = -660;
    } else {
        Chassis.Pack.y_target = 0;
    }

    if (Referee.KeyState[REFEREE_KEY_A].isPressed == 1) {
        Chassis.Pack.x_target = -660;
    } else if (Referee.KeyState[REFEREE_KEY_D].isPressed == 1) {
        Chassis.Pack.x_target = 660;
    } else {
        Chassis.Pack.x_target = 0;
    }

    if (Referee.KeyState[REFEREE_KEY_G].isTicked == 1) {
        Chassis.Pack.r_target = 660;
        Chassis.rotate_flag = 1;
    } else {
        Chassis.Pack.r_target = 0;
        Chassis.rotate_flag = 0;
    }

    if (Referee.KeyState[REFEREE_KEY_SHIFT].isPressed == 0) {
        Chassis.cap_flag = 0;
    } else {
        Chassis.cap_flag = 1;
    }
}

void KeyboardGimbalCtrl()
{
    Gimbal.SetPitchPosition(-Referee.CommaData.mouse_y * 0.005f);
    Gimbal.SetYawPosition(Referee.CommaData.mouse_x * 0.006f);
}

void KeyboardShootCtrl()
{
    static uint8_t flag = 0;
    static uint8_t reserve_flag = 0;
    static uint16_t time_out = 0;
    static uint8_t shoot_allow_flag = 0;
    static uint8_t count_flag = 1;
    static uint8_t change_flag = 1;

    static float shoot_speed;

    if (Referee.KeyState[REFEREE_KEY_Z].isTicked == 1) {
        __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 810);
        Chassis.servo_flag = 1;
    } else {
        __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 520);
        Chassis.servo_flag = 0;
    }

    if (Referee.GameRobotStat.mains_power_shooter_output == 1) {
        if (Referee.KeyState[REFEREE_KEY_X].isTicked == 1) {
            Chassis.fric_flag = 1;
            if (Referee.GameRobotStat.shooter_id1_17mm_speed_limit == 15) {
                Shoot.SetFricSpeed(4600.0f);
            } else if (Referee.GameRobotStat.shooter_id1_17mm_speed_limit == 18) {
                Shoot.SetFricSpeed(5000.0f);
            } else if (Referee.GameRobotStat.shooter_id1_17mm_speed_limit == 30) {
                Shoot.SetFricSpeed(7300.0f);
            } else {
                Shoot.SetFricSpeed(4600.0f);
            }

            if (Referee.KeyState[REFEREE_KEY_R].isTicked == 1) {
                Chassis.shoot_flag = 1;
                if (change_flag == 1) {
                    Shoot.SetTriggerPos(0.0f);
                    Shoot.Shoot_Flag = ANGLE_FLAG;
                    change_flag = 0;
                }
                if (count_flag) {
                    time_out++;
                    if (time_out >= 150) {
                        time_out = 0;
                        count_flag = 0;
                        shoot_allow_flag = 1;
                    }
                }
                if (Referee.KeyState[REFEREE_KEY_V].isTicked == 1 || reserve_flag == 1) {
                    Shoot.SetTriggerPos(-45 * 36.0f);
                    Referee.KeyState[REFEREE_KEY_V].isTicked = 0;
                    reserve_flag = 0;
                }
                if (Referee.KeyState[REFEREE_MOUSE_L].isPressed == 0) {
                    flag = 1;
                }
                if (Referee.KeyState[REFEREE_MOUSE_L].isPressed == 1 && flag == 1 && shoot_allow_flag == 1) {
                    Shoot.SetTriggerPos(45 * 36.0f);
                    flag = 0;
                    shoot_allow_flag = 0;
                    count_flag = 1;
                }
            } else {
                Chassis.shoot_flag = 0;
                if (Referee.KeyState[REFEREE_MOUSE_L].isPressed == 1) {
                    Shoot.Shoot_Flag = SPEED_FLAG;
                    if (Referee.GameRobotStat.shooter_id1_17mm_cooling_limit - Referee.PowerHeatData.shooter_id1_17mm_cooling_heat > 40) {
                        Shoot.SetTriggerSpeed(3.125f * 60 * 36.0f);
                    } else {
                        Shoot.SetTriggerSpeed(0.0f);
                    }
                } else {
                    Shoot.SetTriggerSpeed(0.0f);
                }
                count_flag = 1;
                reserve_flag = 1;
                change_flag = 1;
            }
        } else {
            Chassis.fric_flag = 0;
            Shoot.SetFricSpeed(0.0f);
        }
    } else {
        Chassis.fric_flag = 0;
        Shoot.SetFricSpeed(0.0f);
    }
}