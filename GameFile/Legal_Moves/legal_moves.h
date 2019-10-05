#include "../Typedef/headers.h"
#include "../Typedef/typedef.h"
uint8_t legal_move_check(uint8_t block_val, MOVE *move);
int pawn_legal(MOVE *move);
int bishop_legal(MOVE *move);
int knight_legal(MOVE *move);
int rook_legal(MOVE *move);
int queen_legal(MOVE *move);
int king_legal(MOVE *move);
/* To be implemented */
int legal_kill(MOVE *move);
int is_empty(char final_row, uint32_t final_col);
void init_moves(char initial_row, char final_row, uint32_t initial_col, uint32_t final_col);
