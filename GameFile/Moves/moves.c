#include "moves.h"
/**
 * brief MOVE piece from 1 block to other
 *
 * params *move contains move variables
 * params *chess_board declares the board
 */

uint8_t move_piece(MOVE *move, BOARD *chess_board){
	uint8_t block_val;
	block_val = get_block(move->initial_col, move->initial_row_val);

	if(erase_block_val(move->initial_row, move->initial_col, chess_board));
	else{
		printf("Illegal Stuff\n");
		return FAILED;
	}
	if(erase_block_val(move->final_row, move->final_col, chess_board));
	else{
		printf("Illegal Stuff\n");
		return FAILED;
	}

	put_block_value_to_designated_block(move->final_row, move->final_col, block_val, chess_board);


	block_val = get_block(move->final_col, move->final_row_val);
	return SUCCESS;
}

/*
 * brief Erases the value int the given block
 * 
 * params row_alpha row alphabet of block
 * params col_no column number of block
 * params *chess_board declares the board
 */ 
uint32_t erase_block_val(char row_alpha, uint8_t col_no, BOARD *chess_board){
	uint32_t shift = 1, row_val;
	uint8_t row_num;
	row_num = row_alpha - 'a';
	while(shift < 9){
		if(shift == col_no){
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
			chess_board->row[row_num] &= row_val;
			return SUCCESS;
		}
		shift++;
	}
	return FAILED;
}
/**
 * brief puts a specific value to the selected block 
 *
 * params row_alpha row alphabet of block
 * params col_no column number of block
 * params block_val value of block that need to be put
 * params *chess_board declares the board
 */
void put_block_value_to_designated_block(char row_alpha, uint8_t col_no, uint8_t block_val, BOARD *chess_board){
	uint8_t row_num;
	row_num = row_alpha - 'a';
	chess_board->row[row_num] |= (block_val << (4 * (8 - col_no)));
}
