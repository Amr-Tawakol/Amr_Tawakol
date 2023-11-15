/*
 * Motion.h
 *
 *  Created on: Oct 31, 2023
 *      Author: Mahmoud
 */

#ifndef INC_MOTION_H_
#define INC_MOTION_H_

void Forward_Moving(void);
void Left_Moving(void);
void Right_Moving(void);
void Backword_Moving(void);
void Stop_Moving(void);

#define Motor_High	1
#define Motor_Low	0

void FULL_SPEED (void);

void HALF_SPEED (void);

void QUARTER_SPEED (void);

void NO_SPEED (void);

#endif /* INC_MOTION_H_ */
