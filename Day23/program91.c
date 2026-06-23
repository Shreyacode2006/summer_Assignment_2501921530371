#include <stdio.h>

int main()
{
    char str[100];
    int freq[256] = {0};

    printf("Enter string: ");
    gets(str);

    for(int i = 0; str[i] != '\0'; i++)
    {
        freq[(unsigned char)str[i]]++;

        if(freq[(unsigned char)str[i]] > 1)
        {
            printf("First repeating character: %c", str[i]);
            return 0;
        }
    }

    printf("No repeating character");

    return 0;
}