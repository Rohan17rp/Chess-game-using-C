#include "modules.h"

//print_hex_board(&chess_board);//This command works and prints board in form of hex values
int main(int argc, char *argv[]){

	/* Variable Declarations */
	int save_to_file = 0;
	uint32_t initial_column_number, final_column_number;
	uint8_t initial_block_val, final_block_val;
	char initial_row_alphabet, final_row_alphabet, color, name[20];
	bool check_mate, white_color, white_turn;
	FILE *fp;

	/* Almost useless as of now */
	typedef struct king_piece{
		char king_row_alphabet;
		uint32_t king_column_number;
	}KING;

	KING black_king, white_king;

	/* Variable Initialization */
	check_mate = false;
	white_turn = true;

	/* Set Board to default state */
	set_board_default(&chess_board);

	/* If no argument is given then open a new file */
	if(argc == 1){
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

		/* Take name from user and save them to file */
		printf("Enter a name with max 20 characters\n");
		while(1){
			scanf("\n%s",name);
			if(strlen(name) < 20){
				printf("%s\n",name);
				/* Create file with player name */
				fp = open_file(fp, name, "w+");
				fclose(fp);
				printf("File created\n");
				break;
			}
			else
				printf("Enter a valid name\nMax Character Limit is 20\n");
		}
		/*Display Default Board */
		display_board_set_default(display_board);
	}
	/* If argument is given then open the file to continue game */
	else if(argc == 2){
		/* Load Game */

		int count = 0;
		/* Display saved game */
		fp = open_file(fp, argv[1], "rw");

		/* Display saved board */
		display_saved_board(display_board, fp);
		fclose(fp);

		/* Load values from file to respective variables */
		fp = open_file(fp, argv[1], "rw");
		while(count < 8 && fscanf(fp, "%x",&chess_board.row[count++]));	
		int temp;
		fscanf(fp, "%s%d",name, &temp);
		white_turn = temp ? true : false ;
		fclose(fp);

		printf("Game Sucessfully Loaded\n");
	}
	else{
		perror("INVALID NUMBER OF ARGUMENTS");
		return EINVAL;
	}
	/* Play game */
	while(!check_mate){

		/* Printing Whose turn is it */		
		if(white_turn)
			printf("w-> %s's turn\n",name);
		else
			printf("b->");

		/* Take Move input from user */
		scanf("\n%c%d%c%d", &move.initial_row, &move.initial_col, &move.final_row, &move.final_col);

		/* Quit Game */
		if(move.initial_row == 'q'){
			fclose(fp);
			return 0;
		}
		/* Save Game */
		if(move.initial_row == 's'){
			/* Get the name of file to save to */
			char *file_name;
			if(argc == 1)
				file_name = name;
			else if(argc == 2)
				file_name = argv[1];
			else{
				perror("File not found");
				exit(1);
			}

			/* Save current board position in file */
			fp = open_file(fp, file_name, "w+");
			while(save_to_file < 8){
				fprintf(fp, "%08x\n",chess_board.row[save_to_file]);
				save_to_file++;
			}
			save_to_file = 0;
			fprintf(fp, "%s\n%d", name, white_turn);
			fclose(fp);

			printf("Game State Saved\n");
		}

		/* Get Value of initial block to move */
		move.initial_row_val = get_row(move.initial_row, &chess_board);
		initial_block_val = get_block(move.initial_col, move.initial_row_val);

		/* Check whether right player is playin it */
		if(initial_block_val != 0 && !((initial_block_val >> 3) ^ (white_turn))){
			printf("\nYou need to supress urge of moving enemy pieces\n");
			continue;
		}

		/* Get Value of Final block where piece is to be moved */
		move.final_row_val = get_row(move.final_row, &chess_board);
		final_block_val = get_block(move.final_col, move.final_row_val);

		/* Check For Legal Move */
		if(legal_move_check(initial_block_val, final_block_val, &move, &chess_board)){
			if(move_piece(&move, &chess_board)){
				printf("Legal Move\n");
				/* change turn to opponent in case of legal move */
				white_turn = !white_turn;
				/* display the move made on UI */
				change_move(move.initial_row, move.initial_col, move.final_row, move.final_col, initial_block_val, display_board);

				check_mate = check_gameOver(final_block_val);
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

bool check_gameOver(uint8_t final_block_val){
	if(final_block_val == 0x06){
		printf("Black Wins\n");
		return true;
	}
	else if(final_block_val == 0x0e){
		printf("White Wins\n");
		return true;
	}
	return false;
}

FILE* open_file(FILE *fp, char *file_name, char *mode){
	fp = fopen(file_name, mode);
	if(fp == NULL){
		perror("File Not Opened");
		exit(0);
	}
	return fp;
}

