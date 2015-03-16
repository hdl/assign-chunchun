#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct{
    int x;
    int y;
}point;

int main(int argc, char *argv[]){
    FILE *fp;
    fp = fopen(argv[1], "rb");

    int n;
    fread(&n, sizeof(int), 1, fp);
    //printf("%d\n", n);

    point *buffer = (point *)malloc(n*sizeof(point));
    fread(buffer, sizeof(point), n, fp);

    //for(int i=0; i<n; i++){
     //   printf("%d %d\n", buffer[i].x, buffer[i].y);
    //}

    //calculate

    double result=0;
    double a, b;
    int i=0;
    for(i=0; i<=n-2; i++){
        a = buffer[i+1].x - buffer[i].x;
        b = buffer[i+1].y - buffer[i].y;
        result = result + sqrt(a*a + b*b);
    }
    //add the last one
    a = buffer[0].x - buffer[n-1].x;
    b = buffer[0].y - buffer[n-1].y;
    result = result + sqrt(a*a + b*b);
    printf("The perimeter is %0.2f\n", result);

    fclose(fp);
    return 0;

}
