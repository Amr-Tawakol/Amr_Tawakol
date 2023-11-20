#include "STD_TYPES.h"
#include "MACROS.h"

#include "MDIO_interface.h"
#include "HLCD_interface.h"
#include "HKPD_interface.h"
#include <util/delay.h>

void Stepper_CW();
void Stepper_CCW();
void Stepper_Stop();

void DC_CW();
void DC_CCW();
void DC_Stop();


int main()
{
	u8 Key;

	Port_voidInit();
	HLCD_voidInit();

	while(1)
	{
		DC_Stop();
		Stepper_Stop();
		HLCD_voidSendGoTo(0,0);
		HLCD_voidSendString("1) For DC ");
		HLCD_voidSendGoTo(1,0);
		HLCD_voidSendString("2) For Stepper");
		Key=HKPD_u8GetPressedKey();
		if( Key != NOT_PRESSED )
		{
			if (Key==1)
			{
				HLCD_voidClearLcd();
				HLCD_voidSendString("1-For CW");
				HLCD_voidSendGoTo(1,0);
				HLCD_voidSendString("2-For CCW");
				do
				{
					Key=HKPD_u8GetPressedKey();
				}while(Key == NOT_PRESSED);

			 	switch(Key)
			 	{
			 	case 1 :DC_CW();break;
			 	case 2 :DC_CCW();break;
			 	default:HLCD_voidClearLcd();
			 	HLCD_voidSendString("Wrong Choise");
			 	_delay_ms(1000); break ;
			 	}
			 	HLCD_voidClearLcd();
			 	HLCD_voidSendString("Press Any key");
			 	HLCD_voidSendGoTo(1,0);
			 	HLCD_voidSendString("To Back");
			 	do
			 	{
			 		Key=HKPD_u8GetPressedKey();
			 	}while(Key == NOT_PRESSED);
				HLCD_voidClearLcd();
			}
			else if (Key==2)
			{
				HLCD_voidClearLcd();
				HLCD_voidSendString("1-For CW");
				HLCD_voidSendGoTo(1,0);
				HLCD_voidSendString("2-For CCW");
				do
				{
					Key=HKPD_u8GetPressedKey();
				}while(Key == NOT_PRESSED);
				HLCD_voidClearLcd();
			    HLCD_voidSendString("Press Any key");
				HLCD_voidSendGoTo(1,0);
				HLCD_voidSendString("To Back");
				 switch(Key)
				 {
				 case 1 : Stepper_CW();break;
				 case 2 : Stepper_CCW();break;
				 default :HLCD_voidClearLcd();
				 HLCD_voidSendString("Wrong Choise");
				 _delay_ms(1000); break ;
				 }
				 do
				 {
				 	Key=HKPD_u8GetPressedKey();
				 }while(Key == NOT_PRESSED);
				 HLCD_voidClearLcd();

			}
		}

	}
}

void Stepper_CW()
{
	for(u16 i=0 ; i<515 ; i++)
	{
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_LOW);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
		_delay_ms(2);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_LOW);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_HIGH);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
		_delay_ms(2);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_LOW);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_LOW);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
		_delay_ms(2);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_LOW);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_LOW);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);
		_delay_ms(2);
	}

}
void Stepper_CCW()
{
	for(u16 i=0 ; i<515 ; i++)
	{
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_LOW);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_LOW);
		_delay_ms(2);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_LOW);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_LOW);
		_delay_ms(2);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_HIGH);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_LOW);
		_delay_ms(2);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_LOW);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);
		_delay_ms(2);
	}
}
void Stepper_Stop()
{
	MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
	MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
	MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_LOW);
	MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_LOW);
}
void DC_CCW()
{
	MDIO_VoidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_HIGH);
	MDIO_VoidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
}
void DC_CW()
{
	MDIO_VoidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
	MDIO_VoidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_LOW);
}
void DC_Stop()
{
	MDIO_VoidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_LOW);
	MDIO_VoidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
}

