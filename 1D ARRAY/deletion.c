#include <stdio.h>

int main()
{
    int arr[100], n, pos;

    // Input array size
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Input position to delete
    printf("Enter the position to delete (0-based index): ");
    scanf("%d", &pos);

    // Delete element
    for (int i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1]; // Shift elements to the left
    }
    n--; // Decrement array size

    // Print updated array
    printf("Updated array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
