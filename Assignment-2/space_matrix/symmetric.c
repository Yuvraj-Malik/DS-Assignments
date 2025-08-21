#include <stdio.h>

int indexSym(int i, int j)
{
    return (i * (i + 1)) / 2 + j;
}

void setSymmetric(int sym[], int n, int i, int j, int x)
{
    if (i >= j)
        sym[indexSym(i, j)] = x;
    else
        sym[indexSym(j, i)] = x;
}

int getSymmetric(int sym[], int n, int i, int j)
{
    if (i >= j)
        return sym[indexSym(i, j)];
    else
        return sym[indexSym(j, i)];
}

int main()
{
    int n = 4;
    int size = n * (n + 1) / 2;
    int sym[size];

    for (int i = 0; i < size; i++)
        sym[i] = 0;

    setSymmetric(sym, n, 0, 0, 1);
    setSymmetric(sym, n, 1, 0, 2);
    setSymmetric(sym, n, 1, 1, 3);
    setSymmetric(sym, n, 2, 0, 4);
    setSymmetric(sym, n, 2, 1, 5);
    setSymmetric(sym, n, 2, 2, 6);
    setSymmetric(sym, n, 3, 0, 7);
    setSymmetric(sym, n, 3, 1, 8);
    setSymmetric(sym, n, 3, 2, 9);
    setSymmetric(sym, n, 3, 3, 10);

    printf("Symmetric Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", getSymmetric(sym, n, i, j));
        }
        printf("\n");
    }

    return 0;
}
