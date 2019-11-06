test: boards.o attack_bit_boards.o legal_moves.o
	gcc -o test boards.o attack_bit_boards.o legal_moves.o
	rm *.o
attack_bit_boards.o: attack_bit_boards.c
	gcc -c -g attack_bit_boards.c
boards.o: boards.c
	gcc -c -g boards.c
legal_moves.o: ../Legal_Moves/legal_moves.c
	gcc -c -g ../Legal_Moves/legal_moves.c
