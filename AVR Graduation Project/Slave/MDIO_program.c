/********************************************/
/*******************************************/
/*********	AUTHOR: Amr Tawakol  **********/
/*********	LAYER: MCAL    	     *********/
/*********	MODULE: DIO          ********/
/*********	Version: 1.00        *******/
/*********	Date: 2/8/2023*************/

#include "STD_TYPES.h"
#include "macros.h"
#include "MDIO_interface.h"
#include "MDIO_registers.h"
#include "MDIO_private.h"
#include "MDIO_config.h"



Error_State_t MDIO_voidSetPinDirection(u8 Copy_u8Port ,u8 Copy_u8Pin ,u8 Copy_u8Mode)
{
	Error_State_t Status=Return_OK;
	if(Copy_u8Mode == DIO_INPUT)
	{
		switch(Copy_u8Port)
		{
		case DIO_PORTA : CLR_BIT(DDRA, Copy_u8Pin);Status=Return_OK; break;
		case DIO_PORTB : CLR_BIT(DDRB, Copy_u8Pin);Status=Return_OK; break;
		case DIO_PORTC : CLR_BIT(DDRC, Copy_u8Pin);Status=Return_OK; break;
		case DIO_PORTD : CLR_BIT(DDRD, Copy_u8Pin);Status=Return_OK; break;
		default:Status=Return_Nok; break;

		}
	}
	else if(Copy_u8Mode == DIO_OUTPUT)
	{
		switch(Copy_u8Port)
		{
		case DIO_PORTA : SET_BIT(DDRA, Copy_u8Pin);Status=Return_OK; break;
		case DIO_PORTB : SET_BIT(DDRB, Copy_u8Pin);Status=Return_OK; break;
		case DIO_PORTC : SET_BIT(DDRC, Copy_u8Pin);Status=Return_OK; break;
		case DIO_PORTD : SET_BIT(DDRD, Copy_u8Pin);Status=Return_OK; break;
		default:Status=Return_Nok; break;
		}
	}
	return Status;
}
Error_State_t MDIO_voidSetPinValue(u8 Copy_u8Port ,u8 Copy_u8Pin ,u8 Copy_u8Mode)
{
	Error_State_t Error_State = Return_OK;
	if (Copy_u8Mode == DIO_LOW)
	{
		switch(Copy_u8Port)
		{
		case DIO_PORTA: CLR_BIT(PORTA , Copy_u8Pin);Error_State=Return_OK;  break;
		case DIO_PORTB: CLR_BIT(PORTB , Copy_u8Pin);Error_State=Return_OK; break;
		case DIO_PORTC: CLR_BIT(PORTC , Copy_u8Pin);Error_State=Return_OK; break;
		case DIO_PORTD: CLR_BIT(PORTD , Copy_u8Pin);Error_State=Return_OK; break;
		default:Error_State=Return_Nok; break;
		}

	}
	else if (Copy_u8Mode == DIO_HIGH)
	{
		switch(Copy_u8Port)
		{
		case DIO_PORTA: SET_BIT(PORTA , Copy_u8Pin);Error_State=Return_OK; break;
		case DIO_PORTB: SET_BIT(PORTB , Copy_u8Pin);Error_State=Return_OK; break;
		case DIO_PORTC: SET_BIT(PORTC , Copy_u8Pin);Error_State=Return_OK; break;
		case DIO_PORTD: SET_BIT(PORTD , Copy_u8Pin);Error_State=Return_OK; break;
		default:Error_State=Return_Nok; break;
		}
	}
	return Error_State;
}


void MDIO_u8SetPortValue(u8 Copy_u8Port , u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
	case DIO_PORTA : PORTA=Copy_u8Value; break;
	case DIO_PORTB : PORTB=Copy_u8Value; break;
	case DIO_PORTC : PORTC=Copy_u8Value; break;
	case DIO_PORTD : PORTD=Copy_u8Value; break;
	default : break;

	}
}

void MDIO_Error_State_tGetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* P_u8Value)
{
	Error_State_t Error_State = Return_OK;
	if ((P_u8Value!=NULL)&&(Copy_u8Pin<= DIO_PIN7))

	{
		switch (Copy_u8Port)
		{
		case DIO_PORTA: *P_u8Value=GET_BIT(PINA, Copy_u8Pin);break;
		case DIO_PORTB: *P_u8Value=GET_BIT(PINB, Copy_u8Pin);break;
		case DIO_PORTC: *P_u8Value=GET_BIT(PINC, Copy_u8Pin);break;
		case DIO_PORTD: *P_u8Value=GET_BIT(PIND, Copy_u8Pin);break;
		default:Error_State=Return_Nok; break;
		}
	}
	else
	{
		Error_State=Return_Nok;
	}

}

void Port_voidInit(void)
{
	DDRA=PORTA_DIR;
	DDRB=PORTB_DIR;
	DDRC=PORTC_DIR;
	DDRD=PORTD_DIR;

	PORTA = PORTA_VALUE;
	PORTB = PORTB_VALUE;
	PORTC = PORTC_VALUE;
	PORTD = PORTD_VALUE;

}
