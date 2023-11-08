#include "SPI.h"


void SPI_Init(void)
{
	SET_BIT(SPCR,DORD);
	SET_BIT(SPCR,MSTR);
	SET_BIT(SPSR,SPI2X);
	SET_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPE);
}

u8 SPI_Send_Recieve(u8 data)
{
	// write puffer
	SPDR=data;
	while(!READ_BIT(SPSR,SPIF));
	//READ PUFFER
	return SPDR;
}