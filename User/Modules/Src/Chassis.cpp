/**
 *******************************************************************************
 * @file      : Chassis.cpp
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
#include "Chassis.h"
/* Private macro -------------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* External variables --------------------------------------------------------*/
Chassis_t Chassis;
int16_t Yaw_Encoder = 0;
int16_t Target_Encoder = 0;

/* Private function prototypes -----------------------------------------------*/

void Chassis_t::FollowCtrl()
{
    Pack.x_speed = -arm_sin_f32(Gimbal_Motor[1].angle_real / 180 * PI) * Pack.y_target + arm_cos_f32(Gimbal_Motor[1].angle_real / 180 * PI) * Pack.x_target;
    Pack.y_speed = arm_cos_f32(Gimbal_Motor[1].angle_real / 180 * PI) * Pack.y_target + arm_sin_f32(Gimbal_Motor[1].angle_real / 180 * PI) * Pack.x_target;
    if (0) {
    } else {
    }
}
