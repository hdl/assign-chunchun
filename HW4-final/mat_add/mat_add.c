#include <stdio.h>
#include <stdlib.h>

int main(){

    int row, col;

    printf("Please enter the number of rows: ");
    scanf("%d", &row);
    printf("Please enter the number of columns: ");
    scanf("%d", &col);

    int *m1;
    int *m2;
    int *res;

    m1 = (int *)malloc(sizeof(int)*row*col);
    m2 = (int *)malloc(sizeof(int)*row*col);
    res = (int *)malloc(sizeof(int)*row*col);
    printf("Enter Matrix A\n");
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)
            scanf("%d", &m1[i*col+j]);
    }
    printf("Enter Matrix B\n");
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)
            scanf("%d", &m2[i*col+j]);
    }

    //add
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)
            res[i*col+j] = m1[i*col+j] + m2[i*col+j];
    }
    // output
    printf("A + B =\n");
    int i,j;
    for(i=0; i<row; i++){
        for(j=0; j<col-1; j++)
            printf("%d ", res[i*col+j]);
        printf("%d\n", res[i*col+j]);
    }
    return 0;
}
