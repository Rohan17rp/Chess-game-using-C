#ifndef ATTACK_BIT_BOARDS
#define ATTACK_BIT_BOARDS
#include "boards.h"
#endif
typedef struct pieces{
	uint64_t WHITE_PAWN;
	uint64_t WHITE_KNIGHT;
	uint64_t WHITE_BISHOP;
	uint64_t WHITE_ROOK;
	uint64_t WHITE_QUEEN;
	uint64_t WHITE_KING;

	uint64_t BLACK_PAWN;
	uint64_t BLACK_KNIGHT;
	uint64_t BLACK_BISHOP;
	uint64_t BLACK_ROOK;
	uint64_t BLACK_QUEEN;
	uint64_t BLACK_KING;

	uint64_t BLANK_SPACE;
}PIECES;

void bitboard_init(PIECES *piece){
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
void get_position_bitboards(BOARD *chess_board, PIECES *piece){
	bitboard_init(piece);
	int pos = 0, row_num, column_number, block_val;
	char row_alphabet;
	column_number = 1;
	row_alphabet = 'a';
	while(row_alphabet < 'i'){
		while(column_number < 9){
			row_num = (int)row_alphabet - (int)'a';
//			pos = row_num * 8 + column_number - 1;
			block_val = get_block(column_number, get_row(row_alphabet, chess_board));
			switch(block_val){
				case 0:
					piece->BLANK_SPACE |= (1u << pos);
					break;
				case 1:
					piece->WHITE_PAWN |= (1u << pos);
					break;
				case 9:
					piece->BLACK_PAWN |= (1u << pos);
					break;
				case 2:
					piece->WHITE_KNIGHT |= (1u << pos);
					break;
				case 10:
					piece->BLACK_KNIGHT |= (1u << pos);
					break;
				case 3:
					piece->WHITE_BISHOP |= (1u << pos);
					break;
				case 11:
					piece->BLACK_BISHOP |= (1u << pos);
					break;
				case 4:
					piece->WHITE_ROOK |= (1u << pos);
					break;
				case 12:
					piece->BLACK_ROOK |= (1u << pos);
					break;
				case 5:
					piece->WHITE_QUEEN |= (1u << pos);
					break;
				case 13:
					piece->BLACK_QUEEN |= (1u << pos);
					break;
				case 6: 
					piece->WHITE_KING |= (1u << pos);
					break;
				case 14:
					piece->BLACK_KING |= (1u << pos);
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
}

/* Calculates all possible moves */
void calculate_all(){

}
int main(){
	PIECES piece;
	set_board_default(&chess_board);
	print_hex_board(&chess_board);
	get_position_bitboards(&chess_board, &piece);
	printf("BLANK SPACE  %016lx\n", piece.BLANK_SPACE);

	printf("\n");

	printf("WHITE PAWN   %016lx\n", piece.WHITE_PAWN);
	printf("WHITE KNIGHT %016lx\n", piece.WHITE_KNIGHT);
	printf("WHITE BISHOP %016lx\n", piece.WHITE_BISHOP);
	printf("WHITE ROOK   %016lx\n", piece.WHITE_ROOK);
	printf("WHITE QUEEN  %016lx\n", piece.WHITE_QUEEN);
	printf("WHITE KING   %016lx\n", piece.WHITE_KING);

	printf("\n\n");

	printf("BLACK PAWN   %016lx\n", piece.BLACK_PAWN);
	printf("BLACK KNIGHT %016lx\n", piece.BLACK_KNIGHT);
	printf("BLACK BISHOP %016lx\n", piece.BLACK_BISHOP);
	printf("BLACK ROOK   %016lx\n", piece.BLACK_ROOK);
	printf("BLACK QUEEN  %016lx\n", piece.BLACK_QUEEN);
	printf("BLACK KING   %016lx\n", piece.BLACK_KING);
}
