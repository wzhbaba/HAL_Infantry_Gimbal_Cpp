/**
 *******************************************************************************
 * @file      : DR16.cpp
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
#include <DR16.h>

/* Private macro -------------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
DBUS_Def Remote;
/* External variables --------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/**
 * @brief
 * @param       pData:
 *   @arg       None
 * @retval      None
 * @note        None
 */
void DBUS_Def::SbusToRc(uint8_t* pData)
{
    Pack.ch0 = ((int16_t)pData[0] | ((int16_t)pData[1] << 8)) & 0x07FF;
    Pack.ch1 = (((int16_t)pData[1] >> 3) | ((int16_t)pData[2] << 5)) & 0x07FF;
    Pack.ch2 = (((int16_t)pData[2] >> 6) | ((int16_t)pData[3] << 2) | ((int16_t)pData[4] << 10)) & 0x07FF;
    Pack.ch3 = (((int16_t)pData[4] >> 1) | ((int16_t)pData[5] << 7)) & 0x07FF;

    Pack.s1 = ((pData[5] >> 4) & 0x000C) >> 2;
    Pack.s2 = ((pData[5] >> 4) & 0x0003);

    Pack.mouse_x = ((int16_t)pData[6]) | ((int16_t)pData[7] << 8);
    Pack.mouse_y = ((int16_t)pData[8]) | ((int16_t)pData[9] << 8);
    Pack.mouse_z = ((int16_t)pData[10]) | ((int16_t)pData[11] << 8);

    Pack.press_l = pData[12];
    Pack.press_r = pData[13];

    Pack.key = ((int16_t)pData[14]) | ((int16_t)pData[15] << 8);
    Pack.ch0 -= 1024;
    Pack.ch1 -= 1024;
    Pack.ch2 -= 1024;
    Pack.ch3 -= 1024;
}