#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    int counter=0;
    char temp;
    FILE *fp;
    fp = fopen(argv[1], "r");
    temp=fgetc(fp);
    //printf("temp is %c\n", temp);
    while(temp != EOF){
        if(isspace(temp)){
            counter++;
            // if while space, move on to check more
            while(1){
                temp=fgetc(fp);
                //printf("temp is %c\n", temp);
                if(!isspace(temp) || temp==EOF)
                    break;
            }
        }else{
            temp=fgetc(fp);
        }

    }
    printf("There are %d word(s).\n", counter);

    fclose(fp);
    return 0;
}
