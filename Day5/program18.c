#include<stdio.h>
int main()
{ int  n , temp , digit , fact , sum = 0 , i ;

    printf("enter a number: ");
    scanf("%d", &n);

    temp = n;

    while(temp > 0)
    {
        digit = temp % 10;
        fact = 1;

        for(i = 1; i <= digit; i++)
       { fact *= i;      }
    
       sum += fact;
       temp /= 10;}

       if(sum == n)

       printf("%d is a strong number", n);

       else
       printf("%d is not a strong number", n);

       return 0;
}