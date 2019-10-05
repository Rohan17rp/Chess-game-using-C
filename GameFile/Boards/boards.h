#include "../Typedef/headers.h"
#include "../Typedef/typedef.h"

uint8_t get_block(uint32_t column_number,uint32_t row_val);
void set_board_default(BOARD *chess_board);
uint32_t get_row(char row_alphabet, BOARD *chess_board);
void print_hex_board(BOARD *chess_board);
