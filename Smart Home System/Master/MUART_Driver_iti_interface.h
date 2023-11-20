/*
 * MUART_Driver_iti_interface.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Amr Tawakol
 */

#ifndef MUART_DRIVER_ITI_INTERFACE_H_
#define MUART_DRIVER_ITI_INTERFACE_H_

void UART_voidInit(void);
void UART_voidTransmit(u8 Copy_u8Data);
u8 UART_u8Recive(void);

#endif /* MUART_DRIVER_ITI_INTERFACE_H_ */
