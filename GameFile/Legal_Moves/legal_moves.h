#include "../Typedef/headers.h"
#include "../Typedef/typedef.h"

bool legal_move_check(uint8_t block_val_initial, uint8_t block_val_final, MOVE *move);
bool empty_legal(MOVE *move);
bool pawn_legal(MOVE *move);
bool bishop_legal(MOVE *move);
bool knight_legal(MOVE *move);
bool rook_legal(MOVE *move);
bool queen_legal(MOVE *move);
bool king_legal(MOVE *move);
bool legal_kill(uint8_t initial_block_val, uint8_t final_block_val);
bool check_blocking_piece(MOVE *move, BOARD *board, uint8_t block_val_initial);

bool pawn_block();
bool knight_block();
bool bishop_block();
bool rook_block();
bool queen_block();
bool king_check();
