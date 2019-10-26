#include "../Boards/boards.h"
void print_board(char board);
void display_board_set_default(char display_board[37][58]);
void display_saved_board(char display_board[37][58], FILE *fp);
void change_move(char initial_row, uint32_t initial_col, char final_row, uint32_t final_col, uint8_t block_val, char display_board[37][58]);
