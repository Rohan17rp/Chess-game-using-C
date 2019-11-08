#include "modules.h"

bool check_check_mate(CHESS_PIECE *move_bit_board, CHESS_PIECE *pieces, MOVE move, BOARD chess_board, char king_row, int king_col, bool white_turn);
MOVE return_legal_move(CHESS_PIECE *move_bit_board, CHESS_PIECE *pieces, MOVE move, BOARD chess_board, char king_row, int king_col, bool white_turn);
//print_hex_board(&chess_board);//This command works and prints board in form of hex values
int main(int argc, char *argv[]){

	/* Variable Declarations */
	int save_to_file = 0;
	uint32_t initial_column_number, final_column_number;
	uint8_t initial_block_val, final_block_val;
	char initial_row_alphabet, final_row_alphabet, color, name[20], name2[20], token, del_name[25];
	bool check_mate, white_color, white_turn, valid_mode;
	FILE *fp;
	char white_king_row = 'a', black_king_row = 'h';
	int white_king_col = 4, black_king_col = 4, mode;
	CHESS_PIECE *pieces, *move_bit_board;
	char ch;
	struct dirent *de;  // Pointer for directory entry
	DIR *dr;	// opendir() returns a pointer of DIR type.
	BOARD temp;

	/* Variable Initialization */
	check_mate = false;
	white_turn = true;
	valid_mode = false;

	/* Set Board to default state */
	set_board_default(&chess_board);
	system("clear");

	while(!valid_mode){
		printf("1. To open save game\n");
		printf("2. To start a new two player game\n");
		printf("3. To start a new one player game\n");
		printf("4. Help\n");
		printf("5. View Saved Files\n");
		printf("6. Delete Saved file\n");
		printf("7. Exit\n");
		scanf("\n%d", &mode);
		valid_mode = true;
		if(mode == 1){
			printf("Enter File name\n");
			scanf("%s", name);
			/* Load Game */
			int count = 0;
			printf("Trying to load file '%s'\n", name);	
			/* Display saved game */
			fp = open_file(fp, name, "rw");
			if(fp == NULL){
				exit(1);
			}
			/* Display saved board */
			display_saved_board(display_board, fp);
			fclose(fp);
			/* Load values from file to respective variables */
			fp = open_file(fp, name, "rw");
			while(count < 8 && fscanf(fp, "%x",&chess_board.row[count++]));	
			int temp;
			fscanf(fp, "%s%d",name, &temp);
			white_turn = temp ? true : false ;
			fclose(fp);
			strcpy(name2, "BOT");
			printf("Game Sucessfully Loaded\n");
		}
		else if(mode == 2){
			/* proceed normally */
			printf("Welcome to the realm of chess \n");
			printf("Enter a name with max 20 characters\n");
			while(1){
				scanf("\n%s", name);
				printf("player 2 name\n");
				scanf("\n%s", name2);
				if(strlen(name) < 20){
					printf("Welcome %s\n", name);
					break;
				}
				else
					printf("Enter a valid name\nMax Character Limit is 20\n");
			}
			system("clear");
			/*Display Default Board */
			display_board_set_default(display_board);

		}
		else if(mode == 3){
			/* Choose Player color
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
			printf("Enter a name with max 20 characters\n");
			while(1){
				scanf("\n%s", name);
				if(strlen(name) < 20){
					printf("Welcome %s\n", name);
					break;
				}
				else
					printf("Enter a valid name\nMax Character Limit is 20\n");
			}
			system("clear");
			/*Display Default Board */
			display_board_set_default(display_board);

			//			printf("Not yet implemented\n");


			//			printf("\nPress 'ENTER' to exit to menu\n");
			//			if(getchar() && getchar()){
			//				valid_mode = false;
			//			}
		}
		else if(mode == 4){
			/* Using cat code */
			fp = fopen("../README.md", "r");

			if(fp == NULL) {
				perror("open failed");
				return errno;
			}

			while(ch != EOF){
				ch = fgetc(fp);
				putchar(ch);
			}
			fclose(fp);
			printf("\npress 'ENTER' to exit to menu\n");
			if(getchar() && getchar()){
				valid_mode = false;
			}
			system("clear");
		}
		else if(mode == 5){
			/* View saved files */
			/* File path */
			dr = opendir("./Saved_files/");

			if (dr == NULL)  // opendir returns NULL if couldn't open directory
			{
				printf("Could not open current directory\n" );
				exit(1);
			}
			printf("\n\nSaved files are\n");
			// for readdir()
			green();
			while ((de = readdir(dr)) != NULL){
				if(!(!strcmp(de->d_name, "..") || !strcmp(de->d_name,  "."))){
					printf("%s\n", de->d_name);
				}
			}
			reset();
			closedir(dr);

			printf("\npress 'ENTER' to exit to menu\n");
			if(getchar() && getchar()){
				valid_mode = false;
			}
			system("clear");
		}
		else if(mode == 6){
			/* Delete a file */
			char path[] = "Saved_files/";
			scanf("%s", del_name);
			strcat(path, del_name);
			if (remove(path) == 0) {
				red();
				printf("Deleted successfully\n%s\n", del_name); 
				reset();
			}
			else{
				printf("Unable to delete the file\n"); 
			}
			printf("\npress 'ENTER' to exit to menu\n");
			if(getchar() && getchar()){
				valid_mode = false;
			}
			system("clear");
		}
		else if(mode == 7){
			exit(1);
		}
		else{
			red();
			printf("\nINVALID mode\n");
			valid_mode = false;
			reset();
		}
	}

	if(argc != 1){
		perror("INVALID NUMBER OF ARGUMENTS");
		return EINVAL;
	}
	/* Play game in 2 player mode*/
	while(!check_mate){
		get_user_name(white_color, white_turn, name, name2, mode);
		if(mode == 1 || mode == 2 || white_turn){
			/* Take input from user */
			token = getToken(&move);
		}
		else{
			move = return_legal_move(move_bit_board, pieces, move, chess_board, black_king_row, black_king_col, white_turn);
			if(move.initial_col == -1){
				printf("Sorry can't process\n");
				break;
			}
			token = 'm';
		}
		/* Quit Game */
		if(token == 'q'){
			printf("Game successfully Exited\n");
			return 0;
		}

		/* Save Game */
		if(token == 's'){
			/* Get the name of file to save to */
			char *file_name;
			if(mode == 1 || mode == 2)
				file_name = name;
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


			pieces = (CHESS_PIECE *)malloc(sizeof(MOVE_BIT_BOARD));

			move_bit_board = (CHESS_PIECE *)malloc(sizeof(MOVE_BIT_BOARD));
			/* Check For Legal Move */
			if(legal_move_check(initial_block_val, final_block_val, &move, &chess_board)){
				/* Gets position of pieces by their values */
				pieces = get_position_bitboards(&chess_board, pieces);
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
					if(!white_turn){
						move_bit_board = move_bitboard(move, chess_board, move_bit_board, white_king_row, white_king_col);
					}
					else {
						move_bit_board = move_bitboard(move, chess_board, move_bit_board, black_king_row, black_king_col);
					}
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
						/* display the move made on UI */
						change_move(move.initial_row, move.initial_col, move.final_row, move.final_col, initial_block_val, display_board);
						if(white_turn){
							if(check_check_mate(move_bit_board, pieces, move, chess_board, black_king_row, black_king_col, white_turn)){
								return 0;
							}
						}
						else{
							if(check_check_mate(move_bit_board, pieces, move, chess_board, white_king_row, white_king_col, white_turn)){
								return 0;
							}
						}
						printf("Legal Move\n");

						/* change turn to opponent in case of legal move */
						white_turn = !white_turn;

						/* To coverup for checkmate in case of game bugs */
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
/**
 * \brief prints whose turn is it
 */
void get_user_name(bool color, bool white_turn, char *name, char *name2, int mode){
	if(mode == 3){
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
	else if(mode == 2){
		if(color){
			if(white_turn)
				printf("w-> %s's turn\n", name);
			else
				printf("b-> %s's turn\n", name2);
		}
		else{
			if(!white_turn)
				printf("b-> %s's turn\n", name);
			else
				printf("w-> %s's turn\n", name2);
		}
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
bool check_check_mate(CHESS_PIECE *move_bit_board, CHESS_PIECE *pieces, MOVE move, BOARD chess_board, char king_row, int king_col, bool white_turn){
	uint64_t black_moves, white_moves;
	BOARD temp, temp2;
	uint8_t block_val_final, block_val_initial;
	bool failed = true;

	bitboard_init(pieces);
	pieces = get_position_bitboards(&chess_board, pieces);
	move_bit_board_init(move_bit_board);
	move_bit_board = move_bitboard(move, chess_board, move_bit_board, king_row, king_col);
	white_moves = move_bit_board->WHITE_PAWN | move_bit_board->WHITE_ROOK | move_bit_board->WHITE_KNIGHT | move_bit_board->WHITE_BISHOP | move_bit_board->WHITE_QUEEN | move_bit_board->WHITE_KING;
	black_moves = move_bit_board->BLACK_PAWN | move_bit_board->BLACK_ROOK | move_bit_board->BLACK_KNIGHT | move_bit_board->BLACK_BISHOP | move_bit_board->BLACK_QUEEN | move_bit_board->BLACK_KING;
	if((!(white_moves & pieces->BLACK_KING) && white_turn) || (!(black_moves & pieces->WHITE_KING) && !white_turn)){
		return FAILED;
	}
	else if((((move_bit_board->BLACK_KING ^ white_moves) & pieces->BLACK_KING) && white_turn) || (move_bit_board->WHITE_KING ^ black_moves) & pieces->WHITE_KING ){
		move.final_row = 'a';
		move.final_col = 1;
		move.initial_row = king_row;
		move.initial_col = king_col;
		temp2 = chess_board;
		move.initial_row_val = get_row(move.initial_row, &chess_board);
		block_val_initial = get_block(move.initial_col, move.initial_row_val);
		while(move.final_row < 'i'){
			while(move.final_col < 9){
				move.final_row_val = get_row(move.final_row, &chess_board);
				block_val_final = get_block(move.final_col, move.final_row_val);
				if(((block_val_initial >> 3) && white_turn) || (!(block_val_initial >> 3) && !white_turn)){
					temp = chess_board;
					if(legal_move_check(block_val_initial, block_val_final, &move, &chess_board)){
						if(move_piece(&move, &chess_board)){
							if(!king_check(move.final_row, move.final_col, &chess_board)){
								chess_board = temp2;
								printf("\nPossible move\n%c\t%d\n%c\t%d\n",move.initial_row, move.initial_col, move.final_row, move.final_col);
								return FAILED;
							}


						}
					}
					temp = chess_board;
				}
				chess_board = temp2;
				move.final_col++;
			}
			move.final_col = 1;
			move.final_row++;
		}
		failed = false;
	}
	if(!failed){
		move.final_row = 'a';
		move.final_col = 1;
		move.initial_row = 'a';
		move.initial_col = 1;
		while(move.final_row < 'i'){
			while(move.final_col < 9){
				while(move.initial_row < 'i'){
					while(move.initial_col < 9){
						move.final_row_val = get_row(move.final_row, &chess_board);
						block_val_final = get_block(move.final_col, move.final_row_val);
						move.initial_row_val = get_row(move.initial_row, &chess_board);
						block_val_initial = get_block(move.initial_col, move.initial_row_val);
						temp = chess_board;
						if(((block_val_initial >> 3) && white_turn) || (!(block_val_initial >> 3) && !white_turn)){
							if(legal_move_check(block_val_initial, block_val_final, &move, &chess_board) ){
								if(move_piece(&move, &chess_board)){
									if(!king_check(king_row, king_col, &chess_board)){
										printf("5");
										chess_board = temp;
										printf("\nPossible move\n%c\t%d\n%c\t%d\n",move.initial_row, move.initial_col, move.final_row, move.final_col);
										return FAILED;

									}
								}
							}
						}
						chess_board = temp;
						move.initial_col++;
					}
					move.initial_col = 1;
					move.initial_row++;
				}
				move.initial_col = 1;
				move.initial_row = 'a';
				move.final_col++;
			}
			move.initial_col = 1;
			move.initial_row = 'a';
			move.final_col = 1;
			move.final_row++;
		}
	}
	return SUCCESS;
}

/** 
 * \brief returns a legal move which is best form the given level
 */
MOVE return_legal_move(CHESS_PIECE *move_bit_board, CHESS_PIECE *pieces, MOVE move, BOARD chess_board, char king_row, int king_col, bool white_turn){
	uint8_t block_val_final, block_val_initial, temp_block_val_final;	
	BOARD temp, temp2;
	MOVE temp_move;
	bool first = true;

	move.final_row = 'a';
	move.final_col = 1;
	move.initial_row = 'a';
	move.initial_col = 1;

	move.final_row_val = get_row(move.final_row, &chess_board);
	block_val_final = get_block(move.final_col, move.final_row_val);
	move.initial_row_val = get_row(move.initial_row, &chess_board);
	block_val_initial = get_block(move.initial_col, move.initial_row_val);

	temp_move.initial_col = -1;
	temp_block_val_final = 0;

	while(move.final_row < 'i'){
		while(move.final_col < 9){
			while(move.initial_row < 'i'){
				while(move.initial_col < 9){
					move.final_row_val = get_row(move.final_row, &chess_board);
					block_val_final = get_block(move.final_col, move.final_row_val);
					move.initial_row_val = get_row(move.initial_row, &chess_board);
					block_val_initial = get_block(move.initial_col, move.initial_row_val);
					temp = chess_board;
					if((block_val_initial >> 3)){
						if(legal_move_check(block_val_initial, block_val_final, &move, &chess_board) ){
							if(move_piece(&move, &chess_board)){
								if(!king_check(king_row, king_col, &chess_board)){
									if(first){
										temp_move = move;
										first = false;
									}
									chess_board = temp;
									if(block_val_final > temp_block_val_final){
										printf("5");
										printf("\nPossible move\n%c\t%d\n%c\t%d\n",move.initial_row, move.initial_col, move.final_row, move.final_col);
										temp_block_val_final = block_val_final;
										temp_move = move;
									}
								}
							}
						}
					}
					chess_board = temp;
					move.initial_col++;
				}
				move.initial_col = 1;
				move.initial_row++;
			}
			move.initial_col = 1;
			move.initial_row = 'a';
			move.final_col++;
		}
		move.initial_col = 1;
		move.initial_row = 'a';
		move.final_col = 1;
		move.final_row++;
	}
	if(first){
		move.final_row = 'a';
		move.final_col = 1;
		move.initial_row = king_row;
		move.initial_col = king_col;
		temp2 = chess_board;
		move.initial_row_val = get_row(move.initial_row, &chess_board);
		block_val_initial = get_block(move.initial_col, move.initial_row_val);
		while(move.final_row < 'i'){
			while(move.final_col < 9){
				move.final_row_val = get_row(move.final_row, &chess_board);
				block_val_final = get_block(move.final_col, move.final_row_val);
				if(((block_val_initial >> 3))){
					temp = chess_board;
					if(legal_move_check(block_val_initial, block_val_final, &move, &chess_board)){
						if(move_piece(&move, &chess_board)){
							if(!king_check(move.final_row, move.final_col, &chess_board)){
								if(first){
									temp_move = move;
									first = false;
								}
								if(block_val_final > temp_block_val_final){
									printf("6");
									chess_board = temp2;
									printf("\nPossible move\n%c\t%d\n%c\t%d\n",move.initial_row, move.initial_col, move.final_row, move.final_col);
									temp_block_val_final = block_val_final;
									temp_move = move;
								}
							}
						}
					}
					temp = chess_board;
				}
				chess_board = temp2;
				move.final_col++;
			}
			move.final_col = 1;
			move.final_row++;
		}
	}
	printf("\nPossible move\n%c\t%d\n%c\t%d\n",temp_move.initial_row, temp_move.initial_col, temp_move.final_row, temp_move.final_col);

	return temp_move;
}
/*
   MOVE return_legal_move_next_level(CHESS_PIECE *move_bit_board, CHESS_PIECE *pieces, MOVE move, BOARD chess_board, char king_row, int king_col, bool white_turn){

   }
 */
