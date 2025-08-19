#include <stdio.h>
int main()
{
    int arr[10][10], rows, columns, i, j;
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columnss: ");
    scanf("%d", &columns);

    for (i = 0; i < rows; i++)
    {
        printf("\nEnter the elements for row number %d\n", i + 1);
        for (j = 0; j < columns; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("The matrix formed is: \n");

    for (i = 0; i < rows; i++)
    {
        printf("\n");
        for (j = 0; j < columns; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    printf("The sum of Rows is:\n");
    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        for (int j = 0; j < columns; j++)
        {
            sum += arr[i][j];
        }
        printf("Row %d sum = %d\n", i + 1, sum);
    }
    printf("\n");
    
    printf("The sum of Columns is:\n");
    for (int j = 0; j < columns; j++)
    {
        int sum = 0;
        for (int i = 0; i < rows; i++)
            sum += arr[i][j];
        printf("Column %d sum = %d\n", j + 1, sum);
    }
}