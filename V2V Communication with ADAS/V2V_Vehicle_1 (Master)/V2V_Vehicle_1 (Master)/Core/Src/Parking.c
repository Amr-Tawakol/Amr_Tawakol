/*
 * Parking.c
 *
 *  Created on: Nov 13, 2023
 *      Author: Mahmoud
 */

#include "main.h"
#include "Parking.h"
#include "Motion.h"
#include "NRF24L01.h"
#include <string.h>
extern uint8_t Right_Distance;
extern uint8_t Left_Distance;
extern uint8_t Front_Distance;
extern uint8_t Right_Blind_Distance ;
extern uint8_t Left_Blind_Distance ;
extern UART_HandleTypeDef huart6;
extern volatile int object1detected;
volatile int object2detected = 0;
volatile int object3detected = 0;
volatile int object4detected = 0;

/* NRF COMMANDS*/
extern uint8_t Accident[];
uint8_t	Half_speed[] = "Half_speed\n";
uint8_t Lock[] = "Lock" ;
uint8_t Sock[] = "Sock" ;
extern uint8_t Blind[] ;
extern volatile int8_t flag;
extern int8_t flag2;
extern int8_t front_flag;
extern int8_t COUNTER;

/* GUI COMMANDS*/

char fullSpeed[]   ="speed=Full speed -> 100\r\n";
char halfSpeed[]   ="speed=half speed -> 50\r\n";
char quarterSpeed[]="speed=Quarter speed -> 25\r\n";
char zeroSpeed[]="speed=Zero speed -> 0\r\n";
char MPU1[]="mpu=150,30\r\n";
char parkingMode[]="car_mode=Parking Mode\r\n";
char BlindMode[]="car_mode=Blind Mode\r\n";
char AccidentMode[]="car_mode= Accident Mode\r\n";

state_t STATUS_Parking = FIRST_OBJECT_DETECTED;
state_t STATUS2_Parking=FIRST_OBJECT_DETECTED;

void Parking_Right(void)
{
	switch(STATUS_Parking)/*LEFT SENSOR*/
	{
	case FIRST_OBJECT_DETECTED:
		if(Right_Distance>30)
		{
			object1detected=0;
			STATUS_Parking = WAIT_FOR_CLEAR;
		}
		break;

	case WAIT_FOR_CLEAR:
		if(Right_Distance<=30)
		{
			object2detected=1;
			STATUS_Parking = SECOND_OBJECT_DETECTED;
		}
		break;

	case SECOND_OBJECT_DETECTED:
		if(Right_Distance>30)
		{
			object2detected=0;

			STATUS_Parking = ACTION_TRIGGERED;
		}
		break;
	case ACTION_TRIGGERED:
		NO_SPEED();
		Stop_Moving();
		HAL_Delay(10);
		QUARTER_SPEED();
		Right_Parking();
		HAL_UART_Transmit(&huart6, (uint8_t*)parkingMode, strlen(parkingMode), HAL_MAX_DELAY);
		HAL_Delay(1000);
		STATUS_Parking = IDEL;
	default:break;
	break;
	}
	HAL_Delay(10);
}

void Parking_Left(void)
{
	switch(STATUS_Parking)/*LEFT SENSOR*/
	{
	case FIRST_OBJECT_DETECTED:
		if(Left_Distance>30)
		{
			object1detected=0;
			STATUS_Parking = WAIT_FOR_CLEAR;
		}
		break;

	case WAIT_FOR_CLEAR:
		if(Left_Distance<=30)
		{
			object2detected=1;
			STATUS_Parking = SECOND_OBJECT_DETECTED;
		}
		break;

	case SECOND_OBJECT_DETECTED:
		if(Left_Distance>30)
		{
			object2detected=0;

			STATUS_Parking = ACTION_TRIGGERED;
		}
		break;
	case ACTION_TRIGGERED:
		NO_SPEED();
		Stop_Moving();
		HAL_Delay(10);
		QUARTER_SPEED();
		Left_Parking();
		HAL_UART_Transmit(&huart6, (uint8_t*)parkingMode, strlen(parkingMode), HAL_MAX_DELAY);
		HAL_Delay(1000);
		STATUS_Parking = IDEL;
	default:break;
	break;
	}
	HAL_Delay(10);
}

void ACCIDENT (void)
{
	NO_SPEED();
	Stop_Moving();
	NRF24_Transmit(Accident);
	//HAL_UART_Transmit(&huart6, (uint8_t*)AccidentMode, strlen(AccidentMode), HAL_MAX_DELAY);
	//HAL_Delay(1000);
}

void Blocked_Area (void)
{
	//	flag2=1;
	NO_SPEED();
	Stop_Moving();
	HAL_Delay(20);
	HALF_SPEED();
	Backword_Moving();
	HAL_Delay(300);
	Right_Moving();
	HAL_Delay(200);
	Forward_Moving();
	flag=1;

	//HALF_SPEED();
	//Backword_Moving();

	//flag2=0;
	COUNTER++;
	if(COUNTER==3)
	{
		NRF24_Transmit(Sock);

		//COUNTER==2;
	}
}

void Right_BLIND_MODE (void)
{


	NRF24_Transmit(Blind);
	QUARTER_SPEED();
	Right_Moving();
	HAL_Delay(500);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13,GPIO_PIN_SET);
	HAL_Delay(200);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13,GPIO_PIN_RESET);
	Forward_Moving();
	HAL_Delay(2000);
	/*	HAL_UART_Transmit(&huart6, (uint8_t*)BlindMode, strlen(BlindMode), HAL_MAX_DELAY);
		HAL_Delay(1000);*/

}

void Left_BLIND_MODE (void)
{


	NRF24_Transmit(Blind);
	QUARTER_SPEED();
	Left_Moving();
	HAL_Delay(500);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13,GPIO_PIN_SET);
	HAL_Delay(200);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13,GPIO_PIN_RESET);
	Forward_Moving();
	HAL_Delay(2000);
	/*	HAL_UART_Transmit(&huart6, (uint8_t*)BlindMode, strlen(BlindMode), HAL_MAX_DELAY);
		HAL_Delay(1000);*/

}

void Right_Parking(void)
{
	/*
	 * pin C14 right_forward
	 * pin C15 left_forward
	 * pin A7 right_backword
	 * pin B13 left_backword
	 */
	/*Backward Left*/
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13,GPIO_PIN_SET);
	HAL_Delay(1500);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13,GPIO_PIN_SET);
	HAL_Delay(1300);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13,GPIO_PIN_RESET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13,GPIO_PIN_SET);
	HAL_Delay(600);
	NO_SPEED();
	Stop_Moving();
	HAL_Delay(5);

	/*Backward*/

}

void Left_Parking(void)
{
	/*
	 * pin C14 right_forward
	 * pin C15 left_forward
	 * pin A7 right_backword
	 * pin B13 left_backword
	 */
	/*Backward Left*/
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13,GPIO_PIN_SET);
	HAL_Delay(1500);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7,GPIO_PIN_SET);
	HAL_Delay(1300);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13,GPIO_PIN_RESET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13,GPIO_PIN_SET);
	HAL_Delay(600);
	NO_SPEED();
	Stop_Moving();
	HAL_Delay(5);
	/*Backward*/
}
