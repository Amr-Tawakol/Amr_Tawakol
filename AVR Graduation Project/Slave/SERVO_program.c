/*
 * SERVO_program.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Amr Tawakol
 */
#include "STD_TYPES.h"
#include "macros.h"
#include "MDIO_interface.h"
#include "SERVO_interface.h"
#include "SERVO_register.h"
#include "SERVO_config.h"
#include "SERVO_private.h"


void TIMER1_void_SETICR(u16 Copy_u16Top ){
	ICR=Copy_u16Top;
}
void TIMER1_void_Init(void ){
CLR_BIT(TCCR1A,TCCR1A_COM1A0);
SET_BIT(TCCR1A,TCCR1A_COM1A1);

CLR_BIT(TCCR1A,TCCR1A_WGM10);
SET_BIT(TCCR1A,TCCR1A_WGM11);
SET_BIT(TCCR1B,TCCR1B_WGM12);
SET_BIT(TCCR1B,TCCR1B_WGM13);

CLR_BIT(TCCR1B,TCCR1B_CS10);
SET_BIT(TCCR1B,TCCR1B_CS11);
CLR_BIT(TCCR1B,TCCR1B_CS12);

}
void TIMER1_void_SETCopmareMatchValue(u16 Copy_u16Value ){
OCR1A=Copy_u16Value;
}

