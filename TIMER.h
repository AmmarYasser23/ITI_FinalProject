/*
 * TIMER.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Mariam
 */

#ifndef TIMER_H_
#define TIMER_H_

//TCCR0
#define  TCCR0_FOC0    7
#define  TCCR0_WGM00   6
#define  TCCR0_COM01   5
#define  TCCR0_COM00   4
#define  TCCR0_WGM01   3
#define  TCCR0_CS02    2
#define  TCCR0_CS01    1
#define  TCCR0_CS00    0

//TIMSK
#define  TIMSK_TOIE0  0
#define  TIMSK_OCIE0  1


void TIMER0_Init(void);
u8   TIMER0_u8SetCallBack(void ( *Copy_pvCallBackFunc)(void));



#endif /* TIMER_H_ */

