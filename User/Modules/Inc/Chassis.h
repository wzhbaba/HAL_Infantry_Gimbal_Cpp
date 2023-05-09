/**
 *******************************************************************************
 * @file      : Chassis.h
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CHASSIS_H_
#define __CHASSIS_H_

#ifdef __cplusplus

/* Includes ------------------------------------------------------------------*/
#include "CommomInc.h"
#include "arm_math.h"
/* Exported macro ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
struct Chassis_s {
    int16_t x_speed;
    int16_t y_speed;
    int16_t r_speed;
    int16_t x_target;
    int16_t y_target;
    int16_t r_target;
};

class Chassis_t
{
   public:
    Chassis_s Pack;
    PID_Def Chassis_Follow;
    void FollowCtrl();
};

/* Exported variables --------------------------------------------------------*/
extern int16_t Yaw_Encoder;
extern int16_t Target_Encoder;

/* Exported function prototypes ----------------------------------------------*/

#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported function prototypes ----------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __FILE_H_ */
