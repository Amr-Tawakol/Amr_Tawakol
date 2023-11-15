/*
 * Ultrasonic.c
 *
 *  Created on: Oct 24, 2023
 *      Author: Mahmoud
 */
#include "main.h"
#include "Ultrasonic.h"

extern TIM_HandleTypeDef htim3;

//microsecond delay function
void delay(uint8_t time)
{
	__HAL_TIM_SET_COUNTER(&htim3, 0);
	while(__HAL_TIM_GET_COUNTER(&htim3) < time);
}

void Front_Sensor_Read(uint8_t *Front_Distance)
{
	uint32_t pMillis;
	uint32_t value1 = 0;
	uint32_t value2 = 0;

	HAL_GPIO_WritePin(Front_Ultrasonic_GPIO_Port, Front_Ultrasonic_Pin, GPIO_PIN_SET); //pull the trig pin high
	delay(10); //wait for 10us
	HAL_GPIO_WritePin(Front_Ultrasonic_GPIO_Port, Front_Ultrasonic_Pin, GPIO_PIN_RESET);	//pull the trig pin low

	pMillis = HAL_GetTick(); //used this to avoid infinite while loop (for timeout)
	//wait for the echo pin to get high
	while(!(HAL_GPIO_ReadPin(Echo_Port, Echo_Pin)) && (pMillis + 10 > HAL_GetTick()));
	value1 = __HAL_TIM_GET_COUNTER(&htim3); //save the first reading

	pMillis = HAL_GetTick(); //used this to avoid infinite while loop (for timeout)
	//wait for the echo pin to get low
	while((HAL_GPIO_ReadPin(Echo_Port, Echo_Pin)) && (pMillis + 50 > HAL_GetTick()));
	value2 = __HAL_TIM_GET_COUNTER(&htim3); //save the second reading

	*Front_Distance = (value2 - value1)*0.034/2;
}

void Back_Sensor_Read(uint8_t *Back_Distance)
{
	uint32_t pMillis;
	uint32_t value1 = 0;
	uint32_t value2 = 0;

	HAL_GPIO_WritePin(Back_Ultrasonic_GPIO_Port, Back_Ultrasonic_Pin, GPIO_PIN_SET); //pull the trig pin high
	delay(10); //wait for 10us
	HAL_GPIO_WritePin(Back_Ultrasonic_GPIO_Port, Back_Ultrasonic_Pin, GPIO_PIN_RESET);	//pull the trig pin low

	pMillis = HAL_GetTick(); //used this to avoid infinite while loop (for timeout)
	//wait for the echo pin to get high
	while(!(HAL_GPIO_ReadPin(Echo_Port, Echo_Pin)) && (pMillis + 10 > HAL_GetTick()));
	value1 = __HAL_TIM_GET_COUNTER(&htim3); //save the first reading

	pMillis = HAL_GetTick(); //used this to avoid infinite while loop (for timeout)
	//wait for the echo pin to get low
	while((HAL_GPIO_ReadPin(Echo_Port, Echo_Pin)) && (pMillis + 50 > HAL_GetTick()));
	value2 = __HAL_TIM_GET_COUNTER(&htim3); //save the second reading

	*Back_Distance = (value2 - value1)*0.034/2;
}

void Right_Sensor_Read(uint8_t *Right_Distance)
{
	uint32_t pMillis;
	uint32_t value1 = 0;
	uint32_t value2 = 0;

	HAL_GPIO_WritePin(Right_Ultrasonic_GPIO_Port, Right_Ultrasonic_Pin, GPIO_PIN_SET); //pull the trig pin high
	delay(10); //wait for 10us
	HAL_GPIO_WritePin(Right_Ultrasonic_GPIO_Port, Right_Ultrasonic_Pin, GPIO_PIN_RESET);	//pull the trig pin low

	pMillis = HAL_GetTick(); //used this to avoid infinite while loop (for timeout)
	//wait for the echo pin to get high
	while(!(HAL_GPIO_ReadPin(Echo_Port, Echo_Pin)) && (pMillis + 10 > HAL_GetTick()));
	value1 = __HAL_TIM_GET_COUNTER(&htim3); //save the first reading

	pMillis = HAL_GetTick(); //used this to avoid infinite while loop (for timeout)
	//wait for the echo pin to get low
	while((HAL_GPIO_ReadPin(Echo_Port, Echo_Pin)) && (pMillis + 50 > HAL_GetTick()));
	value2 = __HAL_TIM_GET_COUNTER(&htim3); //save the second reading

	*Right_Distance = (value2 - value1)*0.034/2;
}

