#include "Ex_INT.h"
#include "StdTypes.h"
#include "MemMap.h"
#include "utils.h"

void EX_INT0_INIT(Edge_t Edge)
{	
	switch(Edge)
	{
		case Falling_Edge:
		SET_BIT(MCUCR,ISC01);
		CLR_BIT(MCUCR,ISC00);
		break;
		case Rising_Edge:
		SET_BIT(MCUCR,ISC01);
		CLR_BIT(MCUCR,ISC00);
		break;
	}
	SET_BIT(GICR,INT0);
}


