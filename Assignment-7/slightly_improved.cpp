#include <iostream>
using namespace std;

void swapInt(int &x, int &y)
{
    int t = x;
    x = y;
    y = t;
}

void improvedSelectionSort(int a[], int n)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        int minIdx = left, maxIdx = left;
        for (int i = left; i <= right; i++)
        {
            if (a[i] < a[minIdx])
                minIdx = i;
            if (a[i] > a[maxIdx])
                maxIdx = i;
        }
        swapInt(a[left], a[minIdx]);
        if (maxIdx == left)
            maxIdx = minIdx;
        swapInt(a[right], a[maxIdx]);
        left++;
        right--;
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    improvedSelectionSort(arr, n);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    delete[] arr;
    return 0;
}
