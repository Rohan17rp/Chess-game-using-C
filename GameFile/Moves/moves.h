#include "../Boards/boards.h"
uint32_t erase_block_val(char row_alpha,uint8_t col_no, BOARD *chess_board);
uint8_t move_piece(MOVE *move, BOARD *chess_board);
void put_block_value_to_designated_block(char row_alpha, uint8_t col_no, uint8_t block_val, BOARD *chess_board);
