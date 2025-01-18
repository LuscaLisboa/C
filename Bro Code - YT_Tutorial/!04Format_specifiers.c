#include <stdio.h>

int main(){

    /*
    %c = character
    %s = string (array of characters)
    %f = float
    %lf = double
    %d = integer

    %.1 = decimal precision
    %1 = minimun field width
    %- = left align
    */ 

    float item1 = 5.75;
    float item2 = 10.00;
    float item3 = 19.99;

    printf("Item 1: $%6.2f\n",item1);
    printf("Item 2: $%6.2f\n",item2);
    printf("Item 3: $%6.2f",item3);


    return 0;
}