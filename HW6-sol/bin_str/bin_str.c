#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int possible_solution(char *str, int n){

    if(n==strlen(str)-1)
        return (str[n]=='x' ? 2 :1); //if the last is x, return 2, else return 1
    else if(str[n]=='0'||str[n]=='1')
        return possible_solution(str, n+1);
    else if(str[n]=='x')
        return 2*possible_solution(str, n+1);
    else
        return 0;
}
*/

void rec_print(char *str, int n, int total){
    char * new_str1 = malloc(sizeof(char) * total);
    char * new_str0 = malloc(sizeof(char) * total);
    strcpy(new_str1, str);
    strcpy(new_str0, str);
    new_str0[n] = '0';
    new_str1[n] = '1';

    if(n==strlen(str)-1){  // the base condition, only if it's base conditionl, we print it
        if(str[n]=='x'){
            printf("%s\n", new_str0);
            printf("%s\n", new_str1);
        }else
            printf("%s\n", str);
    }

    // rec call
    if(str[n]=='0'||str[n]=='1'){
        rec_print(str, n+1, total);
    }
    else if(str[n]=='x'){

        rec_print(new_str0, n+1, total);
        rec_print(new_str1, n+1, total);
    }

    free(new_str0);
    free(new_str1);
    return;
}


int main(int argc, char *argv[]){
    int total;
    total = strlen(argv[1]); // get the length of the binary string

    rec_print(argv[1], 0, total);


}


