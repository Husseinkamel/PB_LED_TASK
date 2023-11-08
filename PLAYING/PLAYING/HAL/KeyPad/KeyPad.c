




#include "KeyPad_interface.h"
#include "KeyPad_Cfg.h"

void KEYPAD_Init(void)
{
	for (u8 r=0 ;r<4; r++)
	{
		DIO_InitPin(PINC2+r,OUTPUT_H);
	}
	
	DIO_InitPin(PIND3,INFREE);
	for (u8 C=0 ; C<3; C++)
	{
		DIO_InitPin(PIND5+C,INFREE);
	}
}


u8 KEYPAD_GetKey(void)
{
	u8 r,c,key=NO_KEY;
	
	for (r=0; r<4; r++)
	{
		DIO_InitPin(PINC2+r,OUTPUT_L);
		for (c=0; c<4 ;c++)
		{
			if(c==0)
			{
				if (DIO_ReadPin(PIND3)==LOW)
				{
					key=KeysArr[r][c];
					_delay_ms(10);
					while(DIO_ReadPin(PIND3)==LOW);
					_delay_ms(10);
				}
			}
			else
			{
				if(DIO_ReadPin(PIND4+c)==LOW)
				{
					key=KeysArr[r][c];
					_delay_ms(10);
					while(DIO_ReadPin(PIND4+c)==LOW);
					_delay_ms(10);
				}
			}
			
		}
		DIO_InitPin(PINC2+r,OUTPUT_H);
	}
	return key;

}





/*
u8 KEYPAD_GetKey(void)
{
	u8 r,c,key = NO_KEY;
	for (r=0; r<4; r++)
	{
		DIO_WritePin(PINC2+r,LOW);
		for (c=0; c<4; c++)
		{
			if(c==0)
			{
				if( DIO_ReadPin(PIND3) == LOW )
				{
					key=KeysArr[r][c];
					while(DIO_ReadPin(PIND3) == LOW);
				}
			}
			
			else
			{
				if( DIO_ReadPin(PIND4+c) == LOW )
				{
					key=KeysArr[r][c];
					while(DIO_ReadPin(PIND4+c) == LOW);
				}
			}
		}
		
		DIO_WritePin(PINC2+r,HIGH);
	}

	return key;
	
}
*/






