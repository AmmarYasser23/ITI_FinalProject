/*
 * main.c
 *
 *  Created on: Sep 4, 2023
 *      Author: ManDo2020
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "CLCD.h"
#include "UART.h"
#include "TIMER.h"
#include "DIO.h"
#include "GIE.h"
#include <avr/io.h>
#include "util/delay.h"

void LED_FUN1(void);
void LED_FUN2(void);
void LED_FUN3(void);
void LED_FUN4(void);
u32 count =0;

int main(void)
{

	//intializing local variables
	u8 PassCode [5] = "1234";
	u8 EnteredData;
	u8 EnteredPass[5];
	u8 Count1 =0;

	//making pin7 output (led pin)
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN7,DIO_OUTPUT);

	//Intializing lcd + lcd welcome msg
	DIO_SetPortDirection(DIO_PORTA,DIO_OUTPUT);
	/*LCD Control  pins direction*/
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN0,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN1,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN2,DIO_OUTPUT);

	CLCD_voidInit();

	 CLCD_GotoPosition(1,3);
	 CLCD_voidSendString(" HA M ZY ");
	 CLCD_GotoPosition(2,3);
	 CLCD_voidSendString("SMART HOME <3");
	 _delay_ms(5000);
	 CLCD_voidLCDClear();


	//intializing usart + checking for password
	UARTInit();
	USART_voidReceiveString();

	for(u8 i =0 ; i<5 ; i++)
	{
		EnteredPass[i] = GlobalArr[i];
	}

	for(u8 i =0 ; i<5 ; i++)
	{
		if( (EnteredPass[i]==PassCode[i]))
		{
		// Continue normally if pass is correct
			CLCD_voidSendString("Correct Pass");
		}

		else
		{
			//Display on LCD "PASS IS NOT CORRECT"
			Count1++;
			if(Count1==3)
			{
				//DISPLAY ON LCD "INTRUDER ALERT"
				CLCD_voidSendString("Wrong pass");
				return 0;
				//Dont complete the rest of the code
			}
		}
	}

	//IF passcode was correct display welcome message


	while(1)
	{
		//Display options of smart home on LCD
		EnteredData = USART_RecieveData();


		if(EnteredData==1) //Open Led For certain time (2 options 10 sec or  1 min)
		{
			//ASK user whether to turn on/off

			EnteredData = USART_RecieveData();
			if(EnteredData==1) //if to turn on
			{
			//ask for how long to turn on
			EnteredData = USART_RecieveData();
			if(EnteredData==1) //if for 60 sec
			{
				GIE_Enable();
				TIMER0_Init();
				TIMER0_u8SetCallBack(&LED_FUN1);
			}
			else if (EnteredData==2) //if for 10 sec
			{
				GIE_Enable();
				TIMER0_Init();
				TIMER0_u8SetCallBack(&LED_FUN2);
			}
			else
			{
				//Display error code on lcd and do nothing
			}
			}

			else if(EnteredData==2) // if to turn off
			{
				//ask for how long to turn off
				EnteredData = USART_RecieveData();
				if(EnteredData==1) //if for 60 sec
				{
					GIE_Enable();
					TIMER0_Init();
					TIMER0_u8SetCallBack(&LED_FUN3);
				}
				else if (EnteredData==2) //if for 10 sec
				{
					GIE_Enable();
					TIMER0_Init();
					TIMER0_u8SetCallBack(&LED_FUN4);
				}
				else
				{
					//Display error code on lcd and do nothing
				}

			}



		}
		else if (EnteredData==2) // Temp Control
		{

		}

		else if (EnteredData==3) // Open or close door
		{

		}

		else if (EnteredData==4) // Repeat Options For User
		{

		}

		else
		{
			//Display Invalid Value And Repeat the whole process
		}

	}

	return 0;
}


void LED_FUN1(void)
{
	DIO_SetPinValue(DIO_PORTD,DIO_PIN7,DIO_HIGH);
	count++;
	if(count==1831)
	{
		count=0;
		TOG_BIT(PORTD,DIO_PIN7);
		GIE_Disable();
	}
}

void LED_FUN2(void)
{
	DIO_SetPinValue(DIO_PORTD,DIO_PIN7,DIO_HIGH);
	count++;
		if(count==305)
		{
			count=0;
			TOG_BIT(PORTD,DIO_PIN7);
			GIE_Disable();
		}
}

void LED_FUN3(void)
{
	DIO_SetPinValue(DIO_PORTD,DIO_PIN7,DIO_LOW);
	count++;
	if(count==1831)
	{
		count=0;
		TOG_BIT(PORTD,DIO_PIN7);
		GIE_Disable();
	}
}

void LED_FUN4(void)
{
	DIO_SetPinValue(DIO_PORTD,DIO_PIN7,DIO_LOW);
	count++;
		if(count==305)
		{
			count=0;
			TOG_BIT(PORTD,DIO_PIN7);
			GIE_Disable();
		}
}

