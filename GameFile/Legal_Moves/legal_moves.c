#include "legal_moves.h"

/**
 * brief Return SUCCESS when move is legal FAILED if otherwise
 *
 * param block_val value of a block on the board
 * param move struct keeping track of moves
 */

int legal_move_check(uint8_t block_val, Move *move){
	uint8_t legal;
	switch(block_val){
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

/**
 * brief Return SUCCESS when move is legal FAILED if otherwise
 * for Pawn
 *
 * param move struct keeping track of moves
 */
int pawn_legal(Move *move){
	if(move->initial_col != move->final_col)
		return FAILED;
}

/**
 * brief Return SUCCESS when move is legal FAILED if otherwise
 * for Knight
 *
 * param move struct keeping track of moves
 */
int knight_legal(Move *move){

}

/**
 * brief Return SUCCESS when move is legal FAILED if otherwise
 * for Bishop
 *
 * param move struct keeping track of moves
 */
int bishop_legal(Move *move){
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
int rook_legal(Move *move){
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
int queen_legal(Move *move){
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
int king_legal(Move *move){
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
