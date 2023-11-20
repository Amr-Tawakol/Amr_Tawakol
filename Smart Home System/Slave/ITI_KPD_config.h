/*
 * ITI_KPD_config.h
 *
 *  Created on: Aug 6, 2023
 *      Author: Amr Tawakol
 */

#ifndef ITI_KPD_CONFIG_H_
#define ITI_KPD_CONFIG_H_

#define KPD_PORT	DIO_PORTC

#define KPD_R0_PIN	DIO_PIN0
#define KPD_R1_PIN	DIO_PIN1
#define KPD_R2_PIN	DIO_PIN2
#define KPD_R3_PIN	DIO_PIN3

#define KPD_C0_PIN	DIO_PIN4
#define KPD_C1_PIN	DIO_PIN5
#define KPD_C2_PIN	DIO_PIN6
#define KPD_C3_PIN	DIO_PIN7

#define NKP		0xff

#define KPD_Val		{{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'ON','0','=','+'}}

#endif /* ITI_KPD_CONFIG_H_ */
