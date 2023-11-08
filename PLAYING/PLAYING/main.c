#include "StdTypes.h"
#include "MemMap.h"
#include "utils.h"

#include "DIO_interface.h"
#include "Ex_INT.h"
#include "Timer.h"
#include "UART.h"

#include "Sev_Segment.h"
#include "KeyPad_interface.h"
#include "LCD_interface.h"
#include "SPI.h"

# define GLOBAL_DISABLE()   __asm__ __volatile__ ("cli" ::)		//global Int Disable
# define GLOBAL_ENABLE()    __asm__ __volatile__ ("sei" ::)		//global Int Enable

u32 counter;
u32 TOGGLE_COUNTER;
u32 pressed_counter;
u8 count[4] = {0};
u8 flag;
u8 pressed[4] = {0};
u8 current;

void flash_fast(DIO_Pin_type pin)
{	
	for(u8 i=0; i<4; i++)
	{
		if(pressed[i]==3)
		{
			if(TOGGLE_COUNTER/20 == 0)
			{
				DIO_WritePin(pin+i, HIGH);
			}
			else if(TOGGLE_COUNTER/20 == 1)
			{
				DIO_WritePin(pin+i, LOW);
			}
			else if(TOGGLE_COUNTER/20 >= 3)
			{
				TOGGLE_COUNTER=0;
			}
		}
	}
}

void flash_slow(DIO_Pin_type pin)
{
	for(u8 i=0; i<4; i++)
	{
		if(pressed[i]==2)
		{
			if(TOGGLE_COUNTER/40 == 0)
			{
				DIO_WritePin(pin+i, HIGH);
			}
			else if(TOGGLE_COUNTER/40 == 1)
			{
				DIO_WritePin(pin+i, LOW);
			}
			else if(TOGGLE_COUNTER/40 >= 3)
			{
				TOGGLE_COUNTER=0;
			}
		}
	}
}

void ON_OFF(DIO_Pin_type pin, u8* c)
{
	for(u8 i=0; i<4; i++)
	{
		if(pressed[i]==1)
		{
			if(c[i]==3)
			{
				c[i]=0;
				pressed[i]=0;
				DIO_WritePin(pin+i,LOW);
			}
			else if(c[i]==1)
			{
				DIO_WritePin(pin+i,HIGH);
			}
		}
	}
}

void motor_Off(void)
{
	DIO_WritePin(PIND0,LOW);
	DIO_WritePin(PIND1,LOW);
}

void motor_cw(void)
{
	DIO_WritePin(PIND0,HIGH);
	DIO_WritePin(PIND1,LOW);
}

void Task_1_button(void)
{
	for(u8 i=0; i<4; i++)
	{
		LCD_GoTo(0,0);
		LCD_WriteNumber(count[0]);
		LCD_GoTo(0,2);
		LCD_WriteNumber(count[1]);
		LCD_GoTo(0,4);
		LCD_WriteNumber(count[2]);
		LCD_GoTo(0,6);
		LCD_WriteNumber(count[3]); 
		
		
		if( !DIO_ReadPin(PINA0+i) )
		{
			current=i;
			count[i]++;
			TCNT0 =0;
			counter=0;
			while(!DIO_ReadPin(PINA0+i));
			TOGGLE_COUNTER =0;
			pressed_counter = counter;
		}
		
		if( !DIO_ReadPin(PINB0) )
		{
			while(!DIO_ReadPin(PINB0) );
			flag^=1;
		}
	}
}

void Task_2_Led(void)
{
	for(u8 i=0; i<4; i++)
	{
		if(pressed[i]==3)
		{
			count[i]=1;
			flash_fast(PINC0);
		}
		else if(pressed[i]==2)
		{
			count[i]=1;
			flash_slow(PINC0);
		}
		else if(pressed[i]==1)
		{	
			ON_OFF(PINC0, count);
		}
	}
}

void Task_3_motor(void)
{
	if(flag==0)
	{
		motor_Off();
	}
	else 
	{
		motor_cw();
	}
}
	



int main(void)
{
	DIO_init();
	LCD_Init();
	TIMER0_Init(TIMER0_NORMAL_MODE, TIMER0_SCALER_1024);
	GLOBAL_ENABLE();
	TIMER0_OV_InterruptEnable();
	
	LCD_GoTo(0,3);
	LCD_WriteString((u8*)"!!HELLO!!");
	_delay_ms(1000);
	LCD_Clear();
	
	while(1)
	{
		Task_1_button();
		Task_2_Led();
		Task_3_motor();	
	}
}



ISR(TIMER0_OV_vect)
{
	if(pressed_counter >= 50)
	{
		pressed[current] = 3;
	}
	else if(pressed_counter >= 20)
	{
		pressed[current] = 2;
	}
	else if(pressed_counter < 20 )
	{
		pressed[current] = 1;
	}
	counter++; 
	TOGGLE_COUNTER++;
}
