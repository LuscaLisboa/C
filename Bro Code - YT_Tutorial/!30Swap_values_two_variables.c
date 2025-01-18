#include <stdio.h>
#include <string.h>

int main(){

    char x[15] = "water";
    char y[15] = "soda";
    char temp[15];

    strcpy(temp, x);
    strcpy(x, y);
    strcpy(y, temp);

    printf("X = %s\n", x);
    printf("Y = %s\n", y);

    return 0;
}