/*
 * SERVO_register.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Amr Tawakol
 */

#ifndef SERVO_REGISTER_H_
#define SERVO_REGISTER_H_
#define TCCR1A   *((volatile  u8*)0x4f)
#define TCCR1A_COM1A1 7
#define TCCR1A_COM1A0 6
#define TCCR1A_WGM11  1
#define TCCR1A_WGM10  0

#define  TCCR1B   *((volatile  u8*)0x4e)
#define  TCCR1B_WGM13   4
#define  TCCR1B_WGM12   3
#define  TCCR1B_CS12   2
#define  TCCR1B_CS11    1
#define  TCCR1B_CS10    0
#define OCR1A   *((volatile  u16*)0x4A)
#define ICR     *((volatile  u16*)0x46)


#endif /* SERVO_REGISTER_H_ */
