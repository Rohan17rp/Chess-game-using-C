#include "legal_moves.h"

/**
 * brief Return SUCCESS when move is legal FAILED if otherwise
 *
 * param block_val value of a block on the board
 * param move struct keeping track of moves
 */

bool legal_move_check(uint8_t block_val_initial, uint8_t block_val_final, MOVE *move){
	if(legal_kill(block_val_initial, block_val_final)){
		bool legal;
		switch(block_val_initial){
			case 0:
				printf("Can't move an empty block\n");
				legal = empty_legal(move);
				break;
			case 1:
				legal = pawn_legal(move);
				break;
			case 9:
				legal = pawn_legal(move);
				break;
			case 2: 
				legal = knight_legal(move);
				break;
			case 10: 
				legal = knight_legal(move);
				break;
			case 3:
				legal = bishop_legal(move);
				break;
			case 11:
				legal = bishop_legal(move);
				break;
			case 4:
				legal = rook_legal(move);
				break;
			case 12:
				legal = rook_legal(move);
				break;
			case 5:
				legal = queen_legal(move);
				break;
			case 13:
				legal = queen_legal(move);
				break;
			case 6: 
				legal = king_legal(move);
				break;
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
 * brief Return SUCCESS when move is legal FAILED if otherwise
 * for Empty Box
 *
 * param move struct keeping track of moves
 */
bool empty_legal(MOVE *move){
	return FAILED;
}

/**
 * brief Return SUCCESS when move is legal FAILED if otherwise
 * for Pawn
 *
 * param move struct keeping track of moves
 */
//RETURNS ONLY SUCCESS AS OF NOW
bool pawn_legal(MOVE *move){
	return SUCCESS;
}

/**
 * brief Return SUCCESS when move is legal FAILED if otherwise
 * for Knight
 *
 * param move struct keeping track of moves
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
 * brief Return SUCCESS when move is legal FAILED if otherwise
 * for Bishop
 *
 * param move struct keeping track of moves
 */
//x+c, y-c is also permissible, to be implemented
bool bishop_legal(MOVE *move){
	if(!(abs(move->final_col - move->initial_col) ^ (abs(move->final_row - move->initial_row))))
		return SUCCESS;
	else 
		return FAILED;
}

/**
 * brief Return SUCCESS when move is legal FAILED if otherwise
 * for Rook
 *
 * param move struct keeping track of moves
 */
bool rook_legal(MOVE *move){
	bool mov_row, mov_col;
	mov_row = move->initial_col ^ move->final_col;
	mov_col = move->initial_row ^ move->final_row;
	if(mov_row ^ mov_col)
		return SUCCESS;
	else 
		return FAILED;
}

/**
 * brief Return SUCCESS when move is legal FAILED if otherwise
 * for Queen
 *
 * param move struct keeping track of moves
 */
bool queen_legal(MOVE *move){
	if(rook_legal(move) ^ bishop_legal(move))
		return SUCCESS;
	else 
		return FAILED;
}

/**
 * brief Return SUCCESS when move is legal FAILED if otherwise
 * for King
 *
 * param move struct keeping track of moves
 */
bool king_legal(MOVE *move){
	if((abs(move->initial_col - move->final_col) <= 0x1) & (abs(move->initial_row - move->final_row) <= 0x1))
		return SUCCESS;
	else 
		return FAILED;
}

/**
 * brief Checks whether the final block is of same color or different color 
 * 	if it has same color move is illegal
 *	if it has different color then the piece can be elominated
 *
 * param final_block_val value of block where piece is being moved
 */
bool legal_kill(uint8_t initial_block_val, uint8_t final_block_val){
	if((final_block_val >> 3) ^ (initial_block_val >> 3))
		return SUCCESS;
	else if(final_block_val == 0)
		return SUCCESS;
	else{ 
		printf("Can't Kill Your Own Piece\n");
		return FAILED;
	}
}

/**
 * brief Checks whether there is an enemy piece blocking path
 *
 *
 */
bool check_blocking_piece(MOVE *move, BOARD *board, uint8_t block_val_initial){
	bool block;
	switch(block_val_initial){
		case 0x1:
			block = pawn_block();
			break;
		case 0x2:
			block = knight_block();
			break;
		case 0x3:
			/* Any block between initial and final position in same diagonal should return failure */
			block = bishop_block();
			break;
		case 0x4:
			block = rook_block();
			break;
		case 0x5:
			/* Combination of bishop and rook logic */
			block = queen_block();
			break;
		case 0x6:
			block = king_check();
			break;
		default : 
			printf("EMPTY");
			break;
	}
	return block;
}
bool pawn_block(){
	return SUCCESS;
}
bool knight_block(){
	return SUCCESS;
}
bool bishop_block(){
	return SUCCESS;
}
bool rook_block(){
	/* Any block between initial and final position in same line should return failure */
	/* Check row for blocking pieces */
	/* Check column for blocking pieces */

}
bool queen_block(){
	return SUCCESS;
}
bool king_check(){
	return SUCCESS;
}
