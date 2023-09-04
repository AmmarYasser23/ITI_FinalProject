#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "GIE.h"
#include "avr/io.h"
#include "TIMER.h"

void (*TIMER0_pvCallBackFunc)(void) = NULL;


void TIMER0_Init(void){
	// wave generation : noraml mode
	CLR_BIT(TCCR0 , TCCR0_WGM00);
	CLR_BIT(TCCR0 , TCCR0_WGM01);

	//Enable PIE of normal intrrupt
	SET_BIT(TIMSK , TIMSK_TOIE0);

	//Set compare match value
	//OCR0=125;

	// prescaler
	SET_BIT(TCCR0 , TCCR0_CS00);
	SET_BIT(TCCR0 , TCCR0_CS01);
	CLR_BIT(TCCR0 , TCCR0_CS02);


}

u8   TIMER0_u8SetCallBack(void ( *Copy_pvCallBackFunc)(void)){

	u8 u8ErrorStstus_Local = OK;
	if(Copy_pvCallBackFunc != NULL){
		TIMER0_pvCallBackFunc = Copy_pvCallBackFunc;
	}
	else{
		u8ErrorStstus_Local = NULL_POINTER;
	}
	return u8ErrorStstus_Local;
}


/* Actual ISR */
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void){
	if(TIMER0_pvCallBackFunc != NULL){
		TIMER0_pvCallBackFunc();
	}
}
