#include <stdio.h>

int countDistinctAndDisplay(int arr[], int n)
{
    int count = 0;

    printf("Distinct elements are: ");
    for (int i = 0; i < n; i++)
    {
        int isDistinct = 1;

        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                isDistinct = 0;
                break;
            }
        }

        if (isDistinct)
        {
            printf("%d ", arr[i]);
            count++;
        }
    }
    printf("\n");

    return count;
}

int main()
{
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int distinctCount = countDistinctAndDisplay(arr, n);
    printf("Total number of distinct elements: %d\n", distinctCount);

    return 0;
}
