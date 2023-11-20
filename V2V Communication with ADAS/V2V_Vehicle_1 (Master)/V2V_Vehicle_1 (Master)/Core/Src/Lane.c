/*
 * Lane.c
 *
 *  Created on: Oct 31, 2023
 *      Author: Mahmoud
 */

#include "main.h"
#include "Lane.h"
#include "Motion.h"

extern int8_t R1, L1;

void Lane_Detection(void)
{
	/*Forward Moving*/
	if (R1==Black && L1==Black)
	{
		QUARTER_SPEED();
		Forward_Moving();
	}
	/*Left Moving*/
	else if (R1==Black && L1==White)
	{

		QUARTER_SPEED();
		Left_Moving();
	}
	/*Right Moving*/
	else if (R1==White && L1==Black)
	{
		QUARTER_SPEED();
		Right_Moving();
	}
	/*Stop Moving*/
	else
	{
		NO_SPEED();
		Stop_Moving();

	}
}
