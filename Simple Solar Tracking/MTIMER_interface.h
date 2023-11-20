/******************************************************/
/******************************************************/
/******************************************************/
/************* Author : Amr Tawakol ****************/
/************* Layer  : MCAL           ****************/
/************* Module : Timer          ****************/
/************* Version : 1.00          ****************/
/************* Date   : 8/2023      ****************/
/******************************************************/
/******************************************************/
/******************************************************/
#ifndef MTIMER_INTERFACE_H_
#define MTIMER_INTERFACE_H_

typedef enum{
	TIMER1_NO_PRESCALER ,
	TIMER1_8_PRESCALER  ,
	TIMER1_64_PRESCALER ,
	TIMER1_256_PRESCALER ,
	TIMER1_1024_PRESCALER ,
}TIMER1_PRESCALER_t;

typedef enum{
	TOP_CTC_OCR1A,
	TOP_CTC_ICR1,
	TOP_FPWM_OCR1A,
	TOP_FPWM_ICR1,
	TOP_NORMAL_0xffff,

}TIMER1_TOPMODES_t;

typedef enum{
	CTC_NORMAL_MODE,
	CTC_TOGGLE,
	CTC_CLR,
	CTC_SET,
	FPWM_NON_INVERTING,
	FPWM_INVERTING,
	PPWM_INVERTING,
	PPWM_NON_INVERTING,
}TIMER1MODES_t;

#define ICU_FALLING           1
#define ICU_RISING            2


void MTIMER0_voidInit();
void MTIMER0_voidDisable();
void MTIMER0_voidPreload(u8 Copy_u8Preload);
void MTIMER0_voidSetDutyCycle(u8 Copy_u8DutyCycle);
void MTIMER0_voidCompMatchValue(u8 Copy_u8ComMatchValue);
void MTIMER0_voidSetCallBack_OVF(void (*Copy_pf)(void) );
void MTIMER0_voidSetCallBack_CMP(void (*Copy_pf)(void) );

void MTIMER1_voidInit(TIMER1MODES_t Copy_enuTimer1Mode , TIMER1_TOPMODES_t Copy_enuTimer1TopMode,TIMER1_PRESCALER_t Copy_enuTimer1Prescaler);
void MTIMER1_voidSetTopValue(u16 Copy_TopValue ,TIMER1_TOPMODES_t Copy_enuTimer1TopMode);
void MTIMER1_voidSetDutyCycle(u16 Copy_DutyCycleValue);
void MTIMER1_voidSetICUSense(u8 Copy_ICUSense);
u16 MTIMER1_voidGetICUValue();
void MTIMER1_voidEnableICUInterrupt();


/*
void MTIMER1_voidInit();
void MTIMER1_voidDisable();
void MTIMER1_voidPreload(u8 Copy_u8Preload);
void MTIMER1_voidSetDutyCycle(u8 Copy_u8DutyCycle);
void MTIMER1_voidCompMatchValue(u8 Copy_u8ComMatchValue);
void MTIMER1_voidSetCallBack_OVF(void (*Copy_pf)(void) );
void MTIMER1_voidSetCallBack_CMP(void (*Copy_pf)(void) );*/


#endif /* MTIMER_INTERFACE_H_ */
