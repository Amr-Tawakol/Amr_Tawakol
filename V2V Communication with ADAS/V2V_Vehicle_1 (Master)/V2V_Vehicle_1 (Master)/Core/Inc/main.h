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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Forward_Right_Pin GPIO_PIN_14
#define Forward_Right_GPIO_Port GPIOC
#define Forward_Left_Pin GPIO_PIN_15
#define Forward_Left_GPIO_Port GPIOC
#define Front_Ultrasonic_Pin GPIO_PIN_0
#define Front_Ultrasonic_GPIO_Port GPIOA
#define Back_Ultrasonic_Pin GPIO_PIN_1
#define Back_Ultrasonic_GPIO_Port GPIOA
#define Right_Ultrasonic_Pin GPIO_PIN_2
#define Right_Ultrasonic_GPIO_Port GPIOA
#define Left_Ultrasonic_Pin GPIO_PIN_3
#define Left_Ultrasonic_GPIO_Port GPIOA
#define Right_Blind_Pin GPIO_PIN_4
#define Right_Blind_GPIO_Port GPIOA
#define Left_Blind_Pin GPIO_PIN_5
#define Left_Blind_GPIO_Port GPIOA
#define Selector_0_Pin GPIO_PIN_6
#define Selector_0_GPIO_Port GPIOA
#define Backward_Right_Pin GPIO_PIN_7
#define Backward_Right_GPIO_Port GPIOA
#define Selector_1_Pin GPIO_PIN_0
#define Selector_1_GPIO_Port GPIOB
#define CE_Pin GPIO_PIN_1
#define CE_GPIO_Port GPIOB
#define CSN_Pin GPIO_PIN_2
#define CSN_GPIO_Port GPIOB
#define Backward_Left_Pin GPIO_PIN_12
#define Backward_Left_GPIO_Port GPIOB
#define Buzzer_LED_Pin GPIO_PIN_13
#define Buzzer_LED_GPIO_Port GPIOB
#define Selector_2_Pin GPIO_PIN_15
#define Selector_2_GPIO_Port GPIOA
#define Right_IR_Pin GPIO_PIN_4
#define Right_IR_GPIO_Port GPIOB
#define Left_IR_Pin GPIO_PIN_7
#define Left_IR_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
