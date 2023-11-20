/*
 * M-adc_program.c

 *
 *  Created on: Aug 9, 2023
 *      Author: Amr Tawakol
 */


#include "STD_TYPES.h"
#include  "BIT_MATH.h"
#include "M_adc_interface.h"
#include "M_adc_register.h"
#include "M_adc_config.h"
#include "M_adc_private.h"
void MADC_voidinit(void){
	CLR_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_ADLAR);


	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	SET_BIT(ADCSRA,ADCSRA_ADEN);

}
u16 MADC_u16GetValue(u8 COPY_u8channel){
ADMUX&=0b11100000;
ADMUX|=COPY_u8channel;
SET_BIT(ADCSRA,ADCSRA_ADSC);
while (GET_BIT(ADCSRA,ADCSRA_ADIF)==0);
SET_BIT(ADCSRA,ADCSRA_ADIF);
return ADC_DATA_REG;
}
u16 MAP_U16MAPPING(u16 x_max, u16 x_min ,u16 y_max,u16 y_min,u16 y){
	u16 x;
	x=((u32)((u32)(x_max-x_min)*(y-y_min))/(y_max-y_min))+(x_min);
	return x;
}

