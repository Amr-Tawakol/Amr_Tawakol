/*
 * Motion.c
 *
 *  Created on: Oct 31, 2023
 *      Author: Mahmoud
 */

#include "main.h"
#include <string.h>
#include "Motion.h"
//#include "parking.h"
extern UART_HandleTypeDef huart6;
extern char fullSpeed ;
extern char halfSpeed[] ;
extern char quarterSpeed[];
extern char zeroSpeed[];
void Forward_Moving(void)
{
	HAL_GPIO_WritePin(Backward_Right_GPIO_Port, Backward_Right_Pin, Motor_High);
	HAL_GPIO_WritePin(Forward_Right_GPIO_Port, Forward_Right_Pin, Motor_Low);
	HAL_GPIO_WritePin(Backward_Left_GPIO_Port, Backward_Left_Pin, Motor_Low);
	HAL_GPIO_WritePin(Forward_Left_GPIO_Port, Forward_Left_Pin, Motor_High);
}

void Left_Moving(void)
{
	HAL_GPIO_WritePin(Backward_Right_GPIO_Port, Backward_Right_Pin, Motor_High);
	HAL_GPIO_WritePin(Forward_Right_GPIO_Port, Forward_Right_Pin, Motor_Low);
	HAL_GPIO_WritePin(Backward_Left_GPIO_Port, Backward_Left_Pin, Motor_High);
	HAL_GPIO_WritePin(Forward_Left_GPIO_Port, Forward_Left_Pin, Motor_Low);
}

void Right_Moving(void)
{
	HAL_GPIO_WritePin(Backward_Right_GPIO_Port, Backward_Right_Pin, Motor_Low);
	HAL_GPIO_WritePin(Forward_Right_GPIO_Port, Forward_Right_Pin, Motor_High);
	HAL_GPIO_WritePin(Backward_Left_GPIO_Port, Backward_Left_Pin, Motor_Low);
	HAL_GPIO_WritePin(Forward_Left_GPIO_Port, Forward_Left_Pin, Motor_Low);
}

void Backword_Moving(void)
{
	HAL_GPIO_WritePin(Backward_Right_GPIO_Port, Backward_Right_Pin, Motor_Low);
	HAL_GPIO_WritePin(Forward_Right_GPIO_Port, Forward_Right_Pin, Motor_High);
	HAL_GPIO_WritePin(Backward_Left_GPIO_Port, Backward_Left_Pin, Motor_High);
	HAL_GPIO_WritePin(Forward_Left_GPIO_Port, Forward_Left_Pin, Motor_Low);
}

void Stop_Moving(void)
{
	HAL_GPIO_WritePin(Backward_Right_GPIO_Port, Backward_Right_Pin, Motor_Low);
	HAL_GPIO_WritePin(Forward_Right_GPIO_Port, Forward_Right_Pin, Motor_Low);
	HAL_GPIO_WritePin(Backward_Left_GPIO_Port, Backward_Left_Pin, Motor_Low);
	HAL_GPIO_WritePin(Forward_Left_GPIO_Port, Forward_Left_Pin, Motor_Low);
}

void FULL_SPEED (void)
{
	TIM1->CCR1=65535;
	TIM1->CCR2=65535;
	//HAL_UART_Transmit(&huart6, (uint8_t*)fullSpeed, strlen(fullSpeed), HAL_MAX_DELAY);
	//HAL_Delay(1000);
}
void HALF_SPEED (void)
{
	TIM1->CCR1=32767;
	TIM1->CCR2=32767;
	//HAL_UART_Transmit(&huart6, (uint8_t*)halfSpeed, strlen(halfSpeed), HAL_MAX_DELAY);
	//HAL_Delay(1000);
}

void QUARTER_SPEED (void)
{
	TIM1->CCR1=22000;
	TIM1->CCR2=22000;
	//HAL_UART_Transmit(&huart6, (uint8_t*)quarterSpeed, strlen(quarterSpeed), HAL_MAX_DELAY);
	//HAL_Delay(1000);
}
void NO_SPEED (void)
{
	TIM1->CCR1=0;
	TIM1->CCR2=0;
	HAL_UART_Transmit(&huart6, (uint8_t*)zeroSpeed, strlen(zeroSpeed), HAL_MAX_DELAY);
	HAL_Delay(1000);
}
