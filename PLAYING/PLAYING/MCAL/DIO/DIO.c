#include "StdTypes.h"
#include "MemMap.h"
#include "utils.h"
#include "DIO_interface.h"
#include "DIO_private.h"



const DIO_PinStatus_type DIO_PinsStatusArr[TOTAL_PINS]={
	INPULL,		 /* Port A Pin 0 ADC0*/
	INPULL,		 /* Port A Pin 1 ADC1*/
	INPULL,		 /* Port A Pin 2 */
	INPULL,		 /* Port A Pin 3 */
	OUTPUT_L,		 /* Port A Pin 4 */
	OUTPUT_L,		 /* Port A Pin 5 */
	OUTPUT_L,		 /* Port A Pin 6 */
	OUTPUT_L,		 /* Port A Pin 7 ADC7*/
	
	INPULL,		 /* Port B Pin 0   / */
	OUTPUT_H,		 /* Port B Pin 1   /*/
	OUTPUT_H,		 /* Port B Pin 2 / INT2*/
	OUTPUT_L,		 /* Port B Pin 3   /OC0*/
	OUTPUT_L,		 /* Port B Pin 4 /ss*/
	OUTPUT_L,		 /* Port B Pin 5 //mosi*/
	INFREE,		 /* Port B Pin 6 /miso*/
	OUTPUT_L,		 /* Port B Pin 7 clk*/
	
	
	OUTPUT_L,		 /* Port C Pin 0 */
	OUTPUT_L,		 /* Port C Pin 1 */
	OUTPUT_L,		 /* Port C Pin 2 */
	OUTPUT_L,		 /* Port C Pin 3 */
	OUTPUT_H,		 /* Port C Pin 4 */
	OUTPUT_H,		 /* Port C Pin 5 */
	OUTPUT_H,		 /* Port C Pin 6 */
	INFREE,		 /* Port C Pin 7 */
	
	OUTPUT_L,		 /* Port D Pin 0 */
	OUTPUT_L,		 /* Port D Pin 1 */
	INFREE,        /* Port D Pin 2 /INT0*/
	OUTPUT_H,        /* Port D Pin 3 / INT1 */
	OUTPUT_H,		 /* Port D Pin 4  OC1B*/
	OUTPUT_H,		 /* Port D Pin 5 OC1A*/
	OUTPUT_H,		 /* Port D Pin 6 /   ICP*/
	OUTPUT_H		 /* Port D Pin 7 */
};	


void DIO_InitPin(DIO_Pin_type pin_num, DIO_PinStatus_type status) //pin_num = 25. 
{
	DIO_Port_type port = pin_num/8;
	pin_num = pin_num%8;
	
	switch (status)
	{
	case OUTPUT_L:
		switch(port)
		{
			case PA:
			CLR_BIT(PORTA,pin_num);
			SET_BIT(DDRA,pin_num);
			break;
				
			case PB:
			CLR_BIT(PORTB,pin_num);
			SET_BIT(DDRB,pin_num);
			break;
			
			case PC:
			CLR_BIT(PORTC,pin_num);
			SET_BIT(DDRC,pin_num);
			break;
			
			case PD:
			CLR_BIT(PORTD,pin_num);
			SET_BIT(DDRD,pin_num);
			break;	
		}
		break;
		
		case OUTPUT_H:
		switch(port)
		{
			case PA:
			SET_BIT(PORTA,pin_num);
			SET_BIT(DDRA,pin_num);
			break;
			
			case PB:
			SET_BIT(PORTB,pin_num);
			SET_BIT(DDRB,pin_num);
			break;
			
			case PC:
			SET_BIT(PORTC,pin_num);
			SET_BIT(DDRC,pin_num);
			break;
			
			case PD:
			SET_BIT(PORTD,pin_num);
			SET_BIT(DDRD,pin_num);
			break;
		}
		break;
		
		
		case INFREE:
			switch(port)
			{
				case PA:
				CLR_BIT(PORTA,pin_num);
				CLR_BIT(DDRA,pin_num);
				break;
				
				case PB:
				CLR_BIT(PORTB,pin_num);
				CLR_BIT(DDRB,pin_num);
				break;
				
				case PC:
				CLR_BIT(PORTC,pin_num);
				CLR_BIT(DDRC,pin_num);
				break;
				
				case PD:
				CLR_BIT(PORTD,pin_num);
				CLR_BIT(DDRD,pin_num);
				break;
			}
			break;
			
		case INPULL:
			switch(port)
			{
				case PA:
				CLR_BIT(DDRA,pin_num);
				SET_BIT(PORTA,pin_num);
				break;
				
				case PB:
				CLR_BIT(DDRB,pin_num);
				SET_BIT(PORTB,pin_num);
				break;
				
				case PC:
				CLR_BIT(DDRC,pin_num);
				SET_BIT(PORTC,pin_num);
				break;
				
				case PD:
				CLR_BIT(DDRD,pin_num);
				SET_BIT(PORTD,pin_num);
				break;
				}
			break;			
	}
}


