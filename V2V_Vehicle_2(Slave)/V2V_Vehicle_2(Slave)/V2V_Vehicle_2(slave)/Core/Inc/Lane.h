/*
 * Lane.h
 *
 *  Created on: Oct 31, 2023
 *      Author: Mahmoud
 */

#ifndef INC_LANE_H_
#define INC_LANE_H_

typedef enum
{
	Black,
	White,
	Parking
}IR_SENSOR_READING_t;

void Lane_Detection(void);

#endif /* INC_LANE_H_ */
