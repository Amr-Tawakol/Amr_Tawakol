/*
 * MUART_Driver_iti_program.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Amr Tawakol
 */

#include "STD_TYPES.h"
#include "MACROS.h"
#include "MUART_Driver_iti_interface.h"
#include "MUART_Driver_iti_register.h"
#include "MUART_Driver_iti_config.h"
#include "MUART_Driver_iti_private.h"

void UART_voidInit(void){
	UBRRL=51;

u8 Local_u8Temp=0;
SET_BIT(UCSRB,UCSRB_RXEN);
SET_BIT(UCSRB,UCSRB_TXEN);
CLR_BIT(UCSRB,UCSRB_UCSZ2);
SET_BIT(Local_u8Temp,UCSRC_URSEL);
CLR_BIT(Local_u8Temp,UCSRC_UMSEL);
CLR_BIT(Local_u8Temp,UCSRC_USBS);
SET_BIT(Local_u8Temp,UCSRC_UCSZ0);
SET_BIT(Local_u8Temp,UCSRC_UCSZ1);
UCSRC=Local_u8Temp;

}
void UART_voidTransmit(u8 Copy_u8Data){
	while (GET_BIT(UCSRA,UCSRA_UDRE)==0);
UDR=Copy_u8Data;

}
u8 UART_u8Recive(void){
	while (GET_BIT(UCSRA,UCSRA_RXC)==0);
		return UDR;
}
