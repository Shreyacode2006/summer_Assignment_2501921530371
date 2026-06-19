#include <stdio.h>

int main() {
    int n, i, j;
    int sum1 = 0, sum2 = 0;

    printf("Enter size of matrix: ");
    scanf("%d", &n);

    int a[n][n];

    printf("Enter matrix elements:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Main diagonal sum
    for(i = 0; i < n; i++) {
        sum1 = sum1 + a[i][i];
    }

    // Secondary diagonal sum
    for(i = 0; i < n; i++) {
        sum2 = sum2 + a[i][n - i - 1];
    }

    printf("Main diagonal sum = %d\n", sum1);
    printf("Secondary diagonal sum = %d", sum2);

    return 0;
}