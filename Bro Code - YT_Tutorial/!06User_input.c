#include <stdio.h>
#include <string.h>

int main(){

    char name[25]; // 25 bytes
    int age;

    printf("\nWhat's your name?");
    //scanf("%s",name); << don't work with blank spaces
    fgets(name, 25, stdin); // fgets(variable, bytes, standard_input)\n
    name[strlen(name)-1] = '\0'; // string function

    printf("\nHow old are you?");
    scanf("%d",&age);

    printf("\nHello %s",name);
    printf("\nYou are %d years old", age);

    return 0;
}