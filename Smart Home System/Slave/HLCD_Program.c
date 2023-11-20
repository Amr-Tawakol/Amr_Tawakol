#include "macros.h"
#include "STD_TYPES.h"
#include <util/delay.h>

#include "MDIO_interface.h"
#include "HLCD_interface.h"
#include "HLCD_private.h"
#include "HLCD_config.h"



void HLCD_voidsendcmd(u8 copy_u8cmd)
{
	MDIO_voidSetPinValue(LCD_PORT_CTRL ,LCD_RS , DIO_LOW); //Clr RS to send Command
	MDIO_voidSetPinValue(LCD_PORT_CTRL ,LCD_RW , DIO_LOW); //Clr r/w to write
	MDIO_u8SetPortValue(LCD_PORT_DATA , copy_u8cmd); //send data
	MDIO_voidSetPinValue(LCD_PORT_CTRL ,LCD_EN , DIO_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_PORT_CTRL ,LCD_EN , DIO_LOW);

}
void HLCD_voidsenddata(u8 copy_u8data)
{
	MDIO_voidSetPinValue(LCD_PORT_CTRL ,LCD_RS , DIO_HIGH);
	MDIO_voidSetPinValue(LCD_PORT_CTRL ,LCD_RW , DIO_LOW);
	MDIO_u8SetPortValue(LCD_PORT_DATA , copy_u8data);
	MDIO_voidSetPinValue(LCD_PORT_CTRL ,LCD_EN , DIO_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_PORT_CTRL ,LCD_EN , DIO_LOW);
}
void HLCD_voidInt(void)
{
	_delay_ms(40);
	HLCD_voidsendcmd(0b00111000);
	HLCD_voidsendcmd(0b00001111);
	HLCD_voidsendcmd(0b00000001);
}
void CLCD_voidSendString(const char* Copy_pcString)
{
	u8  Local_u8Counter=0;
	while (Copy_pcString[Local_u8Counter]!= '\0'){
		HLCD_voidsenddata(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
}
void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos){
	u8 Local_u8Address ;
	if (Copy_u8XPos==0){
		Local_u8Address=Copy_u8YPos;
	}
	else if (Copy_u8XPos==1){
		Local_u8Address=Copy_u8YPos+0x40;
	}
	HLCD_voidsendcmd(Local_u8Address+128);
}
void CLCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos ){
	u8 Local_u8CGRAMAddeess=0,Local_u8Iterator;
	Local_u8CGRAMAddeess=Copy_u8PatternNumber*8;
	HLCD_voidsendcmd(Local_u8CGRAMAddeess+64);
	for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++){
		HLCD_voidsenddata(Copy_pu8Pattern[Local_u8Iterator]);
	}
	CLCD_voidGoToXY( Copy_u8XPos,Copy_u8YPos);
	HLCD_voidsenddata(Copy_u8PatternNumber);
}








