

#ifndef UART_H_
#define UART_H_

#include "utils.h"
#include "MemMap.h"
#include "StdTypes.h"

void UART_Init(void);
void UART_SEND(u8 data);
u8 Uart_Recieve(void);

void UART_SEND_String(u8* str);

u8* Uart_Recieve_String(void);

#endif /* UART_H_ */