#include<stdint.h>
#include<stdio.h>
typedef struct board{
	uint32_t row[8];
}board;
board chess_board;

uint8_t get_block(uint32_t column_number,uint32_t row_val);
void set_board_default(board *chess_board);
uint32_t get_row(char row_alphabet, board *chess_board);
