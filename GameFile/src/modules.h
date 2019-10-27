/*
#define ROW_SPAN        8
#define COL_SPAN        8
#define SUCCESS         1
#define FAILED          0                 
*/
#include "../UI/board_display.h"
#include "../Typedef/headers.h"
#include "../Typedef/typedef.h"
#include "../Boards/boards.h"
#include "../Pieces/pieces.h"
#include "../Moves/moves.h"
#include "../Legal_Moves/legal_moves.h"
#include "../UI/ui.h"

bool check_gameOver(uint8_t);
FILE* open_file(FILE *fp, char *file_name, char *mode);
char* get_file_name(int argc, char *argv[]);
char getToken(MOVE *move);
