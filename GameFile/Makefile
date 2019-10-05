project: main.o boards.o legal_moves.o moves.o pieces.o
	gcc -g -o project main.o boards.o legal_moves.o moves.o pieces.o
main.o: src/main.c
	gcc -g -c src/main.c
boards.o: Boards/boards.c
	gcc -g -c Boards/boards.c
legal_moves.o: Legal_Moves/legal_moves.c
	gcc -g -c Legal_Moves/legal_moves.c
moves.o: Moves/moves.c
	gcc -g -c Moves/moves.c
pieces.o: Pieces/pieces.c
	gcc -g -c Pieces/pieces.c
