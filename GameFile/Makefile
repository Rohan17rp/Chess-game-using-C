clean: project
	rm *.o
project: main.o boards.o legal_moves.o moves.o pieces.o ui.o board_display.o attack_bit_boards.o
	gcc -g -o project main.o boards.o legal_moves.o moves.o pieces.o ui.o board_display.o attack_bit_boards.o
main.o: src/main.c
	gcc -g -c -Wall src/main.c
boards.o: Boards/boards.c
	gcc -g -c -Wall Boards/boards.c
legal_moves.o: Legal_Moves/legal_moves.c
	gcc -g -c -Wall Legal_Moves/legal_moves.c
moves.o: Moves/moves.c 
	gcc -g -c -Wall Moves/moves.c
pieces.o: Pieces/pieces.c
	gcc -g -c -Wall Pieces/pieces.c
ui.o: UI/ui.c
	gcc -g -c -Wall UI/ui.c
board_display.o: UI/board_display.c
	gcc -g -c -Wall UI/board_display.c
attack_bit_boards.o: Boards/attack_bit_boards.c
	gcc -g -c -Wall Boards/attack_bit_boards.c
