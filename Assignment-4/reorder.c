<<<<<<< HEAD
#include <stdio.h>

void interleaveQueue(int arr[], int n)
{
    int half = n / 2;
    int result[n];
    int i, j = 0;

    for (i = 0; i < half; i++)
    {
        result[j++] = arr[i];
        result[j++] = arr[i + half];
    }

    for (i = 0; i < n; i++)
    {
        arr[i] = result[i];
    }
}

int main()
{
    int n, i;
    printf("Enter number of elements (even): ");
    scanf("%d", &n);

    if (n % 2 != 0)
    {
        printf("Number of elements must be even.\n");
        return 0;
    }

    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    interleaveQueue(arr, n);

    printf("Interleaved Queue: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
=======
#include <stdio.h>

void interleaveQueue(int arr[], int n)
{
    int half = n / 2;
    int result[n];
    int i, j = 0;

    for (i = 0; i < half; i++)
    {
        result[j++] = arr[i];
        result[j++] = arr[i + half];
    }

    for (i = 0; i < n; i++)
    {
        arr[i] = result[i];
    }
}

int main()
{
    int n, i;
    printf("Enter number of elements (even): ");
    scanf("%d", &n);

    if (n % 2 != 0)
    {
        printf("Number of elements must be even.\n");
        return 0;
    }

    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    interleaveQueue(arr, n);

    printf("Interleaved Queue: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
>>>>>>> 8b15ef0 (Assignment-6 Done)
