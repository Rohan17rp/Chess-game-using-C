#include "legal_moves.h"

/**
 * brief Return SUCCESS when move is legal FAILED if otherwise
 *
 * param block_val value of a block on the board
 * param move struct keeping track of moves
 */

uint8_t legal_move_check(uint8_t block_val_initial, uint8_t block_val_final, MOVE *move){
	if(legal_kill(block_val_final)){
		uint8_t legal;
		if(block_val_initial == block_val_final){
			return FAILED;
		}
		switch(block_val_initial){
			case 0:
				printf("Can't move an empty block");
				break;
			case 1:
				legal = pawn_legal(move);
				break;
			case 2: 
				legal = knight_legal(move);
				break;
			case 3:
				legal = bishop_legal(move);
				break;
			case 4:
				legal = rook_legal(move);
				break;
			case 5:
				legal = queen_legal(move);
				break;
			case 6: 
				legal = king_legal(move);
				break;
			default:
				printf("Somethings Fishy, Check Input");
				break;
		}
		if(legal == 1)
			return SUCCESS;
		else
			return FAILED;
	}
	else 
		return FAILED;
}

/**
 * brief Return SUCCESS when move is legal FAILED if otherwise
 * for Pawn
 *
 * param move struct keeping track of moves
 */
int pawn_legal(MOVE *move){
	if(move->initial_col != move->final_col)
		return FAILED;
}

/**
 * brief Return SUCCESS when move is legal FAILED if otherwise
 * for Knight
 *
 * param move struct keeping track of moves
 */
int knight_legal(MOVE *move){

}

/**
 * brief Return SUCCESS when move is legal FAILED if otherwise
 * for Bishop
 *
 * param move struct keeping track of moves
 */
//x+c, y-c is also permissible, to be implemented
int bishop_legal(MOVE *move){
	if(!((move->final_col - move->initial_col) ^ (move->final_row - move->initial_row)))
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
int rook_legal(MOVE *move){
	if((move->initial_col ^ move->final_col) && (move->initial_row == move->final_row))
		return SUCCESS;
	else if((move->initial_row ^ move->final_row) && (move->initial_col == move->final_col))
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
int queen_legal(MOVE *move){
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
int king_legal(MOVE *move){
	if(!((move->initial_col - move->final_col) ^ 0x01) & !(move->initial_row ^ move->final_row))
		return SUCCESS;
	else if(!((move->initial_row - move->final_row) ^ 0x01) & !(move->initial_col ^ move->final_col))
		return SUCCESS;
	else if(!((move->final_col - move->initial_col) ^ 0x01) & !(move->initial_row ^ move->final_row)) 
		return SUCCESS;
	else if(!((move->final_row - move->initial_row) ^ 0x01) & !(move->initial_col ^ move->final_col))
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
int legal_kill(uint8_t final_block_val){
	if(final_block_val >> 3)
		return SUCCESS;
	else if(final_block_val == 0)
		return SUCCESS;
	else 
		return FAILED;
}

/**
 * brief Checks whether there is an enemy piece blocking path
 *
 *
 */
int check_blocking_piece(MOVE *move, BOARD *board, uint8_t block_val_initial){
	switch(block_val_initial){
		case 0x1:
			
			break;
		case 0x2:

			break;
		case 0x3:
			/* Any block between initial and final position in same diagonal should return failure */
			break;
		case 0x4:
			/* Any block between initial and final position in same line should return failure */
			if(move->initial_col - move->final_col){
				/* Check row for blocking pieces */
			}
			else{
				/* Check column for blocking pieces */
			}
			break;
		case 0x5:
			/* Combination of bishop and rook logic */
			break;
		case 0x6:
			break;
		default : 
			printf("EMPTY");
			break;
	}
}
