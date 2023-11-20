/***************************************************/
/************* Author : Amr Tawakol ****************/
/********************	Layer 	:  HLCD		********/
/********************	Module	:  LCD		********/
/********************	Version : 11.00		********/
/********************	Date	:  3/8/2023	********/
/***************************************************/
/***************************************************/


#ifndef _HLCD_CONFIG_H
#define _HLCD_CONFIG_H
#include "STD_TYPES.h"

#define LCD_MODE			HLCD_MODE_4

#define LCD_PORT_DATA 		DIO_PORTC
#define LCD_D0		 		DIO_PIN2
#define LCD_D1		 		DIO_PIN3
#define LCD_D2		 		DIO_PIN4
#define LCD_D3		 		DIO_PIN5

#define LCD_PORT_CTRL 		DIO_PORTA
#define LCD_RS 				3
#define LCD_RW 				4
#define LCD_EN	 			5


#endif
