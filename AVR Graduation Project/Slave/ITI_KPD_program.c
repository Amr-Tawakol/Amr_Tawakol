#include "STD_TYPES.h"
#include "MDIO_interface.h"

#include "ITI_KPD_config.h"
#include "ITI_KPD_interface.h"
#include "ITI_KPD_private.h"


u8 KPD_u8GetPressedKey(void)
{

	u8 LOCAL_u8KeyPressed=NKP , LOCAL_u8C_Indix , LOCAL_u8R_Indix ,LOCAL_u8PinState ;
	static u8 LOCAL_u8KPDarr[R_num][C_num]=KPD_Val;
	static u8 LOCAL_u8KPDColumnArr[C_num]={KPD_C0_PIN,KPD_C1_PIN,KPD_C2_PIN,KPD_C3_PIN};
	static u8 LOCAL_u8KPDRowArr[R_num]={KPD_R0_PIN,KPD_R1_PIN,KPD_R2_PIN,KPD_R3_PIN};

	for(LOCAL_u8C_Indix = 0; LOCAL_u8C_Indix < C_num; LOCAL_u8C_Indix++)
	{
		MDIO_voidSetPinValue(KPD_PORT,LOCAL_u8KPDColumnArr[LOCAL_u8C_Indix], DIO_LOW);
		for(LOCAL_u8R_Indix = 0; LOCAL_u8R_Indix < R_num; LOCAL_u8R_Indix++)
		{
			MDIO_Error_State_tGetPinValue(KPD_PORT,LOCAL_u8KPDRowArr[LOCAL_u8R_Indix],&LOCAL_u8PinState);
			if(LOCAL_u8PinState==DIO_LOW)
			{
				LOCAL_u8KeyPressed=LOCAL_u8KPDarr[LOCAL_u8R_Indix][LOCAL_u8C_Indix];
				while(LOCAL_u8PinState==DIO_LOW)
				{
					MDIO_Error_State_tGetPinValue(KPD_PORT,LOCAL_u8KPDRowArr[LOCAL_u8R_Indix],&LOCAL_u8PinState);
				}
				return LOCAL_u8KeyPressed;
			}
		}
		MDIO_voidSetPinValue(KPD_PORT,LOCAL_u8KPDColumnArr[LOCAL_u8C_Indix], DIO_HIGH);

	}

	return LOCAL_u8KeyPressed;

}

