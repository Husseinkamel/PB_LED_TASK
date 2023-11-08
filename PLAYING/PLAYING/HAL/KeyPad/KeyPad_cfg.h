

#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#include "StdTypes.h"

#define  ROWS   4
#define  COLS   4


#define FIRST_OUTPUT   PINC2
#define FIRST_INPUT    PIND7


const u8 KeysArr[ROWS][COLS]=
							  {	{'C','0','=','F'},
								{'1','2','3','E'},
								{'4','5','6','B'},
								{'7','8','9','A'} };


#endif /* KEYPAD_CFG_H_ */