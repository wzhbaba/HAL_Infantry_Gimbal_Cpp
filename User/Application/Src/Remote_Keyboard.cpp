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
/* Private macro -------------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private types -------------------------------------------------------------*/
void RemoteChassisCtrl();
void RemoteGimbalCtrl();
void RemoteShootCtrl();
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
    } else if (Remote.Pack.s2 == 2) {
        Infantry_Gimbal.Stop();
    }
}

void RemoteChassisCtrl()
{
    Chassis.Pack.x_target = Remote.Pack.ch2;
    Chassis.Pack.y_target = Remote.Pack.ch3;
}

void RemoteGimbalCtrl()
{
    Gimbal.SetPitchPosition((Remote.Pack.ch1 / 660.0f) * 0.25f);
    Gimbal.SetYawPosition((Remote.Pack.ch0 / 660.0f) * 0.25f);
}

void RemoteShootCtrl()
{
    static uint8_t flag = 0;
    Shoot.SetFricSpeed(5000.0f);
    if (Remote.Pack.s1 == 1) {
        flag = 1;
        Shoot.Shoot_Flag = ANGLE_FLAG;
        Shoot.SetTriggerPos(0.0f);
    }
    if (Remote.Pack.s1 == 3 && flag == 1) {
        Shoot.Shoot_Flag = ANGLE_FLAG;
        Shoot.SetTriggerPos(45 * 36.0f);
        flag = 0;
    }
    if (Remote.Pack.s1 == 2) {
        Shoot.Shoot_Flag = SPEED_FLAG;
        Shoot.SetTriggerSpeed(3.125f * 60 * 36.0f);
    }
}
