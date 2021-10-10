/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
#define HX_DOUT_Pin GPIO_PIN_1
#define HX_DOUT_GPIO_Port GPIOF
#define CMES_ENA_Pin GPIO_PIN_2
#define CMES_ENA_GPIO_Port GPIOA
#define M2_PWM_Pin GPIO_PIN_3
#define M2_PWM_GPIO_Port GPIOA
#define M2_INB_Pin GPIO_PIN_4
#define M2_INB_GPIO_Port GPIOA
#define ENC_SW_Pin GPIO_PIN_5
#define ENC_SW_GPIO_Port GPIOA
#define ENC_B_Pin GPIO_PIN_6
#define ENC_B_GPIO_Port GPIOA
#define ENC_A_Pin GPIO_PIN_7
#define ENC_A_GPIO_Port GPIOA
#define M2_ENA_Pin GPIO_PIN_0
#define M2_ENA_GPIO_Port GPIOB
#define M2_INA_Pin GPIO_PIN_1
#define M2_INA_GPIO_Port GPIOB
#define M1_INB_Pin GPIO_PIN_8
#define M1_INB_GPIO_Port GPIOA
#define M1_INA_Pin GPIO_PIN_9
#define M1_INA_GPIO_Port GPIOA
#define M1_ENA_Pin GPIO_PIN_10
#define M1_ENA_GPIO_Port GPIOA
#define M1_PWM_Pin GPIO_PIN_5
#define M1_PWM_GPIO_Port GPIOB
#define OLED_SCL_Pin GPIO_PIN_6
#define OLED_SCL_GPIO_Port GPIOB
#define OLED_SDA_Pin GPIO_PIN_7
#define OLED_SDA_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
