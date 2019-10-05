#include "../Typedef/headers.h"
#include "../Typedef/typedef.h"
uint8_t legal_move_check(uint8_t block_val_initial, uint8_t block_val_final, MOVE *move);
int pawn_legal(MOVE *move);
int bishop_legal(MOVE *move);
int knight_legal(MOVE *move);
int rook_legal(MOVE *move);
int queen_legal(MOVE *move);
int king_legal(MOVE *move);
int legal_kill(uint8_t final_block_val);
int check_blocking_piece(MOVE *move, BOARD *board, uint8_t block_val_initial);
