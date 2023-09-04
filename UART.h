#ifndef UART_H
#define UART_H
u8 GlobalArr[20];

//UCSRA REGISTR BITS DEFINITION
#define MPCM 0
#define U2X  1
#define PE   2
#define DOR  3
#define FE   4
#define UDRE 5
#define TXC  6
#define RXC  7

//UCSRB REGISTR BITS DEFINITION
#define TXB8  0
#define RXB8  1
#define UCSZ2 2
#define TXEN  3
#define RXEN  4
#define UDRIE 5
#define TXCIE 6
#define RXCIE 7

//UCSRC REGISTR BITS DEFINITION
#define UCPOL 0
#define UCSZ0 1
#define UCSZ1 2
#define USBS  3
#define UPM0  4
#define UPM1  5
#define UMSEL 6
#define URSEL 7

//UART FUNCTIONS IMPLEMENTATION

void UARTInit(void);
void USART_SendData(u8 u8Data_Copy);
u8 USART_RecieveData(void);
void USART_SendString (u8* strcpy);
void USART_voidReceiveString(void);
#endif
