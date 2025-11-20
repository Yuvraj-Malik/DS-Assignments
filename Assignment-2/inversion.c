#include <stdio.h>

// Merge two halves and count inversions
long long mergeAndCount(int arr[], int temp[], int left, int mid, int right)
{
    int i = left;    // left subarray index
    int j = mid + 1; // right subarray index
    int k = left;    // temp array index
    long long inv_count = 0;

    while ((i <= mid) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            // All remaining elements in left-subarray are greater than arr[j]
            inv_count += (mid - i + 1);
        }
    }

    // Copy remaining elements
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    // Copy back to original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

// Recursive function using merge sort
long long mergeSortAndCount(int arr[], int temp[], int left, int right)
{
    long long inv_count = 0;
    if (left < right)
    {
        int mid = (left + right) / 2;

        inv_count += mergeSortAndCount(arr, temp, left, mid);
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);

        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], temp[n];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long result = mergeSortAndCount(arr, temp, 0, n - 1);
    printf("Number of inversions: %lld\n", result);

    return 0;
}