void DIO_init(void)
{
	DIO_Pin_type index=0;
	for(index = 0; index<TOTAL_PINS; index++)
	{
		DIO_InitPin(index, DIO_PinsStatusArr[index]);
	}
}

DIO_PinVoltage_type	DIO_ReadPin(DIO_Pin_type pin)
{	
	DIO_Port_type port = pin/TOTAL_PINS_Per_Port;
	pin = pin %TOTAL_PINS_Per_Port;
	DIO_PinVoltage_type reading=LOW;
	switch(port)
	{
		case PA:
		reading = READ_BIT(PINA,pin);
		break;
		
		case PB:
		reading = READ_BIT(PINB,pin);
		break;
		
		case PC:
		reading = READ_BIT(PINC,pin);
		break;
		
		case PD:
		reading = READ_BIT(PIND,pin);
		break;
	}
	return reading;
}

void DIO_WritePin(DIO_Pin_type pin ,DIO_PinVoltage_type volt)
{
		DIO_Port_type Port = pin/TOTAL_PINS_Per_Port;
		pin = pin % TOTAL_PINS_Per_Port;
		
		switch(volt)
			{
			case HIGH:
				switch(Port)
				{
					case PA:
					SET_BIT(PORTA,pin);
					break;
					
					case PB:
					SET_BIT(PORTB,pin);
					break;
					
					case PC:
					SET_BIT(PORTC,pin);
					break;
					
					case PD:
					SET_BIT(PORTD,pin);
					break;
				}
				break;
			
				case LOW:
				switch(Port)
				{
					case PA:
					CLR_BIT(PORTA,pin);
					break;
					
					case PB:
					CLR_BIT(PORTB,pin);
					break;
					
					case PC:
					CLR_BIT(PORTC,pin);
					break;
					
					case PD:
					CLR_BIT(PORTD,pin);
					break;
				}
				break;	
		}
}

void DIO_TogglePin(DIO_Pin_type pin)
{
	DIO_Port_type Port = pin/TOTAL_PINS_Per_Port;
	pin = pin % TOTAL_PINS_Per_Port;
	
	switch(Port)
	{
		case PA:
		TOG_BIT(PORTA,pin);
		break;
		
		case PB:
		TOG_BIT(PORTB,pin);
		break;
		
		case PC:
		TOG_BIT(PORTC,pin);
		break;
		
		case PD:
		TOG_BIT(PORTD,pin);
		break;
	}
}

void DIO_WritePort(DIO_Port_type port,u8 data)
{
	switch(port)
	{
		case PA:
		PORTA = data;
		break;
		
		case PB:
		PORTB = data;
		break;

		case PC:
		PORTC = data;
		break;
		
		case PD:
		PORTD = data;
		break;	
	}
}

u8 DIO_ReadPort(DIO_Port_type port)
{
	u8 data=0;
	switch(port)
	{
		case PA:
		data = PINA;
		break;
		
		case PB:
		data = PINB;
		break;

		case PC:
		data = PINC;
		break;
		
		case PD:
		data = PIND;
		break;
	}
	return data;
}

/* Make volt high if you need pull up resistor
 * Make volt low you don't want pull up  */

void DIO_InputPin(DIO_Pin_type pin ,DIO_PinVoltage_type volt)
{
		DIO_Port_type Port = pin/TOTAL_PINS_Per_Port;
		pin = pin % TOTAL_PINS_Per_Port;
		switch(volt)
		{
			case HIGH:
			switch(Port)
			{
				case PA:
				CLR_BIT(DDRA,pin);
				SET_BIT(PORTA,pin);
				break;
				
				case PB:
				CLR_BIT(DDRB,pin);
				SET_BIT(PORTB,pin);
				break;
				
				case PC:
				CLR_BIT(DDRC,pin);
				SET_BIT(PORTC,pin);
				break;
				
				case PD:
				CLR_BIT(DDRD,pin);
				SET_BIT(PORTD,pin);
				break;
			}
			break;
			case LOW:
			switch(Port)
			{
				case PA:
				CLR_BIT(DDRA,pin);
				CLR_BIT(PORTA,pin);
				break;
				
				case PB:
				CLR_BIT(DDRB,pin);
				CLR_BIT(PORTB,pin);
				break;
				
				case PC:
				CLR_BIT(DDRC,pin);
				CLR_BIT(PORTC,pin);
				break;
				
				case PD:
				CLR_BIT(DDRD,pin);
				CLR_BIT(PORTD,pin);
				break;
			}
			break;
		}
}
