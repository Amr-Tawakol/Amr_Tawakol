/*
 * SPI_interface.h
 *
 *  Created on: Feb 11, 2023
 *      Author: Amr Tawakol
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_voidInitMaster(void);

void SPI_voidInitSlave(void);

u8 SPI_u8Tranceive (u8 Copy_u8Data);

#endif /* SPI_INTERFACE_H_ */
