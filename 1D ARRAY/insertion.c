#include <stdio.h>

int main()
{
    int arr[100], n, pos, elem;

    // Input array size
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Input position and element
    printf("Enter the position to insert (0-based index): ");
    scanf("%d", &pos);
    printf("Enter the element to insert: ");
    scanf("%d", &elem);

    // Insert element
    for (int i = n; i > pos; i--)
    {
        arr[i] = arr[i - 1]; // Shift elements to the right
    }
    arr[pos] = elem; // Insert new element
    n++;             // Increment array size

    // Print updated array
    printf("Updated array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
