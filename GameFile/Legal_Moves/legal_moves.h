#include "../Boards/boards.h"

bool legal_move_check(uint8_t block_val_initial, uint8_t block_val_final, MOVE *move, BOARD *chess_board);
bool empty_legal(MOVE *move);
bool pawn_legal(MOVE *move);
bool bishop_legal(char initial_row, char final_row, uint32_t initial_col, uint32_t final_col);
bool knight_legal(MOVE *move);
bool rook_legal(char initial_row, char final_row, uint32_t initial_col, uint32_t final_col);
bool queen_legal(char initial_row, char final_row, uint32_t initial_col, uint32_t final_col);
bool king_legal(MOVE *move);
bool legal_kill(uint8_t initial_block_val, uint8_t final_block_val);
bool check_blocking_piece(MOVE *move, BOARD *board, uint8_t block_val_initial);

bool pawn_block();
bool knight_block();
bool bishop_block();
bool rook_block(char initial_row, char final_row, uint32_t initial_col, uint32_t final_col, BOARD *chess_board);
bool queen_block();
bool king_check();

bool is_killed(uint8_t initial_block_val, uint8_t final_block_val);
bool is_empty(uint8_t final_block_val);
