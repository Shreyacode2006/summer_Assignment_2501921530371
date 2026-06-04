#include<stdio.h>
int main()
{ int num, original, reverse = 0, digit;

    printf("enter a number: ");
    scanf("%d", &num);

    original = num;

    while(num != 0)
    {
        digit = num % 10;
        reverse = reverse * 10 + digit;
        num /= 10;
    }

    if(original == reverse)
      printf("palindrome number");
    else 
    printf("not a palindrome number");
    
    return 0;

}