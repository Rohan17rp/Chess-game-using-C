#include "ui.h"
#include "../Pieces/pieces.h"
void red(){
	printf("\033[0;31m");
}
void cyan(){
	printf("\033[1;36m");
}
void yellow(){
	printf("\033[1;33m");
}
void green(){
	printf("\033[1;32m");
}
void reset(){
	printf("\033[0m");
}
void display_board_set_default(char display_board[37][58]){
	int i, j;
	for(i = 0; i < 37; i++){
		for(j = 0; j < 58; j++){
			color(display_board[i][j], i, j);
		}
		printf("\n");
	}
}
void display_saved_board(char display_board[37][58], FILE *fp){
	int i = 0, j;
	char piece_notation;
	uint32_t digit[8];
	uint8_t val;
	while(i < 8){
		fscanf(fp, "%x", &digit[i]);
		i++;
	}
	for (i = 0; i < 8; i++){
		for(j = 0; j < 8; j++){
			val = get_block(j + 1, digit[i]);
			switch(val){
				case 1: 
					piece_notation = 'P';
					break;
				case 9: 
					piece_notation = 'p';
					break;
				case 2: 
					piece_notation = 'N';
					break;
				case 10: 
					piece_notation = 'n';
					break;
				case 3: 
					piece_notation = 'B';
					break;
				case 11: 
					piece_notation = 'b';
					break;
				case 4: 
					piece_notation = 'R';
					break;
				case 12: 
					piece_notation = 'r';
					break;
				case 5: 
					piece_notation = 'Q';
					break;
				case 13: 
					piece_notation = 'q';
					break;
				case 6: 
					piece_notation = 'K';
					break;
				case 14: 
					piece_notation = 'k';
					break;
				default: 
					piece_notation = ' ';
					break;
			}
			display_board[5 + (i * 4)][9 + (j * 6)] = piece_notation;
		}
	}
	system("clear");
	for(i = 0; i < 37; i++){
		for(j = 0; j < 58; j++){
			color(display_board[i][j], i, j);
		}
			printf("\n");
	}
}
void change_move(char initial_row, uint32_t initial_col, char final_row, uint32_t final_col, uint8_t block_val, char display_board[37][58]){
	int row_num_initial, row_num_final, i, j;
	row_num_initial = initial_row - 'a';
	row_num_final = final_row - 'a';
	char piece_notation;
	switch(block_val){
		case 1: 
			piece_notation = 'P';
			break;
		case 9: 
			piece_notation = 'p';
			break;
		case 2: 
			piece_notation = 'N';
			break;
		case 10: 
			piece_notation = 'n';
			break;
		case 3: 
			piece_notation = 'B';
			break;
		case 11: 
			piece_notation = 'b';
			break;
		case 4: 
			piece_notation = 'R';
			break;
		case 12: 
			piece_notation = 'r';
			break;
		case 5: 
			piece_notation = 'Q';
			break;
		case 13: 
			piece_notation = 'q';
			break;
		case 6: 
			piece_notation = 'K';
			break;
		case 14: 
			piece_notation = 'k';
			break;
		default: 
			piece_notation = ' ';
			break;
	}
	display_board[5 + (row_num_initial * 4)][3 + (initial_col * 6)] = ' ';
	display_board[5 + (row_num_final * 4)][3 + (final_col * 6)] = piece_notation;
	system("clear");
	for(i = 0; i < 37; i++){
		for(j = 0; j < 58; j++){
			color(display_board[i][j], i, j);
		}
			printf("\n");
	}
}
void print_board(char board){
	int i, j;
	for(i = 0; i < 37; i++){
		for(j = 0; j < 58; j++){
			printf("%c",(board + (58 * i) + j));
		}
		printf("\n");
	}
}

void color(char display, int i, int j){ 
	if(isalpha(display)){
		if(islower(display) && j > 3){
			cyan();		
		}
		else if(j > 3){
			yellow();
		}
	}
	else if(!isdigit(display)){
		red();
	}
	printf("%c",display);
	reset();
}
