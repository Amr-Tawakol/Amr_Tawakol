/*
 * SPI_program.c
 *
 *  Created on: Feb 11, 2023
 *      Author: Amr Tawakol
 */
#include "STD_TYPES.h"
#include "MACROS.h"
#include "SPI_config.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_register.h"
void SPI_voidInitMaster(void){
	SET_BIT(SPCR,SPCR_MSTR);
SET_BIT(SPCR,SPCR_SPR0);
CLR_BIT(SPCR,SPCR_SPR1);
CLR_BIT(SPSR,SPSR_SPI2X);
	SET_BIT(SPCR,SPCR_SPE);
}

void SPI_voidInitSlave(void){
	CLR_BIT(SPCR,SPCR_MSTR);

	SET_BIT(SPCR,SPCR_SPE);
}

u8 SPI_u8Tranceive (u8 Copy_u8Data){
SPDR=Copy_u8Data;
while (GET_BIT(SPSR,SPSR_SPIF)==0);

return SPDR;

}



