
#ifndef MEMMAP_H_
#define MEMMAP_H_

/* DIO_Registers */
#define DDRA (*(volatile unsigned char*)0x3A)
#define DDRB (*(volatile unsigned char*)0x37)
#define DDRC (*(volatile unsigned char*)0x34)
#define DDRD (*(volatile unsigned char*)0x31)

//#define PINA (*(const volatile unsigned char*)0x39)

#define PINA (*(volatile unsigned char*)0x39)
#define PINB (*(volatile unsigned char*)0x36)
#define PINC (*(volatile unsigned char*)0x33)
#define PIND (*(volatile unsigned char*)0x30)

#define PORTA (*(volatile unsigned char*)0x3B)
#define PORTB (*(volatile unsigned char*)0x38)
#define PORTC (*(volatile unsigned char*)0x35)
#define PORTD (*(volatile unsigned char*)0x32)

/*********************************** EXTERNAL INTERRUPT *************************************/

#define MCUCR	(*(volatile unsigned char*)0X55)
#define MCUCSR	(*(volatile unsigned char*)0X54)
#define GICR	(*(volatile unsigned char*)0X5B)
#define GIFR	(*(volatile unsigned char*)0X3A)


/*************************************	Interrupt vectors ********************************************/
/* External Interrupt Request 0 */
#define INT0_vect			__vector_1
/* External Interrupt Request 1 */
#define INT1_vect			__vector_2
/* External Interrupt Request 2 */
#define INT2_vect			__vector_3
/* Timer/Counter2 Compare Match */
#define TIMER2_COMP_vect		__vector_4
/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect			__vector_5
/* Timer/Counter1 Capture Event */
#define TIMER1_ICU_vect		__vector_6
/* Timer/Counter1 Compare Match A */
#define TIMER1_OCA_vect		__vector_7
/* Timer/Counter1 Compare Match B */
#define TIMER1_OCB_vect		__vector_8
/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect			__vector_9
/* Timer/Counter0 Compare Match */
#define TIMER0_OC_vect		__vector_10
/* Timer/Counter0 Overflow */
#define TIMER0_OV_vect			__vector_11
/* Serial Transfer Complete */
#define SPI_STC_vect			__vector_12
/* USART, Rx Complete */
#define UART_RX_vect			__vector_13
/* USART Data Register Empty */
#define UART_UDRE_vect			__vector_14
/* USART, Tx Complete */
#define UART_TX_vect			__vector_15
/* ADC Conversion Complete */
#define ADC_vect			   __vector_16
/* EEPROM Ready */
#define EE_RDY_vect			   __vector_17
/* Analog Comparator */
#define ANA_COMP_vect			__vector_18
/* 2-wire Serial Interface */
#define TWI_vect			    __vector_19
/* Store Program Memory Ready */
#define SPM_RDY_vect			__vector_20

#define BAD_vect        __vector_default
/**************************************************************/

#  define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)






/************************** ADC_Registers ****************************/
#define ADMUX (*(volatile unsigned char*)0x27)

#define ADLAR 5
#define REFS0 6
#define REFS1 7


#define ADCSRA (*(volatile unsigned char*)0x26)
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE  3
#define ADIF  4
#define ADATE 5
#define ADSC  6
#define ADEN  7

#define ADCL (*(volatile unsigned char*)0x24)
#define ADCH (*(volatile unsigned char*)0x25)
#define ADC (*(volatile unsigned short*)0x24)





/************************************************************************************************/
/* Timer 0 */

#define TCNT0   (*(volatile u8*)0x52)
#define TCCR0   (*(volatile u8*)0x53)

/* TCCR0 */
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0

#define TWCR    (*(volatile unsigned char*)0x56)
#define SPMCR   (*(volatile unsigned char*)0x57)
#define TIFR    (*(volatile unsigned char*)0x58)
#define TIMSK   (*(volatile unsigned char*)0x59)

/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0

#define OCR0    (*(volatile unsigned char*)0x5C)
/****************************************************************************************************/

/*TIMER 1*/


#define ICR1         (*(volatile unsigned short*)0x46)
#define ICR1L     (*(volatile unsigned char*)0x46)
#define ICR1H     (*(volatile unsigned char*)0x47)
#define OCR1B     (*(volatile unsigned short*)0x48)
#define OCR1BL    (*(volatile unsigned char*)0x48)
#define OCR1BH       (*(volatile unsigned char*)0x49)
#define OCR1A     (*(volatile unsigned short*)0x4A)
#define OCR1AL    (*(volatile unsigned char*)0x4A)
#define OCR1AH      (*(volatile unsigned char*)0x4B)
#define TCNT1       (*(volatile unsigned short*)0x4C)
#define TCNT1L    (*(volatile unsigned char*)0x4C)
#define TCNT1H    (*(volatile unsigned char*)0x4D)
#define TCCR1B       (*(volatile unsigned char*)0x4E)
#define TCCR1A        (*(volatile unsigned char*)0x4F)

#define SFIOR       (*(volatile unsigned char*)0x50)

#define OSCCAL       (*(volatile unsigned char*)0x51)
/******************************************************************************/
/* Timer 2 */

#define OCR2     (*(volatile unsigned char*)0x43)
#define TCNT2    (*(volatile unsigned char*)0x44)
#define TCCR2    (*(volatile unsigned char*)0x45)




/* TCCR2 */
#define FOC2    7
#define WGM20   6
#define COM21   5
#define COM20   4
#define WGM21   3
#define CS22    2
#define CS21    1
#define CS20    0

/* ASSR */
/* bits 7-4 reserved */
#define AS2     3
#define TCN2UB  2
#define OCR2UB  1
#define TCR2UB  0

/* TCCR1A */
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

/* TCCR1B */
#define ICNC1   7
#define ICES1   6
/* bit 5 reserved */
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

/* WDTCR */
#define WDTCR    (*(volatile unsigned char*)0x41)
/* bits 7-5 reserved */
#define WDTOE   4
#define WDE     3
#define WDP2    2
#define WDP1    1
#define WDP0    0

/***************************	UART	******************************/

#define	UDR		(*(volatile u8*)0x2C)
#define	UCSRA	(*(volatile u8*)0x2B)
#define	UCSRB	(*(volatile u8*)0x2A)
#define	UCSRC	(*(volatile u8*)0x40)
#define	UBRRL	(*(volatile u8*)0x29)
#define	UBRRH	(*(volatile u8*)0x40)	

#define RXCIE 	7
#define TXCIE 	6
#define UDRIE 	5
#define RXEN 	4
#define TXEN 	3
#define UCSZ2   2
#define RXB8 	1
#define TXB8	0


/***************************	SPI	******************************/

#define SPCR (*(volatile u8*)0x2D)
#define SPSR (*(volatile u8*)0x2E)
#define SPDR (*(volatile u8*)0x2F)

/********* SPCR ********/
#define SPIE	7
#define SPE		6
#define DORD 	5
#define MSTR 	4
#define CPOL 	3
#define CPHA 	2
#define SPR1 	1
#define SPR0	0

/********* SPDR ********/
#define SPIF 	7
#define WCOL  	6
#define SPI2X	0

#endif /* MEMMAP_H_ */
