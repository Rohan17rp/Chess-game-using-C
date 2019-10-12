**DSA-Project Chess** 
MIS     : 111803161
Name    : Rohan Pravin Patil

A basic implementation of 2-player chess engine
White player being the one on Upper side denoted by UppperCase letters, Black would be in lower side as lowerCase letters
Use make command from terminal for compiling and ./project to run the code 
Moves must be entered in format [a-h][1-8][a-h][1-8] which could be interpreted as [initial_row][initial_col][final_row][final_col]
Checking for pseudo legal moves have been completed 
Check Detection and actions taken after it has not been done
Game ends when you kill the enemy king

Pieces are denoted as:-
P - Pawn
R - Rook
N - Knight
B - Bishop
Q - Queen
K - King

Use ctrl and '-' keys together to shrink the terminal screen for better View if the board is not completely visible

The modules of Alogorithm(Alpha-Beta pruning), 1 player Mode yet to be implemented 

Future Tasks :-
1. Get Legal Moves (including legal moves after check)
2. Make attack bitboards or some other way of calculating pins
3. Loop attack possibilities till time taken is not much
4. Save a game to file and retrive game from a file
5. Test it against custom inputs and correct errors if any
6. Convert characters used as denotion to something more easy to understand (confusion in pawn piece occurs currently as 'p' and 'P' look similar on board, also differenciating black and white squares(Easy stuff))
7. Try to improve time taken by bot for each move
8. If time permits switch code to Glade
