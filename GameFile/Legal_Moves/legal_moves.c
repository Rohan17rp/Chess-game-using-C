#include "legal_moves.h"
#ifndef ATTACK_BIT_BOARDS
#define ATTACK_BIT_BOARDS
#include "../Boards/attack_bit_boards.h"
#endif

/**
 * \brief Return SUCCESS when move is legal FAILED if otherwise
 *
 * \param block_val value of a block on the board
 * \param move struct keeping track of moves
 */

bool legal_move_check(uint8_t block_val_initial, uint8_t block_val_final, MOVE *move, BOARD *chess_board){
	if(legal_kill(block_val_initial, block_val_final)){
		bool legal;
		switch(block_val_initial){
			case 0:
				//	printf("Can't move an empty block\n");
				legal = empty_legal(move);
				break;
			case 1:
			case 9:
				//en-passent and promotion not handled
				legal = pawn_legal(move, block_val_initial, block_val_final);
				if(!legal){
					legal = pawn_first_move_legal(move, block_val_initial, block_val_final, chess_board);
				}
				break;
			case 2:
			case 10:
				legal = knight_legal(move);
				break;
			case 3:
			case 11:
				legal = bishop_legal(move->initial_row, move->final_row, move->initial_col, move->final_col);
				if(legal)
					legal = bishop_block(move->initial_row, move->final_row, move->initial_col, move->final_col, chess_board);
				break;
			case 4:
			case 12:
				//castling not handled
				legal = rook_legal(move->initial_row, move->final_row, move->initial_col, move->final_col);
				if(legal)
					legal = rook_block(move->initial_row, move->final_row, move->initial_col, move->final_col, chess_board);
				break;
			case 5:
			case 13:
				legal = queen_legal(move->initial_row, move->final_row, move->initial_col, move->final_col);
				if(legal)
					legal = queen_block(move->initial_row, move->final_row, move->initial_col, move->final_col, chess_board);
				break;
			case 6: 
			case 14: 
				legal = king_legal(move);
				break;
			default:
				printf("Somethings Fishy, Check Input\n");
				legal = empty_legal(move);
				break;
		}
		if(legal == true)
			return SUCCESS;
		else
			return FAILED;
	}
	else 
		return FAILED;
}

/**
 * \brief legal move for Empty Box
 *
 * \param move struct keeping track of moves
 * \return FAILED as empty boxes don't move
 */
bool empty_legal(MOVE *move){
	return FAILED;
}

/**
 * \brief legal move for pawn
 *
 * \param move struct keeping track of moves
 * \return SUCCESS when move is legal FAILED if otherwise
 */
//Does not handle enpassent and 2 steps in first move
bool pawn_legal(MOVE *move, uint8_t initial_block_val, uint8_t final_block_val){
	if(pawn_kill_legal(move, initial_block_val, final_block_val))
		return SUCCESS;
	else if(pawn_move_legal(move, initial_block_val, final_block_val))
		return SUCCESS;
	return FAILED;
}
/**
 * \brief gives legal kills for pawn
 *
 */
bool pawn_kill_legal(MOVE *move, uint8_t initial_block_val, uint8_t final_block_val){
	if(final_block_val){
		if(initial_block_val >> 3){
			if((abs(move->final_col - move->initial_col) == 1) && ((move->initial_row - move->final_row) == 1)){
				//				if(legal_kill(initial_block_val, final_block_val))
				return SUCCESS;
			}
		}
		else{

			if((abs(move->final_col - move->initial_col) == 1) && ((move->final_row - move->initial_row) == 1)){
				//				if(legal_kill(initial_block_val, final_block_val));
				return SUCCESS;
			}
		}
	}
	return FAILED;

}
/**
 * \brief gives legal moves for pawn (excluding killing)
 *
 * 
 */
