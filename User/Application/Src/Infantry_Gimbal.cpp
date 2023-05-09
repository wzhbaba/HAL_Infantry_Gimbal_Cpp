/**
 *******************************************************************************
 * @file      : Infantry_Gimbal.cpp
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
#include "Infantry_Gimbal.h"
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
void Gimbal_Init()
{
    Gimbal.Position[0].Set(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    Gimbal.Position[1].Set(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    Gimbal.Speed[0].Set(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    Gimbal.Speed[1].Set(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    Gimbal.Current[0].Set(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    Gimbal.Current[1].Set(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

    Shoot.Friction_Speed[0].Set(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    Shoot.Friction_Speed[1].Set(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    Shoot.Friction_Current[0].Set(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    Shoot.Friction_Current[1].Set(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

    Shoot.Trigger_Position.Set(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    Shoot.Trigger_Speed.Set(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    Shoot.Trigger_Current.Set(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
}

void GimbalTask()
{
}
