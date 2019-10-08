#include "ui.h"
void display_board_set_default(char display_board[37][58]){
	int i, j;
	for(i = 0; i < 37; i++){
		for(j = 0; j < 58; j++){
			printf("%c",display_board[i][j]);
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
	for(i = 0; i < 37; i++){
		for(j = 0; j < 58; j++){
			printf("%c",display_board[i][j]);
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
