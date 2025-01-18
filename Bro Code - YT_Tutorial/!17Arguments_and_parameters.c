#include <stdio.h>

void birthday(char x[], int y){
    printf("\nHappy birthday dear %s!", x);
    printf("\nYou are %d year old!", y);
}

int main(){

    char name[] = "Lucas";
    int age = 20;

    birthday(name, age);

    return 0;
}