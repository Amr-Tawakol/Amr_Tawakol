/********************************************/
/*******************************************/
/*********	AUTHOR: Amr Tawakol  **********/
/*********	LAYER: MCAL    	     *********/
/*********	MODULE: DIO          ********/
/*********	Version: 1.00        *******/
/*********	Date: 2/8/2023*************/


#ifndef _MDIO_INTERFACE_H_
#define _MDIO_INTERFACE_H_






#define DIO_INPUT	0
#define DIO_OUTPUT	1

#define DIO_PORTA	0
#define DIO_PORTB	1
#define DIO_PORTC	2
#define DIO_PORTD	3

#define DIO_PIN0	0
#define DIO_PIN1	1
#define DIO_PIN2	2
#define DIO_PIN3	3
#define DIO_PIN4	4
#define DIO_PIN5	5
#define DIO_PIN6	6
#define DIO_PIN7	7

#define DIO_LOW		0
#define DIO_HIGH	1

#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7

/*******************data type section******************/
typedef enum
{
Return_OK,
Return_Nok,
Return_Null
}Error_State_t;
/**************function declartion section*******************/
Error_State_t MDIO_voidSetPinDirection(u8 Copy_u8Port ,u8 Copy_u8Pin ,u8 Copy_u8Mode);
Error_State_t MDIO_voidSetPinValue(u8 Copy_u8Port ,u8 Copy_u8Pin ,u8 Copy_u8Mode);
void MDIO_Error_State_tGetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* P_u8Value);
void MDIO_u8SetPortValue(u8 Copy_u8Port , u8 Copy_u8Value);

void Port_voidInit(void);
void PORT_LOGIC_INIT(void);

#endif
