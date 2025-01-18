#include <stdio.h>

int findMax(int x, int y){

    return (x > y)? x : y; // (condition) ? value if true : valua if false
}

int main(){

    int max = findMax(3,4);

    printf("%d", max);

    return 0;
}