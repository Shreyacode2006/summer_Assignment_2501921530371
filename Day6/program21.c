#include<stdio.h>
int main()
{ int n, binary[32], i = 0;

    printf("enter a decimal number: ");
    scanf("%d", &n);

    while(n > 0)
    {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }

    printf("binary = ");
    for(int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }
      return 0;
}