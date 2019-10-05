project: main.o boards.o legal_moves.o moves.o pieces.o
	gcc -c -o main.o boards.o legal_moves.o moves.o pieces.o
main.o: src/main.c
	gcc -c main.c
boards.o: Boards/boards.c
	gcc -c boards.c
legal_moves.o: Legal_Moves/legal_moves.c
	gcc -c legal_move.c
pieces.o: Pieces/pieces.c
	gcc -c pieces.c
