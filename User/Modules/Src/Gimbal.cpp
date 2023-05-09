/**
 *******************************************************************************
 * @file      : Gimbal.cpp
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
#include "Gimbal.h"
/* Private macro -------------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* External variables --------------------------------------------------------*/
Gimbal_t Gimbal;
/* Private function prototypes -----------------------------------------------*/

void Gimbal_t::SetPitchPosition(float set)
{
    Position[0].ref = set;
}

void Gimbal_t::SetYawPosition(float set)
{
    Position[1].ref = set;
}

void Gimbal_t::AngleCalc()
{
    Position[0].ref = 0.0f;
    Position[1].ref = 0.0f;

    Position[0].fdb = IMU.Euler[0];
    Position[0].fdb = IMU.Euler[2];

    for (short i = 0; i < 2; ++i) {
        Position[i].NormalCalc();
    }
}

void Gimbal_t::SpeedCalc()
{
    Speed[0].ref = Position[0].output;
    Speed[0].fdb = IMU.Gyro[0];
    Speed[1].ref = Position[1].output;
    Speed[1].fdb = IMU.Gyro[1];

    for (short i = 0; i < 2; ++i) {
        Speed[i].NormalCalc();
    }
}

void Gimbal_t::CurrentCalc()
{
    for (short i = 0; i < 2; ++i) {
        Current[i].ref = Speed[i].output;
        Current[i].fdb = Gimbal_Motor[i].torque_current;
        Current[i].NormalCalc();
    }
}

void Gimbal_t::Stop()
{
    for (short i = 0; i < 2; ++i) {
        Current[i].output = 0.0f;
    }
}

void Gimbal_t::Control()
{
    AngleCalc();
    SpeedCalc();
    CurrentCalc();
}