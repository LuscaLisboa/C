#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int MIN = 1;
    const int MAX = 100; 
    int guess;
    int guesses;
    int answer;

    // uses the current time as a sees
    srand(time(0));

    // generate a random number between MIN & MAX
    answer = (rand() % MAX) + MIN;

    do{
        printf("\nEnter a guess: ");
        scanf("%d", &guess);
        if(guess > answer)
        {
            printf("\nToo high!\n");
        }
        else if(guess < answer)
        {
            printf("Too low!\n");
        }
        else{
            printf("CORREET!\n");
        }
        guesses++;
    } while(guess != answer);

    printf("\n************************");
    printf("\nanswer: %d\n", answer);
    printf("guesses: %d\n", guesses);
    printf("************************");

    return 0;
}