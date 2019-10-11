#include "modules.h"

//print_hex_board(&chess_board);//This command works and prints board in form of hex values
int main(){

	/* Variable Declarations */
	uint32_t initial_column_number, final_column_number;
	uint8_t initial_block_val, final_block_val;
	char initial_row_alphabet, final_row_alphabet, color;
	bool check_mate, white_color, white_turn;

	/* Variable Initialization */
	check_mate = false;
	white_turn = true;

	/* Set Board to default state */
	set_board_default(&chess_board);

	/* Choose Player color
	 * Though useless now might come in handy later
	 */
	printf("Select Color to play with\nw for white\nb for black\n");
	while(1){
		scanf("\n%c",&color);
		if(color == 'w' || color == 'W'){
			white_color = true;
			break;
		}
		else if(color == 'b' || color == 'B'){
			white_color = false;
			break;
		}
		else
			printf("Enter a valid character\n");
	}

	/*Display Default Board */
	display_board_set_default(display_board);

	while(!check_mate){

		/* Printing Whose turn is it */		
		if(white_turn)
			printf("w->");
		else
			printf("b->");

		/* Take Move input from user */
		scanf("\n%c%d%c%d", &move.initial_row, &move.initial_col, &move.final_row, &move.final_col);

		/* Get Value of initial block to move */
		move.initial_row_val = get_row(move.initial_row, &chess_board);
		initial_block_val = get_block(move.initial_col, move.initial_row_val);

		/* Check whether right player is playin it */
		if(!((initial_block_val >> 3) ^ (white_turn))){
			printf("\nYou need to supress urge of moving enemy pieces\n");
			continue;
		}

		/* Get Value of Final block where piece is to be moved */
		move.final_row_val = get_row(move.final_row, &chess_board);
		final_block_val = get_block(move.final_col, move.final_row_val);

		/* Check For Legal Move */
		if(legal_move_check(initial_block_val, final_block_val, &move, &chess_board)){
			if(final_block_val == 0x06){
				printf("Black Wins\n");
				check_mate = true;
			}
			else if(final_block_val == 0x0e){
				printf("White Wins\n");
				check_mate = true;
			}
			if(move_piece(&move, &chess_board)){
				printf("Legal Move\n");
				/* change turn to opponent in case of legal move */
				white_turn = !white_turn;
				/* display the move made on UI */
				change_move(move.initial_row, move.initial_col, move.final_row, move.final_col, initial_block_val, display_board);
			}
			else{
				printf("Illegal Move\n");
			}
		}
		else{
			printf("Illegal Move\n");
		}
	}
	return 0;
}
