#include "stdint.h"
typedef struct Move {
        char initial_row;
        char final_row;
        uint32_t initial_col;
        uint32_t final_col;
}Move;
Move move;

uint32_t erase_block_val(Move *move, board *chess_board);
void move_piece(Move *move, board *chess_board);
