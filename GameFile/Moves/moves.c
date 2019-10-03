#include "moves.h"

void move_piece(Move *move, board *chess_board){
	uint8_t block_val;
	block_val = get_block(move->initial_col, move->initial_row_val);
	printf("Block Value : %d\n", block_val);
	erase_block_val(move, chess_board);
	move->initial_row_val = get_row(move->initial_row, chess_board);
	block_val = get_block(move->initial_col, move->initial_row_val);
	printf("Block Value : %d\n", block_val);
}

/*
 * brief Erases the value int the given block
 * 
 * params
 */ 
uint32_t erase_block_val(Move *move, board *chess_board){
	uint32_t shift = 1, row_val;
	while(shift < 9){
		if(shift == move->initial_col){
			switch(shift){
				case 1:
					row_val = 0x0FFFFFFF;
					break;
				case 2:
					row_val = 0xF0FFFFFF;
					break;
				case 3:
					row_val = 0xFF0FFFFF;
					break;
				case 4:
					row_val = 0xFFF0FFFF;
					break;
				case 5:
					row_val = 0xFFFF0FFF;
					break;
				case 6:
					row_val = 0xFFFFF0FF;
					break;
				case 7:
					row_val = 0xFFFFFF0F;
					break;
				case 8:
					row_val = 0xFFFFFFF0;
					break;
			}
			printf("Row Value : %x\n", row_val);
			printf("Initial row value : %x\n", chess_board->row[move->initial_row]);
			chess_board->row[move->initial_row] &= row_val;
			printf("Final row value : %x\n", chess_board->row[move->initial_row]);
			return SUCCESS;
		}
		shift++;
	}
	return FAILED;
}