bool pawn_move_legal(MOVE *move, uint8_t initial_block_val, uint8_t final_block_val){
	if(is_empty(final_block_val)){
		if(!(move->initial_col ^ move->final_col)){
			if(initial_block_val >> 3){
				if(move->initial_row - move->final_row == 1)
					return SUCCESS;
			}
			else{
				if(move->final_row - move->initial_row == 1)
					return SUCCESS;
			}
		}
	}
	return FAILED;
}

/**
 * \brief allow pawn to move 2 steps if its first move
 *
 */
bool pawn_first_move_legal(MOVE *move, uint8_t initial_block_val, uint8_t final_block_val, BOARD *chess_board){
	uint8_t mid_block_val;
	/* Check whether move is made in same column */
	if(move->initial_col != move->final_col)
		return FAILED;
	/* white pawn first move */
	if(move->initial_row == 'b'){
		if(move->final_row == 'd'){
			mid_block_val = get_block(move->initial_col, get_row('c', chess_board)); 
			if(is_empty(mid_block_val) && is_empty(final_block_val)){
				return SUCCESS;
			}
		}
	}
	/* Black pawn first move */
	if(move->initial_row == 'g'){
		if(move->final_row == 'e'){
			mid_block_val = get_block(move->initial_col, get_row('f', chess_board)); 
			if(is_empty(mid_block_val) && is_empty(final_block_val)){
				return SUCCESS;
			}
		}
	}
	return FAILED;
}
/**
 * \brief checks for promotion of pawn
 * \prerequisite legal move must be checked
 */
int pawn_promotion(MOVE *move, uint8_t initial_block_val, char choice, BOARD *chess_board){
	int block_val;
	bool correct_choice = false;
	if(move->final_row == 'h' || move->final_row == 'a'){
		while(!correct_choice){
			if(initial_block_val >> 3){
				correct_choice = true;
				switch(choice){
					case 'n': block_val = 10;
						  break;
					case 'b': block_val = 11;
						  break;
					case 'r': block_val = 12;
						  break;
					case 'q': block_val = 13;
						  break;
					default: 
						  printf("Incorrect value %c\nEnter a valid input\n", choice);
						  correct_choice = false;
						  break;
				}
			}
			else{
				printf("What do you want your pawn to be promoted to\nQ - Queen\nR - Rook\nB - Bishop\nN - Knight\n");
				correct_choice = true;
				switch(choice){
					case 'N': block_val = 2;
						  break;
					case 'B': block_val = 3;
						  break;
					case 'R': block_val = 4;
						  break;
					case 'Q': block_val = 5;
						  break;
					default: 
						  printf("Incorrect value %c\nEnter a valid input\n",choice);
						  correct_choice = false;
						  break;
				}
			}
		}	
	}
	return block_val;
}

/**
 * \brief Return SUCCESS when move is legal FAILED if otherwise
 * for Knight
 *
 * \param move struct keeping track of moves
 */
bool knight_legal(MOVE *move){
	if((abs(move->initial_col - move->final_col) == 2) & (abs(move->initial_row - move->final_row) == 1))
		return SUCCESS;
	else if((abs(move->initial_col - move->final_col) == 1) & (abs(move->initial_row - move->final_row) == 2))
		return SUCCESS;
	else 
		return FAILED;
}

/**
 * \brief Return SUCCESS when move is legal FAILED if otherwise
 * for Bishop
 *
 * \param move struct keeping track of moves
 */
bool bishop_legal(char initial_row, char final_row, uint32_t initial_col, uint32_t final_col){
	if(!(abs(final_col - initial_col) ^ (abs(final_row - initial_row))))
		return SUCCESS;
	else 
		return FAILED;
}

/**
 * \brief Return SUCCESS when move is legal FAILED if otherwise
 * for Rook
 *
 * \param move struct keeping track of moves
 */
bool rook_legal(char initial_row, char final_row, uint32_t initial_col, uint32_t final_col){
	bool mov_row, mov_col;
	mov_row = initial_col ^ final_col;
	mov_col = initial_row ^ final_row;
	if(mov_row ^ mov_col)
		return SUCCESS;
	else 
		return FAILED;
}

