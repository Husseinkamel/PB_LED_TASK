/*
 * IncFile1.h
 *
 * Created: 10/21/2023 8:47:29 PM
 *  Author: Sherif
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

#include "STD_TYPES.h"
#include "DIO.h"
#define  F_CPU 16000000UL
#include <avr/delay.h>
#include "KPD_cfg.h"
#include "KPD_prv.h"

#define LOW 0
#define HIGH 1
#define NO_KEY '$'

void KPD_init(void);

u8 KPD_GetKey(void);


#endif /* INCFILE1_H_ */