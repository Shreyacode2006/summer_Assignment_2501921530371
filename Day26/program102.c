#include <stdio.h>

int main() {

    int ans, score = 0;

    printf("Quiz Application\n");

    printf("\n1. C language is developed by?");
    printf("\n1. Dennis Ritchie\n2. James Gosling\n3. Bjarne Stroustrup\n");
    scanf("%d",&ans);

    if(ans == 1)
        score++;

    printf("\n2. Which is an input device?");
    printf("\n1. Monitor\n2. Keyboard\n3. Printer\n");
    scanf("%d",&ans);

    if(ans == 2)
        score++;

    printf("\n3. Which symbol is used for comments in C?");
    printf("\n1. //\n2. #\n3. @\n");
    scanf("%d",&ans);

    if(ans == 1)
        score++;

    printf("\nYour Score = %d/3", score);

    return 0;
}