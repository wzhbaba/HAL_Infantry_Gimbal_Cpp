/**
 *******************************************************************************
 * @file      : Shoot.cpp
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
#include "Shoot.h"
/* Private macro -------------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* External variables --------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

void Shoot_t::FrictionControl()
{
    Friction_Speed[0].ref = 0.0f;
    Friction_Speed[1].ref = 0.0f;

    for (short i = 0; i < 2; ++i) {
        Friction_Speed[i].fdb = 0.0f;
        Friction_Speed[i].NormalCalc();
    }
}

void Shoot_t::TriggerControl()
{
    Trigger_Position.ref = 0.0f;
    Trigger_Position.fdb = 0.0f;
    Trigger_Position.NormalCalc();

    Trigger_Speed.ref = Trigger_Position.output;
    Trigger_Speed.fdb = 0.0f;
    Trigger_Speed.NormalCalc();

    Trigger_Current.ref = Trigger_Speed.output;
    Trigger_Current.fdb = 0.0f;
    Trigger_Current.NormalCalc();
}

void Shoot_t::Control()
{
    FrictionControl();
    TriggerControl();
}

void Shoot_t::Stop()
{
    for (short i = 0; i < 2; ++i) {
        Friction_Speed[i].output = 0.0f;
    }
    Trigger_Current.output = 0.0f;
}