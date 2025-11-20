#include <stdio.h>

int indexUpper(int i, int j, int n)
{
    return (i * n - (i * (i - 1)) / 2) + (j - i);
}

void setUpper(int upper[], int n, int i, int j, int x)
{
    if (i <= j)
        upper[indexUpper(i, j, n)] = x;
}

int getUpper(int upper[], int n, int i, int j)
{
    if (i <= j)
        return upper[indexUpper(i, j, n)];
    else
        return 0;
}

int main()
{
    int n = 4;
    int size = n * (n + 1) / 2;
    int upper[size];

    for (int i = 0; i < size; i++)
        upper[i] = 0;

    setUpper(upper, n, 0, 0, 1);
    setUpper(upper, n, 0, 1, 2);
    setUpper(upper, n, 0, 2, 3);
    setUpper(upper, n, 0, 3, 4);
    setUpper(upper, n, 1, 1, 5);
    setUpper(upper, n, 1, 2, 6);
    setUpper(upper, n, 1, 3, 7);
    setUpper(upper, n, 2, 2, 8);
    setUpper(upper, n, 2, 3, 9);
    setUpper(upper, n, 3, 3, 10);

    printf("Upper Triangular Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", getUpper(upper, n, i, j));
        }
        printf("\n");
    }

    return 0;
}