/**
 * \brief Return SUCCESS when move is legal FAILED if otherwise
 * for Queen
 *
 * \param move struct keeping track of moves
 */
bool queen_legal(char initial_row, char final_row, uint32_t initial_col, uint32_t final_col){
	if(rook_legal(initial_row, final_row, initial_col, final_col) ^ bishop_legal(initial_row, final_row, initial_col, final_col))
		return SUCCESS;
	else 
		return FAILED;
}

/**
 * \brief Return SUCCESS when move is legal FAILED if otherwise
 * for King
 *
 * \param move struct keeping track of moves
 */
bool king_legal(MOVE *move){
	if((abs(move->initial_col - move->final_col) <= 0x1) & (abs(move->initial_row - move->final_row) <= 0x1))
		return SUCCESS;
	else 
		return FAILED;
}

/**
 * \brief Checks whether the final block is of same color or different color 
 * 	if it has same color move is illegal
 *	if it has different color then the piece can be elominated
 * \param initial_block_val value of initial block
 * \param final_block_val value of block where piece is being moved
 */
bool legal_kill(uint8_t initial_block_val, uint8_t final_block_val){
	if(is_killed(initial_block_val, final_block_val))
		return SUCCESS;
	else if(is_empty(final_block_val))
		return SUCCESS;
	else{ 
		//		printf("Can't Kill Your Own Piece\n");
		return FAILED;
	}
}

/**
 * \brief tells whether enemy piece is killed or not
 *
 */
bool is_killed(uint8_t initial_block_val, uint8_t final_block_val){
	if((final_block_val >> 3) ^ (initial_block_val >> 3))
		return SUCCESS;
	else 
		return FAILED;
}


/**
 * \brief SUCCESS if block is empty
 *
 */
bool is_empty(uint8_t final_block_val){
	if(final_block_val == 0)
		return SUCCESS;
	else 
		return FAILED;
}

/**
 * \brief checks for blocking piece between final and initial position
 * \prerequisites Legal_kill and pawn_legal should be implemented beforehand
 */
bool pawn_block(uint8_t final_block_val){
	if(!is_empty(final_block_val))
		return FAILED;
	return SUCCESS;
}
bool knight_block(){
	return SUCCESS;
}
/**
 * \brief checks for blocking piece between final and initial position
 * \prerequisites Legal_kill and bishop_legal should be implemented beforehand
 */
bool bishop_block(char initial_row, char final_row, uint32_t initial_col, uint32_t final_col, BOARD *chess_board){
	bool piece_unblocked;
	uint8_t block_val;
	uint32_t row_val;
	while(abs(initial_col - final_col)){
		if(initial_col < final_col)
			initial_col++;
		else
			initial_col--;
		if(initial_row < final_row)
			initial_row++;
		else
			initial_row--;
		if(initial_row == final_row)
			return SUCCESS;
		row_val =  get_row(initial_row, chess_board);
		block_val = get_block(initial_col, row_val);
		piece_unblocked = is_empty(block_val);
		if(!piece_unblocked)
			return FAILED;
	}	
	return SUCCESS;
}
/**
 * \brief checks for blocking piece between final and initial position
 * \prerequisites Legal_kill and rook_legal should be implemented beforehand
 */
