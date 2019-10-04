#include "moves.h"

void move_piece(Move *move, board *chess_board){
	uint8_t block_val;
	block_val = get_block(move->initial_col, move->initial_row);
	printf("Block Value : %d\n", block_val);
	erase_block_val(move, chess_board);
	block_val = get_block(move->initial_col, move->initial_row);
	printf("Block Value : %d\n", block_val);
}

uint32_t erase_block_val(Move *move, board *chess_board){
	uint32_t shift = 'a', row_val;
	while(shift < 'i'){
		if(shift == move->initial_col){
		row_val = ((0xFFFFFFFF) & (0x0 >> move->initial_col - 1));
		printf("Row Value : %d\n", row_val);
		chess_board->row[move->initial_col] &= row_val;
		return SUCCESS;
		}
		shift++;
	}
	return FAILED;
}
