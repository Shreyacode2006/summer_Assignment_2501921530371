#include <stdio.h>

int main() {
    char str[200];
    int i, count = 0, inWord = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] != ' ' && str[i] != '\n' && inWord == 0) {
            count++;
            inWord = 1;
        }
        else if(str[i] == ' ' || str[i] == '\n') {
            inWord = 0;
        }
    }

    printf("Number of words = %d", count);

    return 0;
}