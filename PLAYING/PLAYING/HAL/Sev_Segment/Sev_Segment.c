#define F_CPU 8000000
#include <util\delay.h>

#include "utils.h"
#include "StdTypes.h"
#include "MemMap.h"
#include "DIO_interface.h"
#include "Sev_Segment.h"


void Segment_Init(void)
{
	DIO_InitPin(PINB6,OUTPUT_L);
	DIO_InitPin(PINB5,OUTPUT_L);
	DIO_InitPin(PINA2,OUTPUT_L);
	DIO_InitPin(PINA3,OUTPUT_L);	
}

void Segment_display(u16 num)	//3456
{
	u8 d0,d1,d2,d3;
	u8 n0,n1,n2,n3;

	d0=num%10;	num/=10;
	d1=num%10;	num/=10;
	d2=num%10;  num/=10;
	d3=num;
	
	DIO_InitPin(PINB6,OUTPUT_H);
	DIO_InitPin(PINB5,OUTPUT_H);
	DIO_InitPin(PINA2,OUTPUT_H);
	DIO_InitPin(PINA3,OUTPUT_L);
	
	n0 = READ_BIT(d0,3);
	PORTB = (d0|(n0<<4))& (0xF7) ;
	_delay_us(200);
	
	/* *************************************** */

	DIO_InitPin(PINA2,OUTPUT_L);
	DIO_InitPin(PINA3,OUTPUT_H);
	
	n1 = READ_BIT(d1,3);
	PORTB = (d1 & 0xF7)|(n1<<4);
	_delay_us(200);
	
	/* *************************************** */
	
	DIO_InitPin(PINB5,OUTPUT_L);
	DIO_InitPin(PINA2,OUTPUT_H);
	
	n2 = READ_BIT(d2,3);
	PORTB = (d2 & 0xF7)|(n2<<4);
	_delay_us(200);

	/* *************************************** */
	DIO_InitPin(PINB6,OUTPUT_L);
	DIO_InitPin(PINB5,OUTPUT_H);
	
	n3 = READ_BIT(d3,3);
	PORTB = (d3 & 0xF7)|(n3<<4);
	_delay_us(200);
}
	
	
	/*_delay_ms(10);
	SET_BIT(PORTC,7);
	CLR_BIT(PORTC,6);
	SEGMENT_PORT = SegmentArr[d1]<<1;
	_delay_ms(10);*/