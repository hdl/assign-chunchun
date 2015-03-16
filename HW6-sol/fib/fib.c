#include <stdio.h>
#include <stdlib.h>

/*
this is the classical recursive call
int fib(int n){

    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return fib(n-1)+fib(n-2);
}
*/

// one call only
// Pass the index i and a place to save the previous Fibonacci[i-1]. Return Fibonacci[i].
int fib(int i, int *prev){
    if(i<=1){
        *prev = 0;
        return i;
    }
    int f2; //the second
    int f1; //the fist
    f1 = fib(i-1, &f2);  // first is got in this function layer, second is got in next layer
    *prev=f1;
    return f1+f2;
}

int main(int argc, char *argv[]){
    int n;
    n = atoi(argv[1]); // get the argument, the number you want to calculate
    //atoi() convert string to int
    int prev;
    printf("The %dth fibanocci number is %d.", n, fib(n, &prev));
    return 0;
}


