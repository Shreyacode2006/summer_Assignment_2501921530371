#include <stdio.h>

int main() {
    int arr[] = {1, 0, 3, 0, 5, 2, 0};
    int n = 7;

    int j = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }

    printf("Array after moving zeroes: ");

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}