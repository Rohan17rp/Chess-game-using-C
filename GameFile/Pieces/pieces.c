//#include "pieces.h"
#include <stdint.h>
#include <stdio.h>

#define EMPTY	0x0
#define PAWN	0x1
#define KNIGHT	0x2
#define BISHOP	0x3
#define ROOK	0x4
#define QUEEN 	0x5
#define KING	0x6

#ifndef BLOCK
#define BLOCK	0x0
#endif

void identify_piece(){
	switch(BLOCK){
		case 0x0:
			printf("The Block is Empty");
			break;
		case 0x1:
			printf("The Block is Pawn");
			break;
		case 0x2:
			printf("The Block is Knight");
			break;
		case 0x3:
			printf("The Block is Bishop");
			break;
		case 0x4:
			printf("The Block is Rook");
			break;
		case 0x5:
			printf("The Block is Queen");
			break;
		case 0x6:
			printf("The Block is King");
			break;
		default:
			printf("Piece error");
			break;
	}
}
