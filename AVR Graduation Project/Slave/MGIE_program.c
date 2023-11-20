#include "STD_TYPES.h"
#include "macros.h"

#include "MGIE_interface.h"
#include "MGIE_registers.h"






void MGIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}
void MGIE_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}
