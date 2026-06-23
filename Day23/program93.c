#include <stdio.h>

int main()
{
    char str[100];
    int freq[256] = {0};
    int max = 0;
    char result;

    printf("Enter string: ");
    gets(str);

    for(int i=0; str[i]!='\0'; i++)
        freq[(unsigned char)str[i]]++;

    for(int i=0; str[i]!='\0'; i++)
    {
        if(freq[(unsigned char)str[i]] > max)
        {
            max = freq[(unsigned char)str[i]];
            result = str[i];
        }
    }

    printf("Maximum occurring character: %c", result);

    return 0;
}