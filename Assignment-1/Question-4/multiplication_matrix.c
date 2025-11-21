#include <stdio.h>

int main()
{
    int rows_1;
    int columns_1;
    int rows_2;
    int columns_2;
    int i;
    int j;
    int k;
    int mul_element = 0;

    printf("Enter the number of rows for matrix 1: ");
    scanf("%d", &rows_1);

    printf("Enter the number of columns for matrix 1: ");
    scanf("%d", &columns_1);

    int array_1[rows_1][columns_1];

    printf("\n\nEnter the elements for first matrix.\n");

    for (i = 0; i < rows_1; i++)
    {
        printf("Enter the elements for row number %d\n", i + 1);
        for (j = 0; j < columns_1; j++)
        {
            scanf("%d", &array_1[i][j]);
        }
    }

    printf("\n\nEnter the number of rows for matrix 2: ");
    scanf("%d", &rows_2);

    printf("Enter the number of columns for matrix 2: ");
    scanf("%d", &columns_2);

    if (columns_1 != rows_2)
    {
        printf("Multiplication of these 2 matrices is not possible.");
        return 0;
    }

    int array_2[rows_2][columns_2];

    printf("\nEnter the elements for second matrix.\n");

    for (i = 0; i < rows_2; i++)
    {
        printf("Enter the elements for row number %d\n", i + 1);
        for (j = 0; j < columns_2; j++)
        {
            scanf("%d", &array_2[i][j]);
        }
    }

    printf("\nThe First matrix is: ");

    for (i = 0; i < rows_1; i++)
    {
        // printf("Enter the elements for row number %d\n", i + 1);
        printf("\n");
        for (j = 0; j < columns_1; j++)
        {
            printf("%d\t", array_1[i][j]);
        }
    }

    printf("\nThe Second matrix is: ");

    for (i = 0; i < rows_2; i++)
    {
        // printf("Enter the elements for row number %d\n", i + 1);
        printf("\n");
        for (j = 0; j < columns_2; j++)
        {
            printf("%d\t", array_2[i][j]);
        }
    }

    // int array_3[rows][columns];
    int mul_result[rows_1][columns_2];

    printf("\n\nThe resultant product matrix is: ");

    for (i=0;i<rows_1;i++){
        for (j=0;j<columns_2;j++){
            for (k=0;k<rows_2;k++){
                mul_element = mul_element + array_1[i][k]*array_2[k][j];
            }
            mul_result[i][j] = mul_element;
            mul_element = 0;
        }
    }

    for (i=0;i<rows_1;i++){
        printf("\n");
        for (j=0;j<columns_2;j++){
            printf("%d\t",mul_result[i][j]);
        }

    }
    return 0;
}