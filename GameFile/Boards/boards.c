#include "boards.h"
#include "../Pieces/pieces.h"

void set_board_default(BOARD *chess_board){ 
	chess_board->row[0] = 0x42365324;
	chess_board->row[1] = 0x11111111;
	chess_board->row[2] = 0x00000000;
	chess_board->row[3] = 0x00000000;
	chess_board->row[4] = 0x00000000;
	chess_board->row[5] = 0x00000000;
	chess_board->row[6] = 0x99999999;
	chess_board->row[7] = 0xCABEDBAC;
}
/**
 *\ brief Get a particular block of a chess BOARD
 *
 *\param row_val alphabet used to define value of row as 32-bit int
 *\param column_number number used to define corresponding column (takes value from 1-8)
 */

uint8_t get_block(uint32_t column_number, uint32_t row_val){
	uint8_t block_val;
	block_val = (uint8_t)(row_val >> (4 * (8 - column_number)));
	return block_val & 0x0000000F;
}
/**
 *\ brief finds the value of given row as 32-bit int
 *
 *\param row_alphabet alphabet used to define row
 */

uint32_t get_row(char row_alphabet, BOARD *chess_board){
	uint8_t row_num;
	row_num = row_alphabet - 'a';
	return chess_board->row[row_num];
}


/**
 *\ brief finds the value of given row as 32-bit int
 *
 *\param row_alphabet alphabet used to define row
 */

 void print_hex_board(BOARD *chess_board){
 	int i;
	printf("\n");
 	for(i = 0; i < 8; i++){
		printf("\t%08x\n",chess_board->row[i]);
	}
	printf("\n");
}
