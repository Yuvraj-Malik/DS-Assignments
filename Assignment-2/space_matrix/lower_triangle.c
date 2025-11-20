#include <stdio.h>

int indexLower(int i, int j)
{
    return (i * (i + 1)) / 2 + j;
}

void setLower(int lower[], int n, int i, int j, int x)
{
    if (i >= j)
        lower[indexLower(i, j)] = x;
}

int getLower(int lower[], int n, int i, int j)
{
    if (i >= j)
        return lower[indexLower(i, j)];
    else
        return 0;
}

int main()
{
    int n = 4;
    int size = n * (n + 1) / 2;
    int lower[size];

    for (int i = 0; i < size; i++)
        lower[i] = 0;

    setLower(lower, n, 0, 0, 1);
    setLower(lower, n, 1, 0, 2);
    setLower(lower, n, 1, 1, 3);
    setLower(lower, n, 2, 0, 4);
    setLower(lower, n, 2, 1, 5);
    setLower(lower, n, 2, 2, 6);
    setLower(lower, n, 3, 0, 7);
    setLower(lower, n, 3, 1, 8);
    setLower(lower, n, 3, 2, 9);
    setLower(lower, n, 3, 3, 10);

    printf("Lower Triangular Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", getLower(lower, n, i, j));
        }
        printf("\n");
    }

    return 0;
}
