#include<stdio.h>
int main()
{ int num, digit , product = 1;

    printf("enter a number: ");
    scanf("%d", &num);

    while(num != 0)
    {
        digit = num % 10;
        product *= digit;
        num /= 10;
    }
      
      printf(" product of digit = %d", product);

      return 0;
}