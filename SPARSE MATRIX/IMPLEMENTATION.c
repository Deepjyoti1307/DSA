#include <stdio.h>

#define MAX 100 // Maximum number of non-zero elements

int main()
{
    int rows, cols, matrix[10][10], sparse[MAX][3], k = 0;

    // Input matrix dimensions
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Input the matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    // Print the sparse matrix representation
    printf("\nSparse Matrix Representation (row, column, value):\n");
    for (int i = 0; i < k; i++)
    {
        printf("%d %d %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }

    return 0;
}
