#include "ADC_interface.h"

void ADC_Init(ADC_VoltRef_type vref,ADC_Prescaler_type scaler)
{
	/* vref*/
	switch(vref)
	{
		case VREF_AREF:
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		case VREF_AVCC:
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		case VREF_256V:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;
	}
	/* prescaller*/
	
	ADCSRA&=0XF8;
	scaler&=0X07;
	ADCSRA=ADCSRA|scaler;
	/* enable ADC*/
	SET_BIT(ADCSRA,ADEN);
	
}

u16 ADC_Read(ADC_Channel_type CH)
{
	/* set channel mux*/
	ADMUX&=0XE0;//11100000
	ADMUX|=CH;
	
	SET_BIT(ADCSRA,ADSC);
	while(READ_BIT(ADCSRA,ADSC));
	
	
	return ADC;
}

















u16 ADC_READS_VOLT(ADC_Channel_type CH)
{
	ADMUX &= 70;
	ADMUX |= CH;
	
	SET_BIT(ADCSRA, ADSC);
	while(READ_BIT(ADCSRA, ADSC));
	
	/*
		U16 ADC = ADCL;
		ADC = ADCH>>8;
	*/
	
	return ADC;
}
