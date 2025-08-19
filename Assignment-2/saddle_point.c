#include <stdio.h>
int main()
{
    int arr[10][10], rows, columns, i, j;
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &columns);

    for (i = 0; i < rows; i++)
    {
        printf("\nEnter the elements for row number %d\n", i + 1);
        for (j = 0; j < columns; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\nThe matrix formed is: \n");
    for (i = 0; i < rows; i++)
    {
        printf("\n");
        for (j = 0; j < columns; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    int found = 0;

    // Find saddle points
    for (i = 0; i < rows; i++)
    {
        // Step 1: Find the minimum element in this row
        int rowMin = arr[i][0];
        int colIndex = 0;
        for (j = 1; j < columns; j++)
        {
            if (arr[i][j] < rowMin)
            {
                rowMin = arr[i][j];
                colIndex = j;
            }
        }

        // Step 2: Check if this row minimum is the maximum in its column
        int isSaddle = 1;
        for (int k = 0; k < rows; k++)
        {
            if (arr[k][colIndex] > rowMin)
            {
                isSaddle = 0;
                break;
            }
        }

        if (isSaddle)
        {
            printf("\nSaddle point found at Row %d, Column %d = %d\n", i + 1, colIndex + 1, rowMin);
            found = 1;
        }
    }

    if (!found)
    {
        printf("\nNo Saddle Point exists in the matrix.\n");
    }

    return 0;
}
