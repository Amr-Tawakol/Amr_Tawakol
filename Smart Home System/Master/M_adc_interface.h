/*
 * M_adc_interface.h
 *
 *  Created on: Aug 9, 2023
 *      Author: Amr Tawakol
 */

#ifndef M_ADC_INTERFACE_H_
#define M_ADC_INTERFACE_H_
void MADC_voidinit(void);
u16 MADC_u16GetValue(u8 COPY_u8channel);
u16 MAP_U16MAPPING(u16 x_max, u16 x_min ,u16 y_max,u16 y_min,u16 y);

#define ADC_CHANNEL0      0
#define ADC_CHANNEL1      1
#define ADC_CHANNEL2      2
#define ADC_CHANNEL3      3
#define ADC_CHANNEL4      4
#define ADC_CHANNEL5      5
#define ADC_CHANNEL6      6
#define ADC_CHANNEL7      7


#endif /* M_ADC_INTERFACE_H_ */
