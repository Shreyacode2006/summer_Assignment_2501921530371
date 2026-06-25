#include <stdio.h>
#include <string.h>

int main()
{
    char s1[100], s2[100];
    int i, j, found;

    printf("Enter first string: ");
    gets(s1);

    printf("Enter second string: ");
    gets(s2);

    printf("Common characters: ");

    for(i = 0; s1[i] != '\0'; i++)
    {
        found = 0;

        for(j = 0; s2[j] != '\0'; j++)
        {
            if(s1[i] == s2[j])
            {
                found = 1;
                break;
            }
        }

        if(found)
            printf("%c ", s1[i]);
    }

    return 0;
}