#include "../Boards/boards.h"

bool legal_move_check(uint8_t block_val_initial, uint8_t block_val_final, MOVE *move, BOARD *chess_board);
bool empty_legal(MOVE *move);
bool pawn_legal(MOVE *move, uint8_t initial_block_val, uint8_t final_block_val);
bool bishop_legal(char initial_row, char final_row, uint32_t initial_col, uint32_t final_col);
bool knight_legal(MOVE *move);
bool rook_legal(char initial_row, char final_row, uint32_t initial_col, uint32_t final_col);
bool queen_legal(char initial_row, char final_row, uint32_t initial_col, uint32_t final_col);
bool king_legal(MOVE *move);
bool legal_kill(uint8_t initial_block_val, uint8_t final_block_val);
bool check_blocking_piece(MOVE *move, BOARD *board, uint8_t block_val_initial);

bool pawn_kill_legal(MOVE *move, uint8_t initial_block_val, uint8_t final_block_val);
bool pawn_move_legal(MOVE *move, uint8_t initial_block_val, uint8_t final_block_val);
bool pawn_first_move_legal(MOVE *move, uint8_t initial_block_val, uint8_t final_block_val, BOARD *board);
int pawn_promotion(MOVE *move, uint8_t initial_block_val, char choice, BOARD *chess_board);
bool knight_block();
bool bishop_block(char initial_row, char final_row, uint32_t initial_col, uint32_t final_col, BOARD *chess_board);
bool rook_block(char initial_row, char final_row, uint32_t initial_col, uint32_t final_col, BOARD *chess_board);
bool queen_block(char initial_row, char final_row, uint32_t initial_col, uint32_t final_col,BOARD *chess_board);

bool king_check(char king_row, uint32_t king_col, BOARD *chess_board);

bool is_killed(uint8_t initial_block_val, uint8_t final_block_val);
bool is_empty(uint8_t final_block_val);
