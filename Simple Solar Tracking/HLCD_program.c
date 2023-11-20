/******************************************************/
/******************************************************/
/******************************************************/
/************* Author : Amr Tawakol *******************/
/************* Layer  : HAL            ****************/
/************* Module : LCD            ****************/
/************* Version : 1.00          ****************/
/************* Date   : 8/2023       ****************/
/******************************************************/
/******************************************************/
/******************************************************/

#include "STD_TYPES.h"
#include "MACROS.h"
#include "MDIO_interface.h"
#include "HLCD_private.h"
#include "HLCD_interface.h"
#include "HLCD_config.h"
#include <util/delay.h>

void HLCD_voidSendCommand(u8 Copy_u8Command)
{
	/*Clr RS to send Command*/
	MDIO_VoidSetPinValue(HLCD_CONTROL_PORT,HLCD_RS_PIN,DIO_PIN_LOW);

	/*Clr RW to Write*/
	MDIO_VoidSetPinValue(HLCD_CONTROL_PORT,HLCD_RW_PIN,DIO_PIN_LOW);

	/*Send Command On data  Port*/
	MDIO_VoidSetPortValue(HLCD_DATA_PORT,Copy_u8Command);

	/*Set En To make LCD mc To read the command*/
	MDIO_VoidSetPinValue(HLCD_CONTROL_PORT,HLCD_EN_PIN,DIO_PIN_HIGH);
	_delay_ms(2);
	MDIO_VoidSetPinValue(HLCD_CONTROL_PORT,HLCD_EN_PIN,DIO_PIN_LOW);


}

void HLCD_voidSendData(u8 Copy_u8Data)
{
	/*Set RS to send Command*/
	MDIO_VoidSetPinValue(HLCD_CONTROL_PORT,HLCD_RS_PIN,DIO_PIN_HIGH);

	/*Clr RW to Write*/
	MDIO_VoidSetPinValue(HLCD_CONTROL_PORT,HLCD_RW_PIN,DIO_PIN_LOW);

	/*Send Data On data  Port*/
	MDIO_VoidSetPortValue(HLCD_DATA_PORT,Copy_u8Data);

	/*Set En To make LCD mc To read the command*/
	MDIO_VoidSetPinValue(HLCD_CONTROL_PORT,HLCD_EN_PIN,DIO_PIN_HIGH);
	_delay_ms(2);
	MDIO_VoidSetPinValue(HLCD_CONTROL_PORT,HLCD_EN_PIN,DIO_PIN_LOW);
}
void HLCD_voidInit()
{
	_delay_ms(40);
	HLCD_voidSendCommand(0b00111100);
	HLCD_voidSendCommand(0b00001100);
	HLCD_voidSendCommand(0b00000001);

}
void HLCD_voidSendString(u8 *Copy_u8String)
{
	while(*Copy_u8String != '\0')
	{
		HLCD_voidSendData(*Copy_u8String);
		Copy_u8String+=1 ;
	}
}
void HLCD_voidSendDigit(u8 Copy_u8Digit)
{
	HLCD_voidSendData( (Copy_u8Digit) + 48 );
}

void HLCD_voidSendGoTo(u8 Copy_u8X,u8 Copy_u8Y)
{
	if(Copy_u8X==0)
	{
		HLCD_voidSendCommand(128+Copy_u8Y);
	}
	else if(Copy_u8X==1)
	{
		HLCD_voidSendCommand(64+128+Copy_u8Y);
	}
}


void HLCD_voidSendInt(s32 A_s32Number)
{
	s32 L_s32ReverseNumber = 0;
	s32 L_s32TempNumber = 0;
	u8 L_u8NegativeFlag = 0;
	if(A_s32Number < 0) {
		A_s32Number = -A_s32Number;
		L_u8NegativeFlag = 1;
	}

	L_s32TempNumber = A_s32Number;
	while(L_s32TempNumber > 0)
	{
		L_s32ReverseNumber = (L_s32ReverseNumber * 10) + (L_s32TempNumber % 10) ;
		L_s32TempNumber /= 10 ;
	}

	if(L_u8NegativeFlag == 1) {
		HLCD_voidSendData( '-' );
	}
	while(L_s32ReverseNumber > 0) {
		HLCD_voidSendData( '0' + (L_s32ReverseNumber % 10) );
		L_s32ReverseNumber /= 10;
	}

	if(A_s32Number % 10 == 0) {
		HLCD_voidSendData('0');

		void HLCD_voidSendFloat(f32 Copy_f32Float,u8 Copy_u8X,u8 Copy_u8Y)
		{
			u32 int_number,Number ;
			u8 i,Countint=0;
			int_number=(u32)Copy_f32Float ;
			/*Count The Digits*/
			while(int_number != 0)
			{
				Countint++ ;
				int_number/=10 ;
			}
			/*Make Sure That All Digits locate before the floating point*/
			for(i=0 ; i<2 ; i++)
			{
				Copy_f32Float*=10 ;
			}
			Number=Copy_f32Float ;
			/*Displaying on LCD (Right To left)*/
			for(i=0 ; i<Countint+3 ; i++)
			{
				HLCD_voidSendGoTo(Copy_u8X,Copy_u8Y+Countint+2-i);
				if(i!=2)
				{
					HLCD_voidSendDigit(Number%10);
					Number/=10 ;
				}
				else
				{
					HLCD_voidSendData('.');
				}

			}
		}
	}
}
	void HLCD_voidClearLcd()
	{
		HLCD_voidSendCommand(1);
	}
