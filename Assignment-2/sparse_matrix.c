<<<<<<< HEAD
#include <stdio.h>

#define MAX 100

void readSparse(int sparse[MAX][3])
{
    int rows, cols, n;
    printf("Enter rows, cols and number of non-zero elements: ");
    scanf("%d %d %d", &rows, &cols, &n);

    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = n;

    printf("Enter row, column and value of non-zero elements (positions start from 1, not index 0):\n");
    for (int i = 1; i <= n; i++)
    {
        int r, c, v;
        scanf("%d %d %d", &r, &c, &v);

        if (r < 1 || r > rows || c < 1 || c > cols)
        {
            printf("Error: Invalid entry (%d,%d). Must be within matrix size %dx%d. Please re-enter:\n",
                   r, c, rows, cols);
            i--;
            continue;
        }

        sparse[i][0] = r;
        sparse[i][1] = c;
        sparse[i][2] = v;
    }
}

void printSparse(int sparse[MAX][3])
{
    int n = sparse[0][2];
    printf("Meta Info: Rows=%d, Cols=%d, Non-zeros=%d\n", sparse[0][0], sparse[0][1], n);
    printf("Row\tCol\tVal\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

void transposeSparse(int a[MAX][3], int b[MAX][3])
{
    int n = a[0][2];
    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = n;

    int k = 1;
    for (int col = 1; col <= a[0][1]; col++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i][1] == col)
            {
                b[k][0] = a[i][1];
                b[k][1] = a[i][0];
                b[k][2] = a[i][2];
                k++;
            }
        }
    }
}

void addSparse(int a[MAX][3], int b[MAX][3], int c[MAX][3])
{
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1])
    {
        printf("Error: Addition not possible. Dimensions mismatch.\n");
        c[0][2] = 0;
        return;
    }

    int i = 1, j = 1, k = 1;
    c[0][0] = a[0][0];
    c[0][1] = a[0][1];

    while (i <= a[0][2] && j <= b[0][2])
    {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1]))
        {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++;
        }
        else if (b[j][0] < a[i][0] || (b[j][0] == a[i][0] && b[j][1] < a[i][1]))
        {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            j++;
        }
        else
        {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2] + b[j][2];
            i++;
            j++;
        }
        k++;
    }

    while (i <= a[0][2])
    {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        i++;
        k++;
    }

    while (j <= b[0][2])
    {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];
        j++;
        k++;
    }

    c[0][2] = k - 1;
}

void multiplySparse(int a[MAX][3], int b[MAX][3], int c[MAX][3])
{
    if (a[0][1] != b[0][0])
    {
        printf("Error: Multiplication not possible. Dimensions mismatch.\n");
        c[0][2] = 0;
        return;
    }

    int temp[MAX][MAX] = {0};

    for (int i = 1; i <= a[0][2]; i++)
    {
        for (int j = 1; j <= b[0][2]; j++)
        {
            if (a[i][1] == b[j][0])
            {
                temp[a[i][0]][b[j][1]] += a[i][2] * b[j][2];
            }
        }
    }

    int k = 1;
    c[0][0] = a[0][0];
    c[0][1] = b[0][1];
    for (int i = 1; i <= a[0][0]; i++)
    {
        for (int j = 1; j <= b[0][1]; j++)
        {
            if (temp[i][j] != 0)
            {
                c[k][0] = i;
                c[k][1] = j;
                c[k][2] = temp[i][j];
                k++;
            }
        }
    }
    c[0][2] = k - 1;
}

int main()
{
    int a[MAX][3], b[MAX][3], trans[MAX][3], sum[MAX][3], product[MAX][3];

    printf("Enter first sparse matrix:\n");
    readSparse(a);
    printSparse(a);

    printf("\nTranspose of first matrix:\n");
    transposeSparse(a, trans);
    printSparse(trans);

    printf("\nEnter second sparse matrix:\n");
    readSparse(b);
    printSparse(b);

    printf("\nAddition of two matrices:\n");
    addSparse(a, b, sum);
    printSparse(sum);

    printf("\nMultiplication of two matrices:\n");
    multiplySparse(a, b, product);
    printSparse(product);

    return 0;
}
=======
#include <stdio.h>

#define MAX 100

