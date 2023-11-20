/*
 * Parking.h
 *
 *  Created on: Nov 8, 2023
 *      Author: Abdul_Aziz
 */

#ifndef INC_PARKING_H_
#define INC_PARKING_H_

typedef enum {
	IDEL,
	FIRST_OBJECT_DETECTED,
	WAIT_FOR_CLEAR,
	SECOND_OBJECT_DETECTED,
	ACTION_TRIGGERED,
	IDEL1,
	FIRST_OBJECT_DETECTED1,
	WAIT_FOR_CLEAR1,
	SECOND_OBJECT_DETECTED1,
	ACTION_TRIGGERED1
}state_t;

void Right_Parking(void);
void Left_Parking(void);
void Parking_Right(void);
void Parking_Left(void);
void ACCIDENT (void);
void Right_BLIND_MODE (void);
void Left_BLIND_MODE (void);

#endif /* INC_PARKING_H_ */
