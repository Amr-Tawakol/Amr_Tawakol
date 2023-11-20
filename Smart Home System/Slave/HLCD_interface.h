/*
 * HLCD_interface.h
 *
 *  Created on: Aug 3, 2023
 *      Author: Amr Tawakol
 */

#ifndef HLCD_INTERFACE_H_
#define HLCD_INTERFACE_H_


void HLCD_voidsendcmd(u8 copy_u8cmd);
void HLCD_voidsenddata(u8 copy_u8data);
void HLCD_voidInt(void);
void CLCD_voidSendString(const char* Copy_pcString);
void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos);
void CLCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos );

#endif /* HLCD_INTERFACE_H_ */