bool rook_block(char initial_row, char final_row, uint32_t initial_col, uint32_t final_col, BOARD *chess_board){
	bool piece_unblocked;
	/* Any block between initial and final position in same line should return failure */
	uint8_t block_val;
	uint32_t row_val;
	/* Check column for blocking pieces */
	while(abs(initial_col - final_col) ){
		if(initial_col < final_col)
			initial_col++;
		else
			initial_col--;
		if (initial_col == final_col)
			return SUCCESS;
		row_val =  get_row(initial_row, chess_board);
		block_val = get_block(initial_col, row_val);
		piece_unblocked = is_empty(block_val);
		if(!piece_unblocked){
			return FAILED;
		}
	}
	/* Check row for blocking pieces */
	while(abs(initial_row - final_row)){
		if(initial_row < final_row)
			initial_row++;
		else
			initial_row--;
		if (initial_row == final_row)
			return SUCCESS;
		row_val =  get_row(initial_row, chess_board);
		block_val = get_block(initial_col, row_val);
		piece_unblocked = is_empty(block_val);
		if(!piece_unblocked){
			return FAILED;
		}
	}
	return SUCCESS;
}
/**
 * \brief cheks if there is a piece blocking queens path
 */
bool queen_block(char initial_row, char final_row, uint32_t initial_col, uint32_t final_col,BOARD *chess_board){
	if(rook_legal(initial_row, final_row, initial_col, final_col))
		return rook_block(initial_row, final_row, initial_col, final_col, chess_board);
	else
		return bishop_block(initial_row, final_row, initial_col, final_col, chess_board);
	return FAILED;
}

/**
 * \brief Detects whether king is in check
 */
bool king_check(char king_row, uint32_t king_col, BOARD *chess_board){
	char initial_row = 'a';
	uint32_t initial_col = 1;

	CHESS_PIECE *move_bit_board;
	move_bit_board = (CHESS_PIECE *)malloc(sizeof(MOVE_BIT_BOARD));
	move_bit_board_init(move_bit_board);

	uint8_t block_val_initial, block_val_final;
	block_val_final = get_block(king_col, get_row(king_row, chess_board));
	MOVE move;
	move.initial_row = initial_row;
	move.initial_col = initial_col;
	move.final_row = king_row;
	move.final_col = king_col;
	while(move.initial_row < 'i'){
		while(move.initial_col < 9){
			move.initial_row_val = get_row(move.initial_row, chess_board);
			move.final_row_val = get_row(move.final_row, chess_board);
			block_val_initial = get_block(move.initial_col, move.initial_row_val);
			printf("%d\t%c\n", move.initial_col, move.initial_row);

			move_bit_board = move_bitboard(move, *chess_board, move_bit_board);


			if(legal_move_check(block_val_initial, block_val_final, &move, chess_board)){
				printf("King is in check\n");
				return SUCCESS;
			}
			move.initial_col++;
		}
		move.initial_col = 1;
		move.initial_row++;
	}
	printf(" attack_bit_board->WHITE_PAWN  -> %016lx\n", move_bit_board->WHITE_PAWN);
	printf(" attack_bit_board->WHITE_ROOK  -> %016lx\n", move_bit_board->WHITE_ROOK);
	printf(" attack_bit_board->WHITE_KNIGHT-> %016lx\n", move_bit_board->WHITE_KNIGHT);
	printf(" attack_bit_board->WHITE_BISHOP-> %016lx\n", move_bit_board->WHITE_BISHOP);
	printf(" attack_bit_board->WHITE_QUEEN -> %016lx\n", move_bit_board->WHITE_QUEEN);
	printf(" attack_bit_board->WHITE_KING  -> %016lx\n", move_bit_board->WHITE_KING);
	printf(" attack_bit_board->BLACK_PAWN  -> %016lx\n", move_bit_board->BLACK_PAWN);
	printf(" attack_bit_board->BLACK_ROOK  -> %016lx\n", move_bit_board->BLACK_ROOK);
	printf(" attack_bit_board->BLACK_KNIGHT-> %016lx\n", move_bit_board->BLACK_KNIGHT);
	printf(" attack_bit_board->BLACK_BISHOP-> %016lx\n", move_bit_board->BLACK_BISHOP);
	printf(" attack_bit_board->BLACK_QUEEN -> %016lx\n", move_bit_board->BLACK_QUEEN);
	printf(" attack_bit_board->BLACK_KING  -> %016lx\n", move_bit_board->BLACK_KING);
	return FAILED;
}
