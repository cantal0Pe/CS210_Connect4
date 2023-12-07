/** test.c
 * =============================================================
 * Name: C3C Tomas Cantalupo
 * Section:  M6/7
 * Project:  Connect 4
 * Purpose:  Create Connect 4 in C
 * Documentation Statement:  Asked ChatGPT to explain scanf and do while loops
 * referenced the cs210 canvas, assignment page,
 * zybooks, class lectures and teams page
 * ============================================================= */

#include <stdio.h>
#include <assert.h>

#include "test.h"
#include "funcs.h"


void runAllTests(){

    maxTurnsTest();

    checkWinTest();
}

void checkWinTest(){

    int rows = 6;
    int cols = 7;

    char p1Symbol = 'x';

    //these loops create 4 in a row pieces in all possible configurations for the board,
    //assert statements are used to make sure checkwin detects them all

    //vert wins

    for(int r = 0; r<rows-3; r++){
        for(int c = 0; c<cols; c++){

            char** board = createBoard(rows,cols);

            for(int i = 0; i<4;i++){
                board[r+i][c]=p1Symbol;
            }

            printBoard(board,rows,cols);

            assert(checkWin(board,rows,cols==1));

            freeBoard(board,rows,cols);

        }
            
    }

    //horizontal wins

    for(int c = 0; c<cols-3; c++){
        for(int r = 0; r<rows; r++){

            char** board = createBoard(rows,cols);

            for(int i = 0; i<4;i++){
                board[r][c+i]=p1Symbol;
            }

            printBoard(board,rows,cols);

            assert(checkWin(board,rows,cols==1));

            freeBoard(board,rows,cols);

        }
            
    }

    //diagonal wins

    for(int c = 0; c<cols-3; c++){
        for(int r = 0; r<rows-3; r++){

            char** board = createBoard(rows,cols);

            for(int i = 0; i<4;i++){
                board[r+i][c+i]=p1Symbol;
            }

            printBoard(board,rows,cols);

            assert(checkWin(board,rows,cols==1));

            freeBoard(board,rows,cols);

        }
            
    }

    for(int c = 3; c<cols; c++){
        for(int r = 0; r<rows-3; r++){

            char** board = createBoard(rows,cols);

            for(int i = 0; i<4;i++){
                board[r+i][c-i]=p1Symbol;
            }

            printBoard(board,rows,cols);

            assert(checkWin(board,rows,cols==1));

            freeBoard(board,rows,cols);

        }
            
    }

    
    printf("checkwin test passed\n");
    



}

void maxTurnsTest(){
    int rows = 6;
    int cols = 7;

    char p1Symbol = 'x';

    int turnCounter = 0;
    int maxTurns = rows*cols;

    char** board = createBoard(rows,cols);

    int c = 0;


    while(turnCounter<maxTurns){

        printf("This is turn %d\n, max turns = %d\n",turnCounter,maxTurns);

        //this loop will keep trying to fill up the array endlessly but if turnCounter is working it will exit after the entire board is filled up

        for(int r = 0; r<rows;r++){
            dropChip(board,rows,p1Symbol,c);
            turnCounter++;
        }

        printBoard(board,rows,cols);

        c++;
        
    }

    printf("test passed\n");
}