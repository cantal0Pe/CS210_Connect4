/** test.h
 * =============================================================
 * Name: C3C Tomas Cantalupo
 * Section:  M6/7
 * Project:  Connect 4
 * Purpose:  Create Connect 4 in C
 * Documentation Statement:  Asked ChatGPT to explain scanf and do while loops
 * referenced the cs210 canvas, assignment page,
 * zybooks, class lectures and teams page
 * ============================================================= */

#ifndef test

#define test

/**
* @brief Runs all test functions for the game
*/
void runAllTests();

/**
* @brief Tests the checkWin function to ensure it works for horizontal, vertical and diagonal wins in all possible locations
*/
void checkWinTest();

/**
* @brief Tests the game logic for handling the maximum number of turns
*/
void maxTurnsTest();

#endif