#include <stdio.h>
#include <string.h>

int main()
{
    char str[200], word[50], longest[50];
    int i=0, j=0, max=0, len;

    printf("Enter sentence: ");
    gets(str);

    while(1)
    {
        if(str[i] != ' ' && str[i] != '\0')
        {
            word[j++] = str[i];
        }
        else
        {
            word[j] = '\0';

            len = strlen(word);

            if(len > max)
            {
                max = len;
                strcpy(longest, word);
            }

            j = 0;
        }

        if(str[i] == '\0')
            break;

        i++;
    }

    printf("Longest word: %s", longest);

    return 0;
}