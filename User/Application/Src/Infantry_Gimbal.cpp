/**
 *******************************************************************************
 * @file      : Infantry_Gimbal.cpp
 * @brief     :
 * @history   :
 *  Version     Date            Author          Note
 *  V1.0.0      2023-05-09      Jerry Gong      第一版
 *******************************************************************************
 * @attention :
 *******************************************************************************
 *  Copyright (c) 2023 Reborn Team, USTB.
 *  All Rights Reserved.
 *******************************************************************************
 */
/* Includes ------------------------------------------------------------------*/
#include "Infantry_Gimbal.h"

#include "Chassis.h"
#include "VOFA.h"
/* Private macro -------------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* External variables --------------------------------------------------------*/
Infantry_Gimbal_t Infantry_Gimbal;
/* Private function prototypes -----------------------------------------------*/

/**
 * @brief
 *   @arg       None
 * @retval      None
 * @note        None
 */
void GimbalInit()
{
    Gimbal.Position[0].Set(25.0f, 0.1f, 10.0f, 10000.0f, 2500.0f, 2500.0f, 15000.0f);
    Gimbal.Position[1].Set(20.0f, 0.0f, 5.0f, 10000.0f, 2500.0f, 2500.0f, 15000.0f);
    Gimbal.Speed[0].Set(50.0f, 0.1f, 0.0f, 25000.0f, 5000.0f, 0.0f, 30000.0f);
    Gimbal.Speed[1].Set(60.0f, 0.0f, 0.0f, 25000.0f, 2500.0f, 2500.0f, 30000.0f);

    Shoot.Friction_Speed[0].Set(10.0f, 0.2f, 0.0f, 10000.0f, 2500.0f, 2500.0f, 15000.0f);
    Shoot.Friction_Speed[1].Set(10.0f, 0.2f, 0.0f, 10000.0f, 2500.0f, 2500.0f, 15000.0f);
    Shoot.Friction_Current[0].Set(1.0f, 0.0f, 0.0f, 10000.0f, 10000.0f, 10000.0f, 30000.0f);
    Shoot.Friction_Current[1].Set(1.0f, 0.0f, 0.0f, 10000.0f, 10000.0f, 10000.0f, 30000.0f);

    Shoot.Trigger_Position.Set(5.0f, 0.0f, 0.0f, 5000.0f, 2500.0f, 0.0f, 15000.0f);
    Shoot.Trigger_Speed.Set(10.0f, 0.0f, 0.0f, 12500.0f, 2500.0f, 0.0f, 15000.0f);
    Shoot.Trigger_Current.Set(1.5f, 0.0f, 0.0f, 30000.0f, 0.0f, 0.0f, 30000.0f);

    Chassis.Follow.Set(5.0f, 0.0f, 0.0f, 220.0f, 220.0f, 220.0f, 660.0f);
}

/**
 * @brief
 *   @arg       None
 * @retval      None
 * @note        None
 */
void Infantry_Gimbal_t::Control()
{
    Gimbal.Control();
    Shoot.Control();
    Chassis.FollowCtrl();
    CANx_PackProcess_Data(&hcan1, 0x1FF, 0x08, 0, (int16_t)Gimbal.Speed[1].output, 0, 0);
    CANx_PackProcess_Data(&hcan2, 0x200, 0x08, (int16_t)Shoot.Friction_Current[0].output, (int16_t)Shoot.Friction_Current[1].output, (int16_t)Shoot.Trigger_Current.output, 0);
    CANx_PackProcess_Data(&hcan2, 0x1FF, 0x08, (int16_t)-Gimbal.Speed[0].output, 0, 0, 0);
    CANx_PackProcess_Data(&hcan1, 0x112, 0x08, (int16_t)Chassis.Pack.x_speed, (int16_t)Chassis.Pack.y_speed, (int16_t)Chassis.Pack.r_speed, 0);
}

void Infantry_Gimbal_t::Stop()
{
    Gimbal.Stop();
    Shoot.Stop();
    Chassis.Stop();
    CANx_PackProcess_Data(&hcan1, 0x1FF, 0x08, 0, (int16_t)Gimbal.Current[1].output, 0, 0);
    CANx_PackProcess_Data(&hcan2, 0x200, 0x08, (int16_t)Shoot.Friction_Current[0].output, (int16_t)Shoot.Friction_Current[1].output, (int16_t)Shoot.Trigger_Current.output, 0);
    CANx_PackProcess_Data(&hcan2, 0x1FF, 0x08, (int16_t)-Gimbal.Current[0].output, 0, 0, 0);
    CANx_PackProcess_Data(&hcan2, 0x112, 0x08, (int16_t)Chassis.Pack.x_speed, (int16_t)Chassis.Pack.y_speed, (int16_t)Chassis.Pack.r_speed, 0);
}

/**
 * @brief
 *   @arg       None
 * @retval      None
 * @note        None
 */
void InfantryGimbalTask()
{
    if (Remote.Pack.s2 == 2) {
        Infantry_Gimbal.Stop();
    } else {
        Infantry_Gimbal.Control();
    }
    VOFA.SendData4(Gimbal.Position[0].output, Gimbal.Position[1].output, Gimbal.Speed[0].output, Gimbal.Speed[1].output);
}
