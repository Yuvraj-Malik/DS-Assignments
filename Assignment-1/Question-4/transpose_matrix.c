#include <stdio.h>

int main()
{
    int rows;
    int columns;
    int i;
    int j;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of cloumns: ");
    scanf("%d", &columns);

    int array[rows][columns];
    int transpose[columns][rows];

    for (i = 0; i < rows; i++)
    {
        printf("Enter the elements for the row number %d\n", i + 1);

        for (j = 0; j < columns; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }

    printf("The matrix formed is: \n");

    for (i = 0; i < rows; i++)
    {
        printf("\n");
        for (j = 0; j < columns; j++)
        {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            transpose[j][i] = array[i][j];
        }
    }
    printf("The transposed matrix is: \n");

    for (i = 0; i < columns; i++)
    {
        printf("\n");
        for (j = 0; j < rows; j++)
        {
            printf("%d\t", transpose[i][j]);
        }
    }

    return 0;
}