

#ifndef SPI_H_
#define SPI_H_

#include "MemMap.h"
#include "StdTypes.h"
#include "utils.h"

void SPI_Init(void);

u8 SPI_Send_Recieve(u8 data);

	


#endif /* SPI_H_ */