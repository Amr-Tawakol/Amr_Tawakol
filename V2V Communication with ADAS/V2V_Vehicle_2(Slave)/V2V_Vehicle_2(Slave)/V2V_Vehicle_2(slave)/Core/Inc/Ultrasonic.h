/*
 * Ultrasonic.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Mahmoud
 */

#ifndef INC_ULTRASONIC_H_
#define INC_ULTRASONIC_H_

#define Echo_Pin GPIO_PIN_10
#define Echo_Port GPIOA

typedef enum
{
	Front,
	Back,
	Right,
	Left,
	Right_Blind,
	Left_Blind
}Ultrasonic_Views_t;

void delay(uint8_t time);
void Front_Sensor_Read(uint8_t *Front_Distance);
void Back_Sensor_Read(uint8_t *Back_Distance);
void Right_Sensor_Read(uint8_t *Right_Distance);
void Left_Sensor_Read(uint8_t *Left_Distance);
void Right_Blind_Sensor_Read(uint8_t *Right_Blind_Distance);
void Left_Blind_Sensor_Read(uint8_t *Left_Blind_Distance);
void Set_Ultrasonic_View(Ultrasonic_Views_t view);
#endif /* INC_ULTRASONIC_H_ */
