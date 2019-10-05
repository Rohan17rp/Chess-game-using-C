#define ROW_SPAN        8
#define COL_SPAN        8
#define SUCCESS         true
#define FAILED          false        

#ifndef BOARD_DEF
#define BOARD_DEF
typedef struct board{
        uint32_t row[8];
}BOARD;
BOARD chess_board;
#endif

#ifndef MOVE_DEF
#define MOVE_DEF
typedef struct Move {
        char initial_row;
        char final_row;
        uint32_t initial_col;
        uint32_t final_col;
        uint32_t initial_row_val;
        uint32_t final_row_val;
}MOVE;
MOVE move;
#endif
