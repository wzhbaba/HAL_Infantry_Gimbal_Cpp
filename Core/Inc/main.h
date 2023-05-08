/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "drv_can.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define IMU_Chassic_Pin GPIO_PIN_0
#define IMU_Chassic_GPIO_Port GPIOE
#define Remote_Pin GPIO_PIN_7
#define Remote_GPIO_Port GPIOB
#define IMU_Gimbal_Pin GPIO_PIN_9
#define IMU_Gimbal_GPIO_Port GPIOG
#define POWER_CTRL1_Pin GPIO_PIN_2
#define POWER_CTRL1_GPIO_Port GPIOH
#define POWER_CTRL2_Pin GPIO_PIN_3
#define POWER_CTRL2_GPIO_Port GPIOH
#define POWER_CTRL3_Pin GPIO_PIN_4
#define POWER_CTRL3_GPIO_Port GPIOH
#define POWER_CTRL4_Pin GPIO_PIN_5
#define POWER_CTRL4_GPIO_Port GPIOH
#define SendMainData_Pin GPIO_PIN_8
#define SendMainData_GPIO_Port GPIOE
#define LED_R_Pin GPIO_PIN_11
#define LED_R_GPIO_Port GPIOE
#define LED_G_Pin GPIO_PIN_14
#define LED_G_GPIO_Port GPIOF
#define CameraDataReceive_Pin GPIO_PIN_7
#define CameraDataReceive_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
