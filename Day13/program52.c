#include <stdio.h>

int main()
{
    int arr[100], n, i;
    int even = 0, odd = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);

        if(arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    printf("Even elements count = %d\n", even);
    printf("Odd elements count = %d", odd);

    return 0;
}