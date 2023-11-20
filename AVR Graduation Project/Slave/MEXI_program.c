#include "STD_TYPES.h"
#include "macros.h"

#include "MEXI_interface.h"
#include "MEXI_private.h"
#include "MEXI_config.h"
#include "MEXI_registers.h"
void(*EXIT_PvInt0Func)(void)=NULL;
void(*EXIT_PvInt1Func)(void)=NULL;
void(*EXIT_PvInt2Func)(void)=NULL;
//void (*sendISR)(void)
/*void Send_voidCallBack(ISR_EXI0(void))
{
	pf();


}*/
void MEXI0_voidInit(void)
{
	/*check Interupt Sense modes*/
#if INT0_SENS_MODES==LOW_LEVEL
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_SENS_MODES==FALLING
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_SENS_MODES==RISING
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_SENS_MODES==LOGIC_CHANGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#else
#error "INT0 SENSE CONTROL INVALID MODES"

#endif
	SET_BIT(GICR,GICR_INT0);

}
void MEXI1_voidInit(void)
{
#if INT1_SENS_MODES==RISING
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#elif INT1_SENS_MODES==FALLING
	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#elif INT1_SENS_MODES==LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
#elif INT1_SENS_MODES==LOGIC_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC10);
     CLR_BIT(MCUCR,MCUCR_ISC11);
#else
#error "INT1 SENSE CONTROL INVALID MODES"

#endif
	SET_BIT(GICR,GICR_INT1);

}
void MEXI2_voidInit(void)
{
#if INT2_SENS_MODES==RISING
	SET_BIT(MCUCSR,MCUCSR_ISC2);

#elif INT2_SENS_MODES==FALLING
	CLR_BIT(MCUCSR,MCUCSR_ISC2);


#else
#error "INT2 SENSE CONTROL INVALID MODES"
#endif
	SET_BIT(GICR,GICR_INT2);

}

u8 EXIT_u8Int0SetCallBack(void(*Copy_PvInt0Func)(void)){
	u8 Local_u8ErrorState=OK;
	if (Copy_PvInt0Func!=NULL){
		EXIT_PvInt0Func=Copy_PvInt0Func ;

	}

	else {
		Local_u8ErrorState=NULL_POINTER;
	}

	return Local_u8ErrorState;
}

u8 EXIT_u8Int1SetCallBack(void(*Copy_PvInt1Func)(void)){
	u8 Local_u8ErrorState=OK;
if (Copy_PvInt1Func!=NULL){
	EXIT_PvInt1Func=Copy_PvInt1Func ;

}

else {
	Local_u8ErrorState=NULL_POINTER;
}

return Local_u8ErrorState;
}
u8 EXIT_u8Int2SetCallBack(void(*Copy_PvInt2Func)(void)){
	u8 Local_u8ErrorState=OK;
	if (Copy_PvInt2Func!=NULL){
		EXIT_PvInt2Func=Copy_PvInt2Func ;

	}

	else {
		Local_u8ErrorState=NULL_POINTER;
	}

	return Local_u8ErrorState;
	}


void __vector_1 (void)  __attribute__((signal));
void __vector_1 (void)
{
	if (EXIT_PvInt0Func!=NULL){
	EXIT_PvInt0Func();
	}
	else{

	}
}


void __vector_2 (void)  __attribute__((signal));
void __vector_2 (void)
{
	if (EXIT_PvInt1Func!=NULL){
	EXIT_PvInt1Func();
	}
	else{

	}
}

void __vector_3 (void)  __attribute__((signal));
void __vector_3 (void)
{
	if (EXIT_PvInt2Func!=NULL){
	EXIT_PvInt2Func();
	}
	else{

	}
}











/*void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	sendISR();

}
*/