// Function to read sparse matrix
void readSparse(int sparse[MAX][3])
{
    int rows, cols, n;
    printf("Enter rows, cols and number of non-zero elements: ");
    scanf("%d %d %d", &rows, &cols, &n);

    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = n;

    printf("Enter row, column and value of non-zero elements (positions start from 1, not index 0):\n");
    for (int i = 1; i <= n; i++)
    {
        int r, c, v;
        scanf("%d %d %d", &r, &c, &v);

        if (r < 1 || r > rows || c < 1 || c > cols)
        {
            printf("❌ Error: Invalid entry (%d,%d). Must be within matrix size %dx%d. Please re-enter:\n",
                   r, c, rows, cols);
            i--; // retry this element
            continue;
        }

        sparse[i][0] = r;
        sparse[i][1] = c;
        sparse[i][2] = v;
    }
}

// Function to print sparse matrix
void printSparse(int sparse[MAX][3])
{
    int n = sparse[0][2];
    printf("Meta Info: Rows=%d, Cols=%d, Non-zeros=%d\n", sparse[0][0], sparse[0][1], n);
    printf("Row\tCol\tVal\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

// Transpose of sparse matrix
void transposeSparse(int a[MAX][3], int b[MAX][3])
{
    int n = a[0][2];
    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = n;

    int k = 1;
    for (int col = 1; col <= a[0][1]; col++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i][1] == col)
            {
                b[k][0] = a[i][1];
                b[k][1] = a[i][0];
                b[k][2] = a[i][2];
                k++;
            }
        }
    }
}

// Addition of two sparse matrices
void addSparse(int a[MAX][3], int b[MAX][3], int c[MAX][3])
{
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1])
    {
        printf("❌ Error: Addition not possible. Dimensions mismatch.\n");
        c[0][2] = 0;
        return;
    }

    int i = 1, j = 1, k = 1;
    c[0][0] = a[0][0];
    c[0][1] = a[0][1];

    while (i <= a[0][2] && j <= b[0][2])
    {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1]))
        {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++;
        }
        else if (b[j][0] < a[i][0] || (b[j][0] == a[i][0] && b[j][1] < a[i][1]))
        {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            j++;
        }
        else
        {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2] + b[j][2];
            i++;
            j++;
        }
        k++;
    }

    while (i <= a[0][2])
    {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        i++;
        k++;
    }

    while (j <= b[0][2])
    {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];
        j++;
        k++;
    }

    c[0][2] = k - 1;
}

// Multiplication of two sparse matrices
void multiplySparse(int a[MAX][3], int b[MAX][3], int c[MAX][3])
{
    if (a[0][1] != b[0][0])
    {
        printf("❌ Error: Multiplication not possible. Dimensions mismatch.\n");
        c[0][2] = 0;
        return;
    }

    int temp[MAX][MAX] = {0};

    for (int i = 1; i <= a[0][2]; i++)
    {
        for (int j = 1; j <= b[0][2]; j++)
        {
            if (a[i][1] == b[j][0])
            {
                temp[a[i][0]][b[j][1]] += a[i][2] * b[j][2];
            }
        }
    }

    int k = 1;
    c[0][0] = a[0][0];
    c[0][1] = b[0][1];
    for (int i = 1; i <= a[0][0]; i++)
    {
        for (int j = 1; j <= b[0][1]; j++)
        {
            if (temp[i][j] != 0)
            {
                c[k][0] = i;
                c[k][1] = j;
                c[k][2] = temp[i][j];
                k++;
            }
        }
    }
    c[0][2] = k - 1;
}

int main()
{
    int a[MAX][3], b[MAX][3], trans[MAX][3], sum[MAX][3], product[MAX][3];

    printf("Enter first sparse matrix:\n");
    readSparse(a);
    printSparse(a);

    printf("\nTranspose of first matrix:\n");
    transposeSparse(a, trans);
    printSparse(trans);

    printf("\nEnter second sparse matrix:\n");
    readSparse(b);
    printSparse(b);

    printf("\nAddition of two matrices:\n");
    addSparse(a, b, sum);
    printSparse(sum);

    printf("\nMultiplication of two matrices:\n");
    multiplySparse(a, b, product);
    printSparse(product);

    return 0;
}
>>>>>>> 1781a33c1b10b5361a91c2198b1f9855e991af9b
