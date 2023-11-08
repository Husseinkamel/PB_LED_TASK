

#ifndef LCD_CFG_H_

#define LCD_CFG_H_
#define  _8_BIT  0
#define  _4_BIT  1

/***********_8_BIT or _4_BIT *********************/
#define  LCD_MODE  _4_BIT


#define  RS    PINB4
#define  EN    PINB3
/**************** 4 BIT mode only *************/
#define D4  PINA4
#define D5  PINA5
#define D6  PINA6
#define D7  PINA7

/**************** 8 BIT mode only *************/
#define  LCD_PORT  PA

#endif /* LCD_CFG_H_ */