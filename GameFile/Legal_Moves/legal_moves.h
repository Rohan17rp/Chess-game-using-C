#include "../includes.h"
typedef struct Move {
	char initial_row;
	char final_row;
	uint32_t initial_col;
	uint32_t final_col;
}Move;
Move move;

int legal_move_check(uint8_t block_val, Move *move);
int pawn_legal(Move *move);
int bishop_legal(Move *move);
int knight_legal(Move *move);
int rook_legal(Move *move);
int queen_legal(Move *move);
int king_legal(Move *move);
/* To be implemented */
int legal_kill(Move *move);
int is_empty(char final_row, uint32_t final_col);
void init_moves(char initial_row, char final_row, uint32_t initial_col, uint32_t final_col);
