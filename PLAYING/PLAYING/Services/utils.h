/*
 * utils.h
 *
 * Created: 10/23/2023 9:29:36 AM
 *  Author: hkame
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define  F_CPU   8000000
#include <util/delay.h>


#define  READ_BIT(reg,bit)    ((reg>>bit)&1)
#define  SET_BIT(reg,bit)     (reg=reg|(1<<bit))
#define  CLR_BIT(reg,bit)     (reg=reg&(~(1<<bit)))
#define  TOG_BIT(reg,bit)     (reg=reg^(1<<bit))


#endif /* UTILS_H_ */