#include <stdio.h>
#include <string.h>

int main(){

    char string1[] = "Lucas";
    char string2[] = "Lisboa";

    strlwr(string1);                   // lowercase
    strupr(string1);                  // uppercase
    strcat(string1, string2);        // appends
    strncat(string1, string2, 1);   // appens n characters
    strcpy(string1, string2);      // copy
    strncpy(string1, string2, 4); // copy n characters

    strset(string1, '?');      // sets all characters of a string to a given character
    strnset(string1, 'x', 1); // sets first n characters of a string to a given character
    strrev(string1);         // reverses a string

    int result = strlen(string1);                   // string lenght as int
    int result = strcmp(string1, string2);         // string compare all characters
    int result = strncmp(string1, string2, 1);    // string compare n characters
    int result = strcmpi(string1, string2);      // string compare all (ignore case)
    int result = strnicmp(string1, string2, 1); // string compare n characters (ignore case)

    printf("%d", result);

    if(result == 0){

        printf("These strings are the same");
    }
    else{
        printf("These strings are not the same");
    }

    return 0;
}