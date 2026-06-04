#include <stdio.h>

int main() {
    int a, b, num1, num2, gcd, lcm, temp;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    num1 = a;
    num2 = b;

    while (num2 != 0) {
        temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }

    gcd = num1;
    lcm = (a * b) / gcd;

    printf("LCM = %d", lcm);

    return 0;
}