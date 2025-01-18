#include <stdio.h>
#include <stdbool.h>

int main(){

    float temp = 25;

    if (temp <= 0 || temp >= 30){ // || (OR) at least one condition is true
        printf("\nThe weather is bad!");
    }
    else{
        printf("\nThe weather is good!");
    }

    return 0;
}