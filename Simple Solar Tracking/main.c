/******************************************************/
/******************************************************/
/******************************************************/
/************* Author : Amr Tawakol *******************/
/************* Layer  : App           ****************/
/************* Module : Solar Tracking ****************/
/************* Version : 1.00          ****************/
/************* Date   : 15/8/2023       ****************/
/******************************************************/
/******************************************************/
/******************************************************/
#include "STD_TYPES.h"
#include "MACROS.h"

#include "MDIO_interface.h"
#include "MADC_interface.h"
#include "MTIMER_interface.h"
#include "HLCD_interface.h"
#include <util/delay.h>

u16 Mapping(u16 X_MAX,u16 X_MIN,u16 Y_MAX,u16 Y_MIN,u16 Y);

int main()
{
	u16 value ,MapValue,angle=0 ;
	Port_voidInit();
	HLCD_voidInit();
	_delay_ms(500);

	MADC_voidInit();
	MTIMER1_voidInit(FPWM_NON_INVERTING,TOP_FPWM_ICR1,TIMER1_8_PRESCALER);
	MTIMER1_voidSetTopValue(20000,TOP_CTC_ICR1);
	while(1)
	{

		value = MADC_voidGetValue(ADC0);
		MapValue=Mapping(2500,700,940,120,value);

		angle=Mapping(180,0,2500,700,MapValue);
		HLCD_voidSendGoTo(0,0);
		_delay_ms(10);
		HLCD_voidSendString("Servo Angle : ");
		_delay_ms(10);
		HLCD_voidSendGoTo(0,13);
		_delay_ms(10);
		HLCD_voidSendInt(angle);
		_delay_ms(10);
		HLCD_voidSendString("         ");
		_delay_ms(10);
		MTIMER1_voidSetDutyCycle(MapValue);
		_delay_ms(500);
	}
}



u16 Mapping(u16 X_MAX,u16 X_MIN,u16 Y_MAX,u16 Y_MIN,u16 Y)
{
	u16 X;
	X = ( (  ((u32) (X_MAX - X_MIN) * (Y-Y_MIN) )/ (Y_MAX-Y_MIN) ) + X_MIN);

	return X ;
}
