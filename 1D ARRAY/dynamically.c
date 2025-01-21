#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr, n;

    // Input array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory dynamically
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed!");
        return 1;
    }

    // Input array elements
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Print array elements
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Free allocated memory
    free(arr);
    return 0;
}
