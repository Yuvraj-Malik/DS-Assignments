<<<<<<< HEAD
#include <stdio.h>

void setDiagonal(int diag[], int n, int i, int x)
{
    if (i >= 0 && i < n)
    {
        diag[i] = x;
    }
}

int getDiagonal(int diag[], int n, int i, int j)
{
    if (i == j)
        return diag[i];
    else
        return 0;
}

int main()
{
    int n = 4;
    int diag[4] = {0};

    setDiagonal(diag, n, 0, 5);
    setDiagonal(diag, n, 1, 8);
    setDiagonal(diag, n, 2, 3);
    setDiagonal(diag, n, 3, 6);

    printf("Diagonal Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", getDiagonal(diag, n, i, j));
        }
        printf("\n");
    }
}
=======
#include <stdio.h>

void setDiagonal(int diag[], int n, int i, int x)
{
    if (i >= 0 && i < n)
    {
        diag[i] = x;
    }
}

int getDiagonal(int diag[], int n, int i, int j)
{
    if (i == j)
        return diag[i];
    else
        return 0;
}

int main()
{
    int n = 4;
    int diag[4] = {0};

    setDiagonal(diag, n, 0, 5);
    setDiagonal(diag, n, 1, 8);
    setDiagonal(diag, n, 2, 3);
    setDiagonal(diag, n, 3, 6);

    printf("Diagonal Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", getDiagonal(diag, n, i, j));
        }
        printf("\n");
    }
}
>>>>>>> 8b15ef0 (Assignment-6 Done)
