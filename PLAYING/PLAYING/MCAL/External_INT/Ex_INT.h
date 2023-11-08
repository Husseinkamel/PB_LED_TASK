

#ifndef EX_INT_H_
#define EX_INT_H_

typedef enum
{
Falling_Edge,
Rising_Edge
}Edge_t;

#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define INT0 6
#define INT1 7
#define INT2 6

void EX_INT0_INIT(Edge_t Edge);

#endif /* EX_INT_H_ */