#include "modules.h"

//print_hex_board(&chess_board);//This command works and prints board in form of hex values
void get_user_name(bool color, bool turn, char *name);
int main(int argc, char *argv[]){

	/* Variable Declarations */
	int save_to_file = 0;
	uint32_t initial_column_number, final_column_number;
	uint8_t initial_block_val, final_block_val;
	char initial_row_alphabet, final_row_alphabet, color, name[20], token;
	bool check_mate, white_color, white_turn;
	FILE *fp;
	char white_king_row = 'a', black_king_row = 'h';
	int white_king_col = 4, black_king_col = 4;
	CHESS_PIECE *pieces;

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
				printf("Welcome %s\n",name);
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
		printf("Trying to load file '%s'\n", argv[1]);	
		/* Display saved game */
		fp = open_file(fp, argv[1], "rw");
		if(fp == NULL){
			exit(1);
		}
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
		get_user_name(white_color, white_turn, name);
//		if(white_turn)
//			printf("w-> %s's turn\n",name);
//		else
//			printf("b->");

		/* Take input from user */
		token = getToken(&move);

		/* Quit Game */
		if(token == 'q'){
			printf("Game successfully Exited\n");
			return 0;
		}

		/* Save Game */
		if(token == 's'){
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
		if(token == 'm'){
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
				/* Gets position of pieces by their values */
				pieces = get_position_bitboards(&chess_board, pieces);
//					printf(" pieces->WHITE_PAWN  -> %016lx\n", pieces->WHITE_PAWN);
//					printf(" pieces->WHITE_ROOK  -> %016lx\n", pieces->WHITE_ROOK);
//					printf(" pieces->WHITE_KNIGHT-> %016lx\n", pieces->WHITE_KNIGHT);
//					printf(" pieces->WHITE_BISHOP-> %016lx\n", pieces->WHITE_BISHOP);
//					printf(" pieces->WHITE_QUEEN -> %016lx\n", pieces->WHITE_QUEEN);
//					printf(" pieces->WHITE_KING  -> %016lx\n", pieces->WHITE_KING);
//					printf(" pieces->BLACK_PAWN  -> %016lx\n", pieces->BLACK_PAWN);
//					printf(" pieces->BLACK_ROOK  -> %016lx\n", pieces->BLACK_ROOK);
//					printf(" pieces->BLACK_KNIGHT-> %016lx\n", pieces->BLACK_KNIGHT);
//					printf(" pieces->BLACK_BISHOP-> %016lx\n", pieces->BLACK_BISHOP);
//					printf(" pieces->BLACK_QUEEN -> %016lx\n", pieces->BLACK_QUEEN);
//					printf(" pieces->BLACK_KING  -> %016lx\n", pieces->BLACK_KING);
				BOARD temp;
				temp = chess_board;
				if(initial_block_val == 0x6){
					white_king_row = move.final_row;
					white_king_col = move.final_col;
				}
				else if(initial_block_val == 0xE){
					black_king_row = move.final_row;
					black_king_col = move.final_col;
				}
				if(move_piece(&move, &chess_board)){
					/* check if it is black turn and if king is in check */
					if(!white_turn && king_check(black_king_row, black_king_col, &chess_board)){
						chess_board = temp;
						printf("black king is in check\n");
					}
					/* check if it is white turn and if king is in check */
					else if(white_turn && king_check(white_king_row, white_king_col, &chess_board)){
						chess_board = temp;
						printf("white king is in check\n");
					}
					/* If king is not in check proceed normally */
					else{
						change_move(move.initial_row, move.initial_col, move.final_row, move.final_col, initial_block_val, display_board);
						printf("Legal Move\n");


						/* change turn to opponent in case of legal move */
						white_turn = !white_turn;
						/* display the move made on UI */
						check_mate = check_gameOver(final_block_val);
					}	
				}
				else{
					printf("Illegal Move\n");
				}
			}

			else{
				printf("Illegal Move\n");
			}
		}
	}
	return 0;
}

void get_user_name(bool color, bool white_turn, char *name){
	if(color){
		if(white_turn)
			printf("w-> %s's turn\n",name);
		else
			printf("b->");
	}
	else{
		if(!white_turn)
			printf("b-> %s's turn\n",name);
		else
			printf("w->");
	}
}

/**
* \breief if the king is killed then game_over
*/
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
/**
 * \brief opens file in Saved_files directory or exits if file not opened
 * \params fp file_pointer
 * \params file_name gets name of file
 * \params mode file should be opened in this mode
 */
FILE* open_file(FILE *fp, char *file_name, char *mode){
	char path[] = "Saved_files/";
	char name[20];
	int i = 0;
	strcpy(name, file_name);
	strcat(path, name);	
	fp = fopen(path, mode);
	if(fp == NULL){
		perror("File Not Opened ");
	}
	return fp;
}
/** 
 * \brief takes input string from user for move-making, saving and quit-game
 *
 * \params move initial and final move values
 */
char getToken(MOVE *move){
	char token[10];
	scanf("%s",token);
	if(!strcmp(token, "quit")){
		return 'q';
	}
	if(!strcmp(token, "save")){
		return 's';
	}
	printf("Move\n");
	move->initial_row = token[0];
	move->initial_col = atoi(&token[1]);
	move->final_row = token[2];
	move->final_col = atoi(&token[3]);
	return 'm';
}
