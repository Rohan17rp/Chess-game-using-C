#include "modules.h"

int main(){
	/* Variable Declarations */
        uint32_t initial_column_number, final_column_number;
        uint8_t initial_block_val, final_block_val;
	char initial_row_alphabet, final_row_alphabet;

	/* Take Move input from user */
        scanf("%c%d%c%d", &move.initial_row, &move.initial_col, &move.final_row, &move.final_col);
	
	/* Set Board to default state */
	set_board_default(&chess_board);

//	printf("First row of chess board : %x\n", chess_board.row[0]);	

	/* Before Move */
        move.initial_row_val = get_row(move.initial_row, &chess_board);
        initial_block_val = get_block(move.initial_col, move.initial_row_val);
	printf("%x\t%d\n", move.initial_row_val, initial_block_val);

	move_piece(&move, &chess_board);

	/* After Move */
        move.final_row_val = get_row(move.final_row, &chess_board);
        final_block_val = get_block(move.final_col, move.final_row_val);
	printf("%x\t%d\n", move.final_row_val, final_block_val);

return 0;
}

