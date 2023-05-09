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
}

/**
 * @brief
 *   @arg       None
 * @retval      None
 * @note        None
 */
void InfantryGimbalTask()
{
    Infantry_Gimbal.Control();
}

void Infantry_Gimbal_t::Stop()
{
    Gimbal.Stop();
    Shoot.Stop();
}
