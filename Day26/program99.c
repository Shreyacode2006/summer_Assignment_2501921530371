#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, guess, attempts = 0;

    srand(time(0));
    num = rand() % 100 + 1;

    printf("Guess the number between 1 and 100\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if(guess > num)
            printf("Too high!\n");
        else if(guess < num)
            printf("Too low!\n");
        else
            printf("Correct! You guessed in %d attempts\n", attempts);

    } while(guess != num);

    return 0;
}