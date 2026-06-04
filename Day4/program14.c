#include <stdio.h>

int main() {
    int n, i;
    long long first = 0, second = 1, next;

    printf("Enter the term number: ");
    scanf("%d", &n);

    if (n == 1)
        printf("The %dst Fibonacci term is %lld", n, first);
    else if (n == 2)
        printf("The %dnd Fibonacci term is %lld", n, second);
    else {
        for (i = 3; i <= n; i++) {
            next = first + second;
            first = second;
            second = next;
        }
        printf("The %dth Fibonacci term is %lld", n, second);
    }

    return 0;
}