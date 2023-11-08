/*
 * StdTypes.h
 *
 * Created: 10/23/2023 9:27:11 AM
 *  Author: hkame
 */ 


#ifndef STDTYPES_H_
#define STDTYPES_H_

typedef unsigned char		u8;
typedef unsigned short		u16;
typedef unsigned long		u32;
typedef unsigned long long	u64;

typedef signed char			s8;
typedef signed short		s16;
typedef signed long			s32;
typedef signed long long	S64;

typedef float f32;
typedef double f64;


typedef enum{
	FALSE,
	TRUE
}Boolean_t;

#define NULL_PTR ((void*)0)

typedef enum{
	OK,
	NOK,
	NULLPTR,
	OUTOFRANGE
}Error_t;

#define MAX_U8	 ((u8)255)
#define MAX_s8	 ((u8)0)

#define MAX_S8	  ((s8)127)
#define MIN_S8	  ((s8)-128)



#endif /* STDTYPES_H_ */