/*
 * SPI_register.h
 *
 *  Created on: Feb 11, 2023
 *      Author: Amr Tawakol
 */

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_
#define SPCR *((volatile u8*)0x2D)
#define SPCR_SPIE  7
#define SPCR_SPE   6
#define SPCR_DORD  5
#define SPCR_MSTR  4
#define SPCR_CPOL  3
#define SPCR_CPHA  2
#define SPCR_SPR1  1
#define SPCR_SPR0  0

#define SPSR *((volatile u8*)0x2E) /*SPI status register*/

#define SPSR_SPIF  7   /*SPI interupt flag */
#define SPSR_WCOL  6
#define SPSR_SPI2X 0








#define SPDR	 *((volatile u8*)0x2F)   /*spi data register*/


#endif /* SPI_REGISTER_H_ */
