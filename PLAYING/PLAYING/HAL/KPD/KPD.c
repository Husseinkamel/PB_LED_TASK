/*
 * CFile1.c
 *
 * Created: 10/21/2023 8:49:06 PM
 *  Author: Sherif
 */ 

#include "KPD.h"

u8 KEY[4][4] = KPD_ARR_VAL;

u8 col_array[4] = { COL0_PIN, COL1_PIN, COL2_PIN, COL3_PIN };
u8 row_array[4] = { ROW0_PIN, ROW1_PIN, ROW2_PIN, ROW3_PIN };

void KPD_init(void) {
	u8 col_idx , row_idx ;

	for ( col_idx = 0 ; col_idx < 4; col_idx++){
	DIO_vsetPinMode(col_array[col_idx], INPUT_NORMAL);}

	for ( row_idx = 0 ; row_idx < 4; row_idx++){
	DIO_vsetPinMode(row_array[row_idx], OUTPUT_HIGH);}

}

u8 KPD_GetKey(void) {

	u8 col_idx = 0, row_idx = 0;

	for (; row_idx < 4; row_idx++) {

		DIO_vsetPinMode(row_array[row_idx], OUTPUT_LOW);

		for (; col_idx < 4; col_idx++) {

			if (LOW == DIO_u8GetPinValue(col_array[col_idx])) {
				_delay_ms(35);
				if (LOW == DIO_u8GetPinValue(col_array[col_idx])) {

					DIO_vsetPinMode(row_array[row_idx], OUTPUT_HIGH);

					return KEY[col_idx][row_idx];

				}

			}

			DIO_vsetPinMode(row_array[row_idx], OUTPUT_HIGH);

		}

	}

	return NO_KEY;
}
