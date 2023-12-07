#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

/** funcs.c
 * =============================================================
 * Name: C3C Tomas Cantalupo
 * Section:  M6/7
 * Project:  Connect 4
 * Purpose:  Create Connect 4 in C
 * Documentation Statement:  Asked ChatGPT to explain scanf and do while loops
 * referenced the cs210 canvas, assignment page,
 * zybooks, class lectures and teams page
 * ============================================================= */

void playGame(){
    int rows = 6;
    int cols = 7;

    char p1Symbol = 'x';
    char p2Symbol = 'v';

    int turnCounter = 0;
    int maxTurns = rows*cols;

    int playerMove = 1;

    char winner = ' ';

    int nextPlayerCol = 0;

    printf("Welcome to Connect 4!\n\n");

    getValidBoardSize(&rows,&cols);

    char** board = createBoard(rows,cols);

    getValidPlayerSymbols(&p1Symbol,&p2Symbol);

    while(winner==' ' && turnCounter<maxTurns){

        int dropSuccess = 0;

        

        if(playerMove==1){
            do {
                printBoard(board,rows,cols);
                printf("Player 1, enter the column you want to drop your chip: ");
                scanf("%d", &nextPlayerCol);
                printf("\n");
                dropSuccess = dropChip(board,rows,p1Symbol,nextPlayerCol);
            } while (dropSuccess == 0);

        } else if(playerMove==2){
            do {
                printBoard(board,rows,cols);
                printf("Player 2, enter the column you want to drop your chip: ");
                scanf("%d", &nextPlayerCol);
                printf("\n");
                dropSuccess = dropChip(board,rows,p2Symbol,nextPlayerCol);
            } while (dropSuccess == 0);
        }

        if(playerMove==2){
            playerMove=1;
        } else {
            playerMove = 2;
        }

        //printBoard(board,rows,cols);

        winner=checkWin(board,rows,cols);

        //printf("This is turn %d, max turns = %d\n",turnCounter,maxTurns);

        turnCounter++;

        printf("\n");
    }

    printBoard(board,rows,cols);

    if(winner==' '){
        printf("It was a tie");
    } else {
        printf("Player %c wins!\n",winner);

    }
    
    printf("A total of %d chips were used\n",turnCounter);

    saveBoard(board,rows,cols,winner,turnCounter);

    printf("Game result has been saved to results.txt!\n");

    freeBoard(board,rows,cols);

}

char checkWin(char**board, int rows, int cols){

    //horizontal win

    int counter = 0;

    for(int r = 0; r<rows; r++){

        for(int c = 0; c<cols-3; c++){

            counter = 0;

            if(board[r][c]!=' '){

                for(int j = 0; j<4; j++){
                
                if(board[r][c]==board[r][c+j]){
                    counter++;
                    }
                }
                if(counter == 4){
                    return board[r][c];
                }

            }
        }

    }

    //vertical win

    for(int c = 0; c<cols; c++){

        for(int r = 0; r<rows-3; r++){

            counter = 0;

            if(board[r][c]!=' '){

                for(int j = 0; j<4; j++){
                
                if(board[r][c]==board[r+j][c]){
                    counter++;
                    }
                }
                if(counter == 4){
                    return board[r][c];
                }

            }
        }

    }

    //diagonal win top left bottom right

    for(int c = 0; c<cols-3; c++){

        for(int r = 0; r<rows-3; r++){

            counter = 0;

            if(board[r][c]!=' '){

                for(int j = 0; j<4; j++){
                
                if(board[r][c]==board[r+j][c+j]){
                    counter++;
                    }
                }
                if(counter == 4){
                    return board[r][c];
                }

            }
        }

    }

    //diagonal win bottom left top right

    for(int c = 3; c<cols; c++){

        for(int r = 0; r<rows-3; r++){

            counter = 0;

            if(board[r][c]!=' '){

                for(int j = 0; j<4; j++){
                
                if(board[r][c]==board[r+j][c-j]){
                    counter++;
                    }
                }
                if(counter == 4){
                    return board[r][c];
                }

            }
        }

    }


    return ' ';
}

void getValidBoardSize(int* rows, int* cols){



    printf("Choose your board size!\n");

    printf("Enter a board size like this: ROWSxCOLS, e.g. 10x10, 6x7, etc.\n");

    printf("WARNING: Extreme board sizes (ROWS>55, COLS>100) may cause issues!\n");

    do{

        printf("Board size must be 4x4 or larger!\n");

        scanf("%dx%d",rows,cols);

    } while (*rows<4 && *cols<4);


    printf("\n");

}

void getValidPlayerSymbols(char* p1Symbol, char* p2Symbol){

    do{
        printf("Player 1, choose your chip symbol! (Any single character except ' ')\n");
        scanf(" %c",p1Symbol);

    } while (*p1Symbol==' ');

    do{
        printf("Player 2, choose your chip symbol! (Any single character except ' ' or %c))\n",*p1Symbol);
        scanf(" %c",p2Symbol);

    } while (*p2Symbol==' ' || *p2Symbol== *p1Symbol);

    printf("\n");

}



int dropChip(char** board, int rows, char pSymbol, int chipCol){

    //returns 1 if succesfully dropped, return 0 if invalid column

    if(board[0][chipCol]!=' '){
        printf("Invalid column (full)\n");
        return 0;
    } else {

        int rowIndex = rows-1;

        while(board[rowIndex][chipCol]!=' '){
            rowIndex--;
        }

        board[rowIndex][chipCol]=pSymbol;
    }

    return 1;

    //find lowest open grid

}

char** createBoard(int rows, int cols){

    //dynamically allocate rows

    char** board = (char**)malloc(sizeof(char*)*rows);

    //dynamically allocate each row with correct number of cols

    for(int i = 0; i<rows; i++){
        board[i] = (char*)malloc(sizeof(char)*cols);
    }

    //populate each grid square with 0 (empty) to start game

    for(int r = 0; r<rows; r++){
        for(int c = 0; c<cols; c++){
            board[r][c]=' ';
        }
    }

    return board;



}

void freeBoard(char** board, int rows, int cols){

    for(int i = 0; i<rows; i++){
        free(board[i]);
    }

    free(board);

}

void printBoard(char** board, int rows, int cols){


    for(int r = 0; r<rows; r++){
        for(int c = 0; c<cols; c++){
            printf("| %c ",board[r][c]);
        }

        printf("| %d\n",r);
    }

    printf("-");
    for(int c = 0; c<cols;c++){
        printf("----");
    }
    printf("\n");

    printf(" ");

    for(int c = 0; c<cols;c++){
        printf("%03d ",c);
    }

    printf("\n");

}

void saveBoard(char**board, int rows, int cols, char winner, int turns){

    FILE* file = fopen("results.txt","w");

    for(int r = 0; r<rows; r++){
        for(int c = 0; c<cols; c++){
            fprintf(file,"| %c ",board[r][c]);
        }

        fprintf(file,"| %d\n",r);
    }

    fprintf(file,"-");
    for(int c = 0; c<cols;c++){
        fprintf(file,"----");
    }
    fprintf(file,"\n");

    fprintf(file," ");

    for(int c = 0; c<cols;c++){
        fprintf(file,"%03d ",c);
    }

    fprintf(file,"\n");

    if(winner==' '){
        fprintf(file,"It was a tie");
    } else {
        fprintf(file,"Player %c wins!\n",winner);

    }
    
    fprintf(file,"A total of %d chips were used\n",turns);

    fclose(file);
}







