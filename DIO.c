/*********************************************************/
/***********		Author: Mariam Awad  	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: DIO 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 5-8/2023		 	**************/
/*********************************************************/

///////////////////////////////////////////////////////////////////
/*              1- DIO_SetPinValue()                         */
/*              2- DIO_GetPinValue()                         */
/*              3- DIO_SetPinDirection()                     */
/*              4- DIO_SetPortDirection()                    */ 
/*              5- DIO_SetPortValue()                        */
///////////////////////////////////////////////////////////////////

/*###############################################################*/
/*############################ STD LIBARARY #####################*/
/*############################    MCAL LIB  #####################*/
/*###############################################################*/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO.h"
#include"avr/io.h"
#include<util/delay.h>

/*###############################################################*/
/*############################ functions implementation #########*/
/*############################          IO Pins         #########*/
/*###############################################################*/

/*              1- DIO_SetPinValue()                            */
void DIO_SetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy)
{
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((u8PortIdCopy <= DIO_PORTD) && (u8PinIdCopy <=  DIO_PIN7))
	{
		if (u8PinValCopy ==  DIO_HIGH)
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case  DIO_PORTA: SET_BIT( PORTA,u8PinIdCopy); break;
				case  DIO_PORTB: SET_BIT( PORTB,u8PinIdCopy); break;
				case  DIO_PORTC: SET_BIT( PORTC,u8PinIdCopy); break;
				case  DIO_PORTD: SET_BIT( PORTD,u8PinIdCopy); break;
			}
		
		}
		
		else if (u8PinValCopy == DIO_LOW)
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case  DIO_PORTA: CLR_BIT( PORTA,u8PinIdCopy); break;
				case  DIO_PORTB: CLR_BIT( PORTB,u8PinIdCopy); break;
				case  DIO_PORTC: CLR_BIT( PORTC,u8PinIdCopy); break;
				case  DIO_PORTD: CLR_BIT( PORTD,u8PinIdCopy); break;
			}
		}
	
		else
		{
			/* Do nothing, Wrong value to set */
			//error, U not entered low or high
		}
	}
	
	else
	{
		/* Do nothing, Error in the Pin ID or PORT ID */
		//out off range
		
	}
}


/*              2- DIO_GetPinValue()                        */
u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy)
{
	/* Define Local Variable to get the BIT Value */
	u8 u8ResultLocal;
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((u8PortIdCopy <= DIO_PORTD) && (u8PinIdCopy <= DIO_PIN7))
	{
		/* Check on the Required PORT Number */
		switch (u8PortIdCopy)
		{
			case DIO_PORTA: u8ResultLocal= GET_BIT( PINA,u8PinIdCopy); break;
			case DIO_PORTB: u8ResultLocal= GET_BIT( PINB,u8PinIdCopy); break;
			case DIO_PORTC: u8ResultLocal= GET_BIT( PINC,u8PinIdCopy); break;
			case DIO_PORTD: u8ResultLocal= GET_BIT( PIND,u8PinIdCopy); break;
		}
	}
	
	else
	{
		/* return 0xff in case of error in the Pin ID or PORT ID */
		u8ResultLocal = 0xFF;
	}
	
	return u8ResultLocal;
}

/*              3- DIO_SetPinDirection()                    */
void DIO_SetPinDirection (u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy)
{
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((u8PortIdCopy <= DIO_PORTD) && (u8PinIdCopy <= DIO_PIN7))
	{
		if ( u8PinDirCopy == DIO_OUTPUT )
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case  DIO_PORTA: SET_BIT( DDRA,u8PinIdCopy); break;
				case  DIO_PORTB: SET_BIT( DDRB,u8PinIdCopy); break;
				case  DIO_PORTC: SET_BIT( DDRC,u8PinIdCopy); break;
				case  DIO_PORTD: SET_BIT( DDRD,u8PinIdCopy); break;
			}
		}
		
		else if ( u8PinDirCopy == DIO_INPUT )
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case  DIO_PORTA: CLR_BIT( DDRA,u8PinIdCopy); break;
				case  DIO_PORTB: CLR_BIT( DDRB,u8PinIdCopy); break;
				case  DIO_PORTC: CLR_BIT( DDRC,u8PinIdCopy); break;
				case  DIO_PORTD: CLR_BIT( DDRD,u8PinIdCopy); break;
			}
		}
		
		else
		{
			/* Do nothing, Wrong Direction Required */
		}
	}
	
	else
	{
		/* Do nothing, Error in the Pin ID or PORT ID */
	}
}

/*###############################################################*/
/*############################ functions implementation #########*/
/*############################          IO Ports        #########*/
/*###############################################################*/

/*              4- DIO_SetPortDirection()                   */ 

void DIO_SetPortDirection (u8 u8PortId, u8 u8PortDir)
{
	/* Check on the Required PORT Number */
	switch (u8PortId)
	{
		case      DIO_PORTA:  DDRA = u8PortDir; break;
		case      DIO_PORTB:  DDRB = u8PortDir; break;
		case      DIO_PORTC:  DDRC = u8PortDir; break;
		case      DIO_PORTD:  DDRD = u8PortDir; break;
		default: /* Wrong Port ID */       break;
	}
}
/*              5- DIO_SetPortValue()                   */


void DIO_SetPortValue (u8 u8PortId, u8 u8PortVal)
{
	/* Check on the Required PORT Number */
	switch (u8PortId)
	{
		case     DIO_PORTA: PORTA = u8PortVal; break;
		case     DIO_PORTB: PORTB = u8PortVal; break;
		case     DIO_PORTC: PORTC = u8PortVal; break;
		case     DIO_PORTD: PORTD = u8PortVal; break;
		default: /* Wrong Port ID */        break;
	}
}

