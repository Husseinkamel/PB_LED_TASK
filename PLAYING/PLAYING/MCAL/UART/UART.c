
#include "UART.h"


void UART_Init(void)
{
	/* 
	TX,RX 		:ENABLE
	BAUDRATE 	:9600
	NO_PARITY
	Asynchronous
	DATA SIZE	:8 
	*/
	// NEED CFG FILE BUT NOT NOW;
	
	
	SET_BIT(UCSRB,3); // RX ENABLE
	SET_BIT(UCSRB,4); // TX ENABLE
	
	SET_BIT(UCSRC,1);  
	SET_BIT(UCSRC,2);  //8 BIT DATA
	
	UBRRL = 51;
}



void UART_SEND(u8 data)
{
	UDR = data;
	while(READ_BIT(UCSRA,5)==0);
}
 /*
u8 Uart_Recieve(void)
{
	if(UDR != 0xaa)
	{
		return UDR;
	}
}

void UART_SEND_String(u8* str)
{
	for(int i=0; str[i]!=0; i++)
	{
		UART_SEND(str[i]);
	}
}

u8* Uart_Recieve_String(void)
{
	u8 i=0;
	UDR = 0xAA;
	while ( READ_BIT(UCSRA,5) ); //UDRE
	if(UDR != 0xAA)
	{
		u8*str=Uart_Recieve();
		for(; str[i]!='\n' ; i++)
		{
			str[i]=Uart_Recieve();
		}
	}
	
}
	 */