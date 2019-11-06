**DSA-Project Chess** 
MIS     : 111803161
Name    : Rohan Pravin Patil

INTRO:
1. A basic implementation of 2-player chess engine
2. White player being the one on Upper side denoted by UppperCase letters, Black would be in lower side as lowerCase letters
3. Use make command from terminal for compiling and ./project <file_name> to run the code 
4. Moves must be entered in format [a-h][1-8][a-h][1-8] which could be interpreted as [initial_row][initial_col][final_row][final_col]
5. Use quit command to quit game
6. Use save command to save game
7. Checking for pseudo legal moves have been completed 

ISSUES:
1. Check Detection and actions taken after it has not been done
2. Game ends when you kill the enemy king
3. En-passen, Castling and Pawn promotion not handled

SAVE & LOAD GAME:
Save a game to file and retrive game from a file implemented
1. If the program is run without any arguments then the player name entered would be the name of file in which the game state would be saved
2. If a file name is passed as argument then the file loads and game continues from previous save point
3. If a given file name does not exist then respective error message is displayed
4. The game doesn't provide any autosave feature so you need to manually save the game
5. All Saved games are stored in a Saved_files directory
6. If you try to save again using same name then, existing file would be over-written

PIECES DENOTION:
P - Pawn
R - Rook
N - Knight
B - Bishop
Q - Queen
K - King

EASE OF ACCESS:
Use ctrl and '-' keys together to shrink the terminal screen for better View if the board is not completely visible
Press ctrl, shift an '+' key together to expand screen back again

Future Tasks :-
1. Get Legal Moves (including legal moves after check)
2. Make attack bitboards or some other way of calculating pins
3. Loop attack possibilities till time taken is not much
4. Test it against custom inputs and correct errors if any
5. Convert characters used as denotion to something more easy to understand (confusion in pawn piece occurs currently as 'p' and 'P' look similar on board)
6. Try to improve time taken by bot for each move
7. If time permits switch code to Glade
