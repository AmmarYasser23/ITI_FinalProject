#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "GIE.h"
#include <avr/io.h>
#include "UART.h"


void UARTInit(void)
{
	//BAUDRATE = 9600
	UBRRL = 51;
	UBRRH = 0;
	//FRAME FORMAT
	SET_BIT(UCSRC,URSEL);
	    //WORD SIZE = 8 BIT
	    SET_BIT(UCSRC,UCSZ1);
	    SET_BIT(UCSRC,UCSZ0);
	    CLR_BIT(UCSRB,UCSZ2);
	    //PARITY MODE: DISABLED
	    CLR_BIT(UCSRC, UPM0);
	    CLR_BIT(UCSRC, UPM1);
	    //STOP BIT: 1 BIT
	    CLR_BIT(UCSRC, USBS);

	//enable RX & TX
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
}

void USART_SendData(u8 u8Data_Copy)
{
	while(GET_BIT(UCSRA,UDRE)==0);
	UDR= u8Data_Copy;
}

u8 USART_RecieveData(void)
{
	while(GET_BIT(UCSRA,RXC)==0);
	return UDR;
}
void USART_SendString (u8* strcpy)
{
	u8 LocalCounter = 0;
	while(strcpy[LocalCounter] != '\0')
	{
		USART_SendData(strcpy[LocalCounter]);
		LocalCounter++;
	}

}

void USART_voidReceiveString(void)
{
	while(GET_BIT(UCSRA,RXC)==0);
	u8 i=0;
	while(1)
	{
			GlobalArr[i]=USART_RecieveData();
			if(GlobalArr[i]==13)
				break;
			i++;
	}
}
