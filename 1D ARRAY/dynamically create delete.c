#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr, n, choice, pos, elem;

    // Input initial array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory dynamically
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input array elements
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    while (1)
    {
        printf("\nMenu:\n1. Insert element\n2. Delete element\n3. Display array\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Insert element
            printf("Enter position (0-based index) to insert: ");
            scanf("%d", &pos);
            printf("Enter the element to insert: ");
            scanf("%d", &elem);

            n++;
            arr = (int *)realloc(arr, n * sizeof(int)); // Resize array
            if (arr == NULL)
            {
                printf("Memory allocation failed!\n");
                return 1;
            }

            for (int i = n - 1; i > pos; i--)
            {
                arr[i] = arr[i - 1]; // Shift elements to the right
            }
            arr[pos] = elem;
            printf("Element inserted.\n");
            break;

        case 2: // Delete element
            printf("Enter position (0-based index) to delete: ");
            scanf("%d", &pos);

            for (int i = pos; i < n - 1; i++)
            {
                arr[i] = arr[i + 1]; // Shift elements to the left
            }
            n--;
            arr = (int *)realloc(arr, n * sizeof(int)); // Resize array
            if (arr == NULL && n > 0)
            {
                printf("Memory allocation failed!\n");
                return 1;
            }

            printf("Element deleted.\n");
            break;

        case 3: // Display array
            printf("Array elements: ");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;

        case 4: // Exit
            free(arr);
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}
