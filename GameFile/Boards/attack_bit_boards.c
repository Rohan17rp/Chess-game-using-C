#include "attack_bit_boards.h"
#include "../Pieces/pieces.h"
/**
 * \brief initializes bitboard 
 */
void bitboard_init(CHESS_PIECE *piece){
	piece->WHITE_PAWN	= 0x0000000000000000; 
	piece->WHITE_KNIGHT	= 0x0000000000000000;
	piece->WHITE_BISHOP	= 0x0000000000000000;
	piece->WHITE_ROOK	= 0x0000000000000000;
	piece->WHITE_QUEEN	= 0x0000000000000000;
	piece->WHITE_KING	= 0x0000000000000000;

	piece->BLACK_PAWN	= 0x0000000000000000;
	piece->BLACK_KNIGHT	= 0x0000000000000000;
	piece->BLACK_BISHOP	= 0x0000000000000000;
	piece->BLACK_ROOK	= 0x0000000000000000;
	piece->BLACK_QUEEN	= 0x0000000000000000;
	piece->BLACK_KING	= 0x0000000000000000;

	piece->BLANK_SPACE	= 0x0000000000000000;
}

/**
 * \brief initializes move_bitboard 
 */
void move_bit_board_init(CHESS_PIECE *move_bit_board){
	move_bit_board->WHITE_PAWN	= 0x0000000000000000; 
	move_bit_board->WHITE_KNIGHT	= 0x0000000000000000;
	move_bit_board->WHITE_BISHOP	= 0x0000000000000000;
	move_bit_board->WHITE_ROOK	= 0x0000000000000000;
	move_bit_board->WHITE_QUEEN	= 0x0000000000000000;
	move_bit_board->WHITE_KING	= 0x0000000000000000;

	move_bit_board->BLACK_PAWN	= 0x0000000000000000;
	move_bit_board->BLACK_KNIGHT	= 0x0000000000000000;
	move_bit_board->BLACK_BISHOP	= 0x0000000000000000;
	move_bit_board->BLACK_ROOK	= 0x0000000000000000;
	move_bit_board->BLACK_QUEEN	= 0x0000000000000000;
	move_bit_board->BLACK_KING	= 0x0000000000000000;

	move_bit_board->BLANK_SPACE	= 0x0000000000000000;
}

/**
 * \brief Identifies pieces position by their block_value and returns bitmask of their positions
 */
CHESS_PIECE *get_position_bitboards(BOARD *chess_board, CHESS_PIECE *piece){
	bitboard_init(piece);
	int pos = 0, column_number, block_val;
	char row_alphabet;
	column_number = 1;
	row_alphabet = 'a';
	while(row_alphabet < 'i'){
		while(column_number < 9){
			block_val = get_block(column_number, get_row(row_alphabet, chess_board));
			switch(block_val){
				case 0:
					piece->BLANK_SPACE |= (1ul << pos);
					break;
				case 1:
					piece->WHITE_PAWN |= (1ul << pos);
					break;
				case 9:
					piece->BLACK_PAWN |= (1ul << pos);
					break;
				case 2:
					piece->WHITE_KNIGHT |= (1ul << pos);
					break;
				case 10:
					piece->BLACK_KNIGHT |= (1ul << pos);
					break;
				case 3:
					piece->WHITE_BISHOP |= (1ul << pos);
					break;
				case 11:
					piece->BLACK_BISHOP |= (1ul << pos);
					break;
				case 4:
					piece->WHITE_ROOK |= (1ul << pos);
					break;
				case 12:
					piece->BLACK_ROOK |= (1ul << pos);
					break;
				case 5:
					piece->WHITE_QUEEN |= (1ul << pos);
					break;
				case 13:
					piece->BLACK_QUEEN |= (1ul << pos);
					break;
				case 6: 
					piece->WHITE_KING |= (1ul << pos);
					break;
				case 14:
					piece->BLACK_KING |= (1ul << pos);
					break;
				default:
					printf("Error in positions\n");
					break;
			}
			pos++;
			column_number++;
		}
		row_alphabet++;
		column_number = 1;
	}
	return piece;
}

/**
 * \brief returns a bitmask of pieces to which the pieces could move
 *	eg. bitmask of the squares that a WHITE_PAWN can move is denoted by move_bit_board->WHITE_PAWN
 * \prerequisites should be run in a while loop that access all initial positions of board
 */
CHESS_PIECE *move_bitboard(MOVE move, BOARD chess_board, CHESS_PIECE *move_bit_board, char king_row, int king_col){
	uint8_t block_val_initial, block_val_final;
	int pos;
	move.final_col = 1;
	move.final_row = 'a';
	move.initial_col = 1;
	move.initial_row = 'a';
	while(move.initial_row < 'i'){
		while(move.initial_col < 9){
			move.initial_row_val = get_row(move.initial_row, &chess_board);
			block_val_initial = get_block(move.initial_col, move.initial_row_val);
			
			while(move.final_row < 'i'){
				while(move.final_col < 9){
					move.final_row_val = get_row(move.final_row, &chess_board);
					block_val_final = get_block(move.final_col, move.final_row_val);
					
					if(legal_move_check(block_val_initial, block_val_final, &move, &chess_board)){
						pos = ((move.final_row - 'a') * 8) + (move.final_col - 1);
						switch(block_val_initial){
							case 0:
								move_bit_board->BLANK_SPACE |= (1ul << pos);
								break;
							case 1:
								move_bit_board->WHITE_PAWN |= (1ul << pos);
								break;
							case 9:
								move_bit_board->BLACK_PAWN |= (1ul << pos);
								break;
							case 2:
								move_bit_board->WHITE_KNIGHT |= (1ul << pos);
								break;
							case 10:
								move_bit_board->BLACK_KNIGHT |= (1ul << pos);
								break;
							case 3:
								move_bit_board->WHITE_BISHOP |= (1ul << pos);
								break;
							case 11:
								move_bit_board->BLACK_BISHOP |= (1ul << pos);
								break;
							case 4:
								move_bit_board->WHITE_ROOK |= (1ul << pos);
								break;
							case 12:
								move_bit_board->BLACK_ROOK |= (1ul << pos);
								break;
							case 5:
								move_bit_board->WHITE_QUEEN |= (1ul << pos);
								break;
							case 13:
								move_bit_board->BLACK_QUEEN |= (1ul << pos);
								break;
							case 6: 
								move_bit_board->WHITE_KING |= (1ul << pos);
								break;
							case 14:
								move_bit_board->BLACK_KING |= (1ul << pos);
								break;
							default:
								printf("Error in positions\n");
								break;
								//						}
					}
					//		printf("%d\t%c\n%d\t%c\n%d\n", move.initial_col, move.initial_row, move.final_col, move.final_row, pos);
				}
				move.final_col++;
				}
				move.final_col = 1;
				move.final_row++;
			}
			
			move.final_col = 1;
			move.final_row = 'a';
			move.initial_col++;
		}
		move.final_col = 1;
		move.final_row = 'a';
		move.initial_col = 1;
		move.initial_row++;
	}

	return move_bit_board;
}
