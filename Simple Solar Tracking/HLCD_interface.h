/******************************************************/
/******************************************************/
/******************************************************/
/************* Author : Amr Tawakol *******************/
/************* Layer  : HAL            ****************/
/************* Module : LCD            ****************/
/************* Version : 1.00          ****************/
/************* Date   : 8/2023       ****************/
/******************************************************/
/******************************************************/
/******************************************************/

#ifndef HLCD_INTERFACE_H_
#define HLCD_INTERFACE_H_





void HLCD_voidInit();
void HLCD_voidSendCommand(u8 Copy_u8Command);
void HLCD_voidSendData(u8 Copy_u8Data);
void HLCD_voidSendString(u8 *Copy_u8String);
void HLCD_voidSendDigit(u8 Copy_u8Digit);
void HLCD_voidSendGoTo(u8 Copy_u8X,u8 Copy_u8Y);
void HLCD_voidSendInt(s32 A_s32Number);
void HLCD_voidSendFloat(f32 Copy_f32Float,u8 Copy_u8X,u8 Copy_u8Y);
void HLCD_voidClear();



#endif /* HLCD_INTERFACE_H_ */
