#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, **arr;

    // Input number of rows
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Allocate memory for rows
    arr = (int **)malloc(rows * sizeof(int *));
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input the size of each row and allocate memory for columns
    for (int i = 0; i < rows; i++)
    {
        int cols;
        printf("Enter the number of columns for row %d: ", i + 1);
        scanf("%d", &cols);

        arr[i] = (int *)malloc(cols * sizeof(int));
        if (arr[i] == NULL)
        {
            printf("Memory allocation failed!\n");
            return 1;
        }

        // Input elements for the current row
        printf("Enter %d elements for row %d: ", cols, i + 1);
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // Display the 2D array
    printf("The 2D array is:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; arr[i][j] != '\0'; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
