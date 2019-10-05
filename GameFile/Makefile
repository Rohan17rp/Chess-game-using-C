project: main.o boards.o legal_moves.o moves.o pieces.o
	gcc -o project main.o boards.o legal_moves.o moves.o pieces.o
main.o: src/main.c
	gcc -c src/main.c
boards.o: Boards/boards.c
	gcc -c Boards/boards.c
legal_moves.o: Legal_Moves/legal_moves.c
	gcc -c Legal_Moves/legal_moves.c
moves.o: Moves/moves.c
	gcc -c Moves/moves.c
pieces.o: Pieces/pieces.c
	gcc -c Pieces/pieces.c
