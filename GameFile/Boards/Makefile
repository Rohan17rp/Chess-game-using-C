test: boards.o attack_bit_boards.o
	gcc -o test boards.o attack_bit_boards.o
	rm *.o
attack_bit_boards.o: attack_bit_boards.c
	gcc -c -g attack_bit_boards.c
boards.o: boards.c
	gcc -c -g boards.c
