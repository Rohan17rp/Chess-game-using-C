#include "modules.h"

int main(){
	/* Variable Declarations */
	uint32_t initial_column_number, final_column_number;
	uint8_t initial_block_val, final_block_val;
	char initial_row_alphabet, final_row_alphabet;
	bool check_mate;
	check_mate = false;
	/* Set Board to default state */
	set_board_default(&chess_board);
	while(!check_mate){
		/* Take Move input from user */
		scanf("\n%c%d%c%d", &move.initial_row, &move.initial_col, &move.final_row, &move.final_col);

		/* Before Move */

		/* Get Value of initial block to move */
		move.initial_row_val = get_row(move.initial_row, &chess_board);
		initial_block_val = get_block(move.initial_col, move.initial_row_val);

		/* Get Value of Final block where piece is to be moved */
		move.final_row_val = get_row(move.final_row, &chess_board);
		final_block_val = get_block(move.final_col, move.final_row_val);

		/* Prints board */
		print_hex_board(&chess_board);

		/* Check For Legal Move */
		if(legal_move_check(initial_block_val, final_block_val, &move, &chess_board)){
			if(move_piece(&move, &chess_board)){
				printf("Legal Move\n");
		/* Print board after legal move */
		print_hex_board(&chess_board);
			}
			else{
				printf("Illegal Move\n");
			}
		}
		else{
			printf("Illegal Move\n");
		}


		/* After Move */
		move.final_row_val = get_row(move.final_row, &chess_board);
		final_block_val = get_block(move.final_col, move.final_row_val);
	}
	return 0;

}
