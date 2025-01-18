#include <stdio.h>

int main(){

    int rows;
    int columns;
    char symbol;

    printf("\nEnter a number of rows: ");
    scanf("\n%d", &rows);

    printf("\nEnter a number of columns: ");
    scanf("\n%d", &columns);

    scanf("%c");

    printf("Enter a symbol do use: ");
    scanf("%c", &symbol);

    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            printf("%c", symbol);
        }
        printf("\n");
    }

    return 0;
}