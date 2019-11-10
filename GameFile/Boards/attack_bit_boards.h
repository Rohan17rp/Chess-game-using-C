#ifndef ATTACK_BIT_BOARDS
#define ATTACK_BIT_BOARDS
#include "boards.h"
#include "../Legal_Moves/legal_moves.h"
#include<inttypes.h>
#endif
typedef struct pieces{
        uint64_t WHITE_PAWN;
        uint64_t WHITE_KNIGHT;
        uint64_t WHITE_BISHOP;
        uint64_t WHITE_ROOK;
        uint64_t WHITE_QUEEN;
        uint64_t WHITE_KING;

        uint64_t BLACK_PAWN;
        uint64_t BLACK_KNIGHT;
        uint64_t BLACK_BISHOP;
        uint64_t BLACK_ROOK;
        uint64_t BLACK_QUEEN;
        uint64_t BLACK_KING;

        uint64_t BLANK_SPACE;
}CHESS_PIECE;
CHESS_PIECE PIECES, MOVE_BIT_BOARD;

void move_bit_board_init(CHESS_PIECE  *move_bit_board);
void bitboard_init(CHESS_PIECE *piece);
CHESS_PIECE *get_position_bitboards(BOARD *chess_board, CHESS_PIECE *piece);
CHESS_PIECE *move_bitboard(MOVE move, BOARD chess_board, CHESS_PIECE *move_bit_board, char king_row, int king_col);
