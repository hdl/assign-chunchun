#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    int n;
    FILE *fp;
    fp = fopen(argv[1], "r");
    n = atoi(argv[2]);


    // get all line num
    int line_counter=0;
    char ch;
    do{
        ch = fgetc(fp);
        if( ch== '\n')
            line_counter++;
    }while( ch != EOF );

    //printf("Total number of lines %d\n",line_counter);

    // fseek
    int counter=0;
    fseek(fp, 0, SEEK_SET);
    if(n<line_counter){
        do{
            ch = fgetc(fp);
            if( ch== '\n'){
                counter++;
                if(counter == line_counter - n){
                    break;
                }
            }
        }while( ch != EOF );
    }
    // print
    while((ch = fgetc(fp)) != EOF){
        printf("%c", ch);
    }

    fclose(fp);
    return 0;
}
