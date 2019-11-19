#include "../UI/board_display.h"
#include "../Typedef/headers.h"
#include "../Typedef/typedef.h"
#include "../Boards/boards.h"
#include "../Pieces/pieces.h"
#include "../Moves/moves.h"
#include "../Legal_Moves/legal_moves.h"
#include "../UI/ui.h"
#include "../Boards/attack_bit_boards.h"

bool check_gameOver(uint8_t);
FILE* open_file(FILE *fp, char *file_name, char *mode);
char* get_file_name(int argc, char *argv[]);
char getToken(MOVE *move);
void get_user_name(bool color, bool turn, char *name, char *name2, int mode);
bool check_check_mate(CHESS_PIECE *move_bit_board, CHESS_PIECE *pieces, MOVE move, BOARD chess_board, char king_row, int king_col, bool white_turn);
int return_legal_move(CHESS_PIECE *move_bit_board, CHESS_PIECE *pieces, MOVE *move, int size, BOARD chess_board, char king_row, int king_col, bool white_turn);
