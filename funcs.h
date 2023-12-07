/** funcs.h
 * =============================================================
 * Name: C3C Tomas Cantalupo
 * Section:  M6/7
 * Project:  Connect 4
 * Purpose:  Create Connect 4 in C
 * Documentation Statement:  Asked ChatGPT to explain scanf and do while loops
 * referenced the cs210 canvas, assignment page,
 * zybooks, class lectures and teams page
 * ============================================================= */

#ifndef funcs

#define funcs

/**
* @brief creates a custom size 2D array of chars based on parameters
* @param rows number of rows in board
* @param cols number of cols in board
* @return pointer to the board 2D array
*/
char** createBoard(int rows, int cols);

/**
* @brief Frees allocated memory for 2D board array 
* @param board pointer to the 2D array 
* @param rows number of rows in board
* @param cols number of cols in board
*/
void freeBoard(char** board, int rows, int cols);

/**
* @brief Prints the current state of the 2D array representing the board
* @param board pointer to the 2D array (board) to be printed
* @param rows number of rows in board
* @param cols number of cols in board
*/
void printBoard(char** board, int rows, int cols);

/**
* @brief Drops a chip into the specified column of the board
* @param board pointer to the 2D array (board) where the chip is dropped
* @param rows number of rows in board
* @param player the symbol representing the current player
* @param chipCol the column where the chip is to be dropped
* @return returns 1 if succesfully dropped, return 0 if invalid column
*/
int dropChip(char** board, int rows, char player, int chipCol);

/**
* @brief Checks for a win condition in the board
* @param board pointer to the 2D array (board) to be checked
* @param rows number of rows in board
* @param cols number of cols in board
* @return the symbol of the winning player or ' ' if no winner
*/
char checkWin(char**board, int rows, int cols);

/**
* @brief Plays the game, setup, main gameplay loop, ending, calls other functions
*/
void playGame();

/**
* @brief Gets valid board dimensions from the user
* @param rows pointer to store the number of rows
* @param cols pointer to store the number of columns
*/
void getValidBoardSize(int* rows, int* cols);

/**
* @brief Gets valid player symbols from the user
* @param p1Symbol pointer to store the first player's symbol
* @param p2Symbol pointer to store the second player's symbol
*/
void getValidPlayerSymbols(char* p1Symbol, char* p2Symbol);

/**
* @brief Saves the current state of the board along with game details
* @param board pointer to the 2D array (board) to be saved
* @param rows number of rows in board
* @param cols number of cols in board
* @param winner the symbol of the winning player or ' ' if no winner
* @param turns the number of turns played
*/
void saveBoard(char**board, int rows, int cols, char winner, int turns);

#endif