#include <stdio.h>

int main() {
    int n1, n2, i, j, k = 0, flag;

    printf("Enter size of first array: ");
    scanf("%d", &n1);

    int a[n1];

    printf("Enter first array elements:\n");
    for(i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &n2);

    int b[n2];
    int u[n1 + n2];

    printf("Enter second array elements:\n");
    for(i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
    }

    // Add first array elements
    for(i = 0; i < n1; i++) {
        u[k++] = a[i];
    }

    // Add second array elements if not present
    for(i = 0; i < n2; i++) {
        flag = 0;

        for(j = 0; j < k; j++) {
            if(b[i] == u[j]) {
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            u[k++] = b[i];
        }
    }

    printf("Union of arrays:\n");
    for(i = 0; i < k; i++) {
        printf("%d ", u[i]);
    }

    return 0;
}