void Left_Sensor_Read(uint8_t *Left_Distance)
{
	uint32_t pMillis;
	uint32_t value1 = 0;
	uint32_t value2 = 0;

	HAL_GPIO_WritePin(Left_Ultrasonic_GPIO_Port, Left_Ultrasonic_Pin, GPIO_PIN_SET); //pull the trig pin high
	delay(10); //wait for 10us
	HAL_GPIO_WritePin(Left_Ultrasonic_GPIO_Port, Left_Ultrasonic_Pin, GPIO_PIN_RESET);	//pull the trig pin low

	pMillis = HAL_GetTick(); //used this to avoid infinite while loop (for timeout)
	//wait for the echo pin to get high
	while(!(HAL_GPIO_ReadPin(Echo_Port, Echo_Pin)) && (pMillis + 10 > HAL_GetTick()));
	value1 = __HAL_TIM_GET_COUNTER(&htim3); //save the first reading

	pMillis = HAL_GetTick(); //used this to avoid infinite while loop (for timeout)
	//wait for the echo pin to get low
	while((HAL_GPIO_ReadPin(Echo_Port, Echo_Pin)) && (pMillis + 50 > HAL_GetTick()));
	value2 = __HAL_TIM_GET_COUNTER(&htim3); //save the second reading

	*Left_Distance = (value2 - value1)*0.034/2;
}

void Right_Blind_Sensor_Read(uint8_t *Right_Blind_Distance)
{
	uint32_t pMillis;
	uint32_t value1 = 0;
	uint32_t value2 = 0;

	HAL_GPIO_WritePin(Right_Blind_GPIO_Port, Right_Blind_Pin, GPIO_PIN_SET); //pull the trig pin high
	delay(10); //wait for 10us
	HAL_GPIO_WritePin(Right_Blind_GPIO_Port, Right_Blind_Pin, GPIO_PIN_RESET);	//pull the trig pin low

	pMillis = HAL_GetTick(); //used this to avoid infinite while loop (for timeout)
	//wait for the echo pin to get high
	while(!(HAL_GPIO_ReadPin(Echo_Port, Echo_Pin)) && (pMillis + 10 > HAL_GetTick()));
	value1 = __HAL_TIM_GET_COUNTER(&htim3); //save the first reading

	pMillis = HAL_GetTick(); //used this to avoid infinite while loop (for timeout)
	//wait for the echo pin to get low
	while((HAL_GPIO_ReadPin(Echo_Port, Echo_Pin)) && (pMillis + 50 > HAL_GetTick()));
	value2 = __HAL_TIM_GET_COUNTER(&htim3); //save the second reading

	*Right_Blind_Distance = (value2 - value1)*0.034/2;
}

void Left_Blind_Sensor_Read(uint8_t *Left_Blind_Distance)
{
	uint32_t pMillis;
	uint32_t value1 = 0;
	uint32_t value2 = 0;

	HAL_GPIO_WritePin(Left_Blind_GPIO_Port, Left_Blind_Pin, GPIO_PIN_SET); //pull the trig pin high
	delay(10); //wait for 10us
	HAL_GPIO_WritePin(Left_Blind_GPIO_Port, Left_Blind_Pin, GPIO_PIN_RESET);	//pull the trig pin low

	pMillis = HAL_GetTick(); //used this to avoid infinite while loop (for timeout)
	//wait for the echo pin to get high
	while(!(HAL_GPIO_ReadPin(Echo_Port, Echo_Pin)) && (pMillis + 10 > HAL_GetTick()));
	value1 = __HAL_TIM_GET_COUNTER(&htim3); //save the first reading

	pMillis = HAL_GetTick(); //used this to avoid infinite while loop (for timeout)
	//wait for the echo pin to get low
	while((HAL_GPIO_ReadPin(Echo_Port, Echo_Pin)) && (pMillis + 50 > HAL_GetTick()));
	value2 = __HAL_TIM_GET_COUNTER(&htim3); //save the second reading

	*Left_Blind_Distance = (value2 - value1)*0.034/2;
}

void Set_Ultrasonic_View(Ultrasonic_Views_t view)
{
	switch(view)
	{
	case Front:
		HAL_GPIO_WritePin(Selector_0_GPIO_Port, Selector_0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Selector_1_GPIO_Port, Selector_0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Selector_2_GPIO_Port, Selector_0_Pin, GPIO_PIN_RESET);
		break;

	case Back:
		HAL_GPIO_WritePin(Selector_0_GPIO_Port, Selector_0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(Selector_1_GPIO_Port, Selector_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Selector_2_GPIO_Port, Selector_2_Pin, GPIO_PIN_RESET);
		break;

	case Right:
		HAL_GPIO_WritePin(Selector_0_GPIO_Port, Selector_0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Selector_1_GPIO_Port, Selector_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(Selector_2_GPIO_Port, Selector_2_Pin, GPIO_PIN_RESET);
		break;

	case Left:
		HAL_GPIO_WritePin(Selector_0_GPIO_Port, Selector_0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(Selector_1_GPIO_Port, Selector_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(Selector_2_GPIO_Port, Selector_2_Pin, GPIO_PIN_RESET);
		break;

	case Right_Blind:
		HAL_GPIO_WritePin(Selector_0_GPIO_Port, Selector_0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Selector_1_GPIO_Port, Selector_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Selector_2_GPIO_Port, Selector_2_Pin, GPIO_PIN_SET);
		break;

	case Left_Blind:
		HAL_GPIO_WritePin(Selector_0_GPIO_Port, Selector_0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(Selector_1_GPIO_Port, Selector_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Selector_2_GPIO_Port, Selector_2_Pin, GPIO_PIN_SET);
		break;
	}
}
