/*
 * MUART_Driver_iti_register.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Amr Tawakol
 */

#ifndef MUART_DRIVER_ITI_REGISTER_H_
#define MUART_DRIVER_ITI_REGISTER_H_
#define UDR              *((volatile u8*) 0x2c)
#define UCSRA			 *((volatile u8*) 0x2B)
#define UCSRA_RXC      7
#define UCSRA_TXC      6
#define UCSRA_UDRE     5
#define UCSRA_PE       2


#define UCSRB     *((volatile u8*) 0x2a)
#define UCSRB_RXCIE   7
#define UCSRB_TXCIE   6
#define UCSRB_UDRIE   5
#define UCSRB_RXEN    4
#define UCSRB_TXEN    3
#define UCSRB_UCSZ2   2
#define UCSRB_RXB8    1
#define UCSRB_TXB8    0

#define UCSRC    *((volatile u8*) 0x40)
#define UBRRL    *((volatile u8*) 0x29)
#define UBRRH    *((volatile u8*) 0x40)


#define UCSRC_URSEL     7
#define UCSRC_UMSEL    6
#define UCSRC_UPM1      5
#define UCSRC_UPM0      4
#define UCSRC_USBS      3
#define UCSRC_UCSZ1     2
#define UCSRC_UCSZ0     1
#define UCSRC_UCPOL     0





#endif /* MUART_DRIVER_ITI_REGISTER_H_ */
