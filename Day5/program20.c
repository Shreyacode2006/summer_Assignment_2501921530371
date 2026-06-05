#include<stdio.h>
int main()
{ long long n;
    int largestprime = 0;

    printf("enter a number :");
    scanf("lld", &n);

    while(n % 2 == 0)
    {
        largestprime = 2;
        n /= 2;
    }

    for(int i = 3; i * i <= n; i += 2)
    {
        while(n % i == 0)
        {
            largestprime = i;
            n /= i;
        }
    }

    if(n > 2)
    largestprime = n;

    printf("largest prime factor = %d", largestprime);

    return 0;

}