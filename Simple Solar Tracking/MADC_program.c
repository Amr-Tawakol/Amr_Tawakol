/******************************************************/
/******************************************************/
/******************************************************/
/************* Author : Amr Tawakol *******************/
/************* Layer  : MCAL           ****************/
/************* Module : ADC            ****************/
/************* Version : 1.00          ****************/
/************* Date   : 3/8/2023       ****************/
/******************************************************/
/******************************************************/
/******************************************************/


#include "STD_TYPES.h"
#include "MACROS.h"
#include "MADC_private.h"
#include "MADC_register.h"
#include "MADC_config.h"
#include "MADC_interface.h"

void MADC_voidInit()
{
	/*Select V REF*/
	CLR_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);
	/*Right Adjust*/
	CLR_BIT(ADMUX,ADMUX_ADLAR);

	/*Select 32 Prescaler*/
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	CLR_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);



	/*Enable ADC*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

u16 MADC_voidGetValue(u8 Copy_u8AdcChannel)
{
	ADMUX &= 0b11100000 ;// Clr The selection bits
	ADMUX |= Copy_u8AdcChannel ; //
	/*start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/*Busy wait until ADC Complete Converting*/
	while(GET_BIT(ADCSRA,ADCSRA_ADIF)==0);
	/**Clear ADC flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF) ;
	return ADC_DATA ;


}
