#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "connectn.h"


void print_board(char *board, int num_rows, int num_columns){
    int i,j;
    for(i=0; i<num_rows; i++){
        printf("%d ", num_rows-i-1);
        for(j=0; j<num_columns-1; j++)
            printf("%c ", board[i * num_columns + j]);
        printf("%c\n", board[i * num_columns + j]);
    }
    // last line
    printf("  ");
    for(i=0; i<num_columns-1; i++)
        printf("%d ",i);
    printf("%d\n",i);
}

int play_game(char tile, char *board, int num_rows, int num_columns, int col_to_play){
    int i=num_rows-1;
    if(col_to_play<0 || col_to_play>=num_columns)
        return 0;
    while(board[i*num_columns+col_to_play]!='*'){
        i--;
        if(i<0)
            return 0;
    }
    board[i*num_columns+col_to_play]=tile;
    print_board(board, num_rows, num_columns);
    return 1;
}

char * create_board(int num_rows, int num_columns){
    char *board = (char *)malloc(sizeof(char) * num_columns * num_rows);
    for(int i=0; i<num_rows; i++)
        for(int j=0; j<num_columns; j++)
            board[i * num_columns + j]='*';
    return board;
}


int tie_game(char *board, int num_rows, int num_columns){
    for(int i=0; i<num_columns*num_rows; i++)
        if(board[i]=='*')
            return 0;
    return 1;
}
int row_win(char tile, char *board, int num_rows, int num_columns, int number_of_win){
    int counter=0;
    int i,j;
    for(i=0; i<num_rows; i++){
        for(j=0; j<num_columns; j++){
            if(board[j+i*num_columns]==tile)
                counter++;
            if(board[j+i*num_columns]!=tile)
                counter=0;
            if(counter==number_of_win)
                return 1;
        }
        counter=0;
    }
    return 0;
}

int col_win(char tile, char *board, int num_rows, int num_columns, int number_of_win){
    int counter=0;
    int i,j;
    for(i=0; i<num_columns; i++){
        for(j=0; j<num_rows; j++){
            if(board[num_columns*j+i]==tile)
                counter++;
            if(board[num_columns*j+i]!=tile)
                counter=0;
            if(counter==number_of_win)
                return 1;
        }
        counter=0;
    }
    return 0;
}

int left_diag_win(char tile, char *board, int num_rows, int num_columns, int number_of_win){
    int counter=0;
    int i,j;
    for(i=0; i<num_rows+num_columns-1; i++){
        if(i<=num_columns-1){
            for(j=0; j<=i; j++){
                if(board[i+j*(num_columns-1)]==tile)
                    counter++;
                if(board[i+j*(num_columns-1)]!=tile)
                    counter=0;
                if(counter==number_of_win)
                    return 1;
            }
            counter=0;
        }else{
            for(j=0; j<=num_rows+num_columns-1-i; j++){
                if(board[i+ (num_columns-1)*(i- num_columns +1) +j*(num_columns-1)]==tile)
                    counter++;
                if(board[i+ (num_columns-1)*(i- num_columns +1) +j*(num_columns-1)]!=tile)
                    counter=0;
                if(counter==number_of_win)
                    return 1;
            }
            counter=0;

        }
    }
    return 0;
}

int right_diag_win(char tile, char *board, int num_rows, int num_columns, int number_of_win){
    int counter=0;
    int i,j;
    for(i=0; i<num_rows+num_columns-1; i++){
        if(i<=num_columns-1){
            for(j=0; j<=i; j++){
                if(board[ num_columns-1-i +j*(num_columns+1)]==tile)
                    counter++;
                if(board[ num_columns-1-i +j*(num_columns+1)]!=tile)
                    counter=0;
                if(counter==number_of_win)
                    return 1;
            }
            counter=0;
        }else{
            for(j=0; j<=num_rows+num_columns-1-i; j++){
                if(board[ num_columns-1-i+ (i-num_columns+1)*(num_columns+1)+j*(num_columns+1)]==tile)
                    counter++;
                if(board[ num_columns-1-i+ (i-num_columns+1)*(num_columns+1)+j*(num_columns+1)]!=tile)
                    counter=0;
                if(counter==number_of_win)
                    return 1;
            }
            counter=0;

        }
    }
    return 0;
}

int check_win(char *board, int num_rows, int num_columns, int number_of_win){

    if(row_win('X', board, num_rows, num_columns, number_of_win) || col_win('X', board, num_rows, num_columns, number_of_win)|| left_diag_win('X', board, num_rows, num_columns, number_of_win) || right_diag_win('X', board, num_rows, num_columns, number_of_win))
        return 1;
    if(row_win('O', board, num_rows, num_columns, number_of_win) || col_win('O', board, num_rows, num_columns, number_of_win)|| left_diag_win('O', board, num_rows, num_columns, number_of_win) || right_diag_win('O', board, num_rows, num_columns, number_of_win))
        return 2;
    if(tie_game(board, num_rows, num_columns))
        return 3;
    return 0;
}

int main(int argc, char *argv[]){
    int num_rows, num_columns, number_of_win;
    if(argc<4){
        printf("Not enough arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }
    else if(argc>4){
        printf("Too many arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }

    num_rows = atoi(argv[1]);
    num_columns=atoi(argv[2]);
    number_of_win=atoi(argv[3]);

    char *board = create_board(num_rows, num_columns);
    print_board(board, num_rows, num_columns);

    char tile='X';
    int play_at_col=0;
    int win_player=0;
    int valid_play=0;
    while(1){
        printf("Enter a column between 0 and %d to play in: ", num_columns-1);
        scanf("%d", &play_at_col);
        valid_play = play_game(tile, board, num_rows, num_columns,play_at_col);

        win_player=check_win(board, num_rows, num_columns, number_of_win);
        if(win_player==1){
            printf("Player 1 Won!\n");
            break;
        }
        else if(win_player==2){
            printf("Player 2 Won!\n");
            break;
        }
        else if(win_player==3){
            printf("Tie game!\n");
            break;
        }
        // else win_player==0, continue with following statement
        if(valid_play){
            if(tile=='X')
                tile='O';
            else if(tile=='O')
                tile='X';
        }
    }

    return 0;
}
