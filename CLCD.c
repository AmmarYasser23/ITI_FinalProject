/*********************************************************/
/***********		Author: Mariam Awad  	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: CLCD 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 10-8/2023		 	**************/
/*********************************************************/

#include "STD_TYPES.h"
#include "util/delay.h"
#include "DIO.h"
#include"CLCD.h"

/*Write command steps */
/*Step 1 : Reset (RS&RW)pins */
/*Step 2 : Send command through data port */
/*Step 3 : Set the (E) pin for a period defined in datasheet ( 1ms is working) then reset it*/

void CLCD_voidSendCommand(u8 Copy_u8Command){

/*Write command steps */

/*Step 1 : Reset (RS&RW)pins */
	/*set RS pin to LOW for command*/
	DIO_SetPinValue(CLCD_CTRL_PORT ,CLCD_RS_PIN, DIO_LOW);
	/*set RW pin to LOW for write*/
	DIO_SetPinValue(CLCD_CTRL_PORT ,CLCD_RW_PIN, DIO_LOW);

/*Step 2 : Send command through data port */
    /*set  command at 8 pins */
	DIO_SetPortValue (CLCD_DATA_PORT,Copy_u8Command);

/*Step 3 : Set the (E) pin for a period defined in datasheet ( 2ms is working) then reset it*/
	/*set  Enable Pulse */
	DIO_SetPinValue(CLCD_CTRL_PORT ,CLCD_E_PIN, DIO_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(CLCD_CTRL_PORT ,CLCD_E_PIN, DIO_LOW);

}


void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*Set RS pin to high for data*/
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_HIGH);

	/*Set RW pin to low for write*/
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_LOW);

	/*Set Data to data pins*/
	DIO_SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	/*Send enable pulse*/
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_LOW);
}


void CLCD_voidInit(void)
{
	/*Wait for more than 30 ms*/
	_delay_ms(40);

	/*Function set command: 2 lines(N = 1), 5*8 Font size (F = 0 )*/
	CLCD_voidSendCommand(0b00111000);

	/*Display on off control: display enable, disable cursor, no blink cursor*/
	CLCD_voidSendCommand(0b00001100);

	/*Clear display*/
	CLCD_voidSendCommand(0b00000001);
}


void CLCD_voidSendString(const char* Copy_pcString)
{     u8 Local_u8Counter=0;
      while  ( Copy_pcString[Local_u8Counter] != '\0' ){
    	  CLCD_voidSendData(Copy_pcString[Local_u8Counter]);
    	  Local_u8Counter ++;
      }
}



void CLCD_voidLCDClear(void)
{
	CLCD_voidSendCommand(0X01);
}

void CLCD_GotoPosition(u8 Row , u8 Col)
{
	if(Row==1)
	{
		Col=Col-1;
		CLCD_voidSendCommand(0x80+Col);
	}
	if(Row==2)
	{
		Col=Col-1;
		CLCD_voidSendCommand(0xC0+Col);
	}
}











