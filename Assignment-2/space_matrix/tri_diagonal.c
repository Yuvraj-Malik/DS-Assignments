#include <stdio.h>

void setTriDiagonal(int tri[], int n, int i, int j, int x)
{
    if (i == j)
        tri[i] = x;
    else if (i == j + 1)
        tri[n + j] = x;
    else if (i + 1 == j)
        tri[2 * n - 1 + i] = x;
}

int getTriDiagonal(int tri[], int n, int i, int j)
{
    if (i == j)
        return tri[i];
    else if (i == j + 1)
        return tri[n + j];
    else if (i + 1 == j)
        return tri[2 * n - 1 + i];
    else
        return 0;
}

int main()
{
    int n = 4;
    int tri[3 * 4 - 2] = {0};

    setTriDiagonal(tri, n, 0, 0, 1);
    setTriDiagonal(tri, n, 1, 0, 2);
    setTriDiagonal(tri, n, 1, 1, 3);
    setTriDiagonal(tri, n, 2, 1, 4);
    setTriDiagonal(tri, n, 2, 2, 5);
    setTriDiagonal(tri, n, 3, 2, 6);
    setTriDiagonal(tri, n, 3, 3, 7);

    printf("Tri-diagonal Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", getTriDiagonal(tri, n, i, j));
        }
        printf("\n");
    }
}
