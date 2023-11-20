/*
 * MGIE_interface.h
 *
 *  Created on: Aug 8, 2023
 *      Author: Amr Tawakol
 */

#ifndef MGIE_INTERFACE_H_
#define MGIE_INTERFACE_H_

void MGIE_voidEnable(void);
void MGIE_voidDisable(void);
u8 EXIT_u8Int0SetCallBack(void(*Copy_PvInt0Func)(void));
u8 EXIT_u8Int1SetCallBack(void(*Copy_PvInt1Func)(void));
u8 EXIT_u8Int2SetCallBack(void(*Copy_PvInt2Func)(void));


#endif /* MGIE_INTERFACE_H_ */
