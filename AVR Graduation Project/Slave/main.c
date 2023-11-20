/*
 * main.c
 *
 *  Created on: Aug 8, 2023
 *      Author: Amr Tawakol
 */
#include "STD_TYPES.h"
#include "macros.h"
#include "MDIO_interface.h"
#include "ITI_KPD_interface.h"
#include "MEXI_interface.h"
#include "MGIE_interface.h"
#include "SERVO_interface.h"
#include "SPI_interface.h"
#include <util/delay.h>
#include "HSSD_interface.h"

u32 z;
void main()
{
	u16 i;

	Port_voidInit();
	SPI_voidInitSlave();
	TIMER1_void_Init();
	MGIE_voidEnable();
	
	while(1)
	{

		z=SPI_u8Tranceive(50);
		if (z>=50)
		{
				MDIO_u8SetPortValue(DIO_PORTA,~z);
				_delay_ms(7);

		}
		else if(z<50)
		{
			_delay_ms(5);

			static u8 f=0;
			HSSD_voidEnable(SSD_PORTD,SSD_PIN0);
			int D1=z%10 ;
			int D2=z/10 ;
			if (f==0)
			{
				HSSD_voidEnable(SSD_PORTD,SSD_PIN0);
				HSSD_voidDisable(SSD_PORTD,SSD_PIN1);
				HSSD_voidSendNumber(D1);
				f=1 ;
			}
			else
			{
				HSSD_voidDisable(SSD_PORTD,SSD_PIN0);
				HSSD_voidEnable(SSD_PORTD,SSD_PIN1);
				HSSD_voidSendNumber(D2);
				f=0 ;
			}
			if ((z>35)&&(z<40))
			{
				MDIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,DIO_HIGH);

			}
			else
			{
				MDIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,DIO_LOW);

			}

		}
		switch (z){

		case '1':
			TIMER1_void_SETICR(20000);

			TIMER1_void_SETCopmareMatchValue(2500);
			_delay_ms(10);
			break;
		case '2':
			TIMER1_void_SETICR(20000);

			TIMER1_void_SETCopmareMatchValue(500);
			_delay_ms(10);
			break;
		case '3':
			MDIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,DIO_HIGH);
			break;
		case '4':
			MDIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,DIO_LOW);
			break;
		case '5':

			for(i=0;i<386;i++)
			{
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_HIGH);
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_LOW);
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_LOW);
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN3,DIO_LOW);
				_delay_ms(2);

				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_LOW);
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_HIGH);
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_LOW);
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN3,DIO_LOW);
				_delay_ms(2);

				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_LOW);
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_LOW);
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_HIGH);
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN3,DIO_LOW);
				_delay_ms(2);

				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_LOW);
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_LOW);
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_LOW);
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN3,DIO_HIGH);
				_delay_ms(2);
			} break;
		case '6':

			for(i=0;i<386;i++)
			{
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_LOW);
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_LOW);
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_LOW);
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN3,DIO_HIGH);
				_delay_ms(2);

				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_LOW);
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_LOW);
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_HIGH);
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN3,DIO_LOW);
				_delay_ms(2);

				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_LOW);
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_HIGH);
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_LOW);
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN3,DIO_LOW);
				_delay_ms(2);

				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_HIGH);
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_LOW);
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_LOW);
				MDIO_voidSetPinValue(DIO_PORTB,DIO_PIN3,DIO_LOW);
				_delay_ms(2);
			} break;
			
		default: break ;

		}
			}

}

