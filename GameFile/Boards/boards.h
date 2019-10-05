/*
#include<stdint.h>
#include<stdio.h>
*/
#include "../Typedef/headers.h"
#include "../Typedef/typedef.h"
/*
typedef struct board{
	uint32_t row[8];
}board;
board chess_board;
*/
uint8_t get_block(uint32_t column_number,uint32_t row_val);
void set_board_default(BOARD *chess_board);
uint32_t get_row(char row_alphabet, BOARD *chess_board);
