#include <stdio.h>

int findMissingNumber(int arr[], int n)
{
    int first = arr[0];
    int last = arr[n-1];

    int expected_sum = (last * (last + 1)) / 2 - ((first - 1) * first) / 2;

    int actual_sum = 0;
    for (int i = 0; i < n; i++) {
        actual_sum += arr[i];
    }

    return expected_sum - actual_sum;
}

int main()
{
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int missing = findMissingNumber(arr, size);
    printf("Missing number is: %d\n", missing);

    return 0;
}
