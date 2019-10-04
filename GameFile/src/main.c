#include "modules.h"

int main(){
	/* Variable Declarations */
        uint32_t initial_column_number, final_column_number, initial_row_val, final_row_val;
        uint8_t initial_block_val, final_block_val;
        char initial_row_alphabet, final_row_alphabet;

	

	/* Take Move input from user */
        scanf("%c%d%c%d", &move.initial_row, &move.initial_col, &move.final_row, &move.final_col);
	
	/* Set Board to default state */
        set_board_default(&chess_board);
	
	/* Before Move */
        initial_row_val = get_row(move.initial_row, &chess_board);
        initial_block_val = get_block(move.initial_col, initial_row_val);
	printf("%d\t%d\n", initial_row_val, initial_block_val);

	move_piece(&move, &chess_board);

	/* After Move */
        final_row_val = get_row(move.final_row, &chess_board);
        final_block_val = get_block(move.final_col, final_row_val);
	printf("%d\t%d\n", final_row_val, final_block_val);

return 0;
}

