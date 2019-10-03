#include "modules.h"

board chess_board;

int main(){
	/* Variable Declarations */
        uint32_t initial_column_number, final_column_number, initial_row_val, final_row_val;
        uint8_t initial_block_val, final_block_val;
        char initial_row_alphabet, final_row_alphabet;

	/* Take Move input from user */
        scanf("%c%d%c%d", &initial_row_alphabet, &initial_column_number, &final_row_alphabet, &final_column_number);
	
	/* Set Board to default state */
        set_board_default(&chess_board);
	
	/* Before Move */
        initial_row_val = get_row(initial_row_alphabet, &chess_board);
        initial_block_val = get_block(initial_column_number, initial_row_val);
	printf("%d\t%d\n", initial_row_val, initial_block_val);
	
	/* After Move */
        final_row_val = get_row(final_row_alphabet, &chess_board);
        final_block_val = get_block(final_column_number, final_row_val);
	printf("%d\t%d\n", final_row_val, final_block_val);

return 0;
}

