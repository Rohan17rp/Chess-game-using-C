**DSA-Project Chess** 
MIS     : 111803161
Name    : Rohan Pravin Patil

INTRO:
1. A basic implementation of 2-player chess engine
2. White player being the one on Upper side denoted by UppperCase letters in yellow color,
	Black would be in lower side as lowerCase letters in cyan color
3. Use make command from terminal for compiling and ./project to run the code 
4. Moves must be entered in format [a-h][1-8][a-h][1-8] which could be interpreted as [initial_row][initial_col][final_row][final_col]
5. Use quit command to quit game
6. Use save command to save game
7. Checking for pseudo legal moves have been completed 
8. Check and check_mate detection has been done

ISSUES:
1. En-passen, Castling and Pawn promotion not handled
2. 1player not yet implemented

SAVE & LOAD GAME:
Save a game to file and retrive game from a file implemented
1. If the program is run in mode 2 or 3 then the player name or 1st player name respectively entered would be the name of file in which the game state would be saved
2. If a given file name does not exist then respective error message is displayed
3. The game doesn't provide any autosave feature so you need to manually save the game
4. All Saved games are stored in a Saved_files directory
5. If you try to save again using same name then, existing file would be over-written

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
1. Loop attack possibilities till time taken is not much
2. Test it against custom inputs and correct errors if any
3. Try to improve time taken by bot for each move
4. If time permits switch code to Glade
