


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#include "StdTypes.h"
#include "DIO_interface.h"
#include "KeyPad_Interface.h"


									//#include "Converter_interface.h"
#define  F_CPU   8000000
#include <util/delay.h>

#define NO_KEY  'T'

void KEYPAD_Init(void);

u8 KEYPAD_GetKey(void);



#endif /* KEYPAD_INTERFACE_H_ */