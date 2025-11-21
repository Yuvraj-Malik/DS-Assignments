#include <iostream>
using namespace std;

void swapInt(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void copyArray(int src[], int dst[], int n)
{
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

// ---------------------- a) SELECTION SORT ----------------------
void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[minIdx])
                minIdx = j;
        swapInt(a[i], a[minIdx]);
    }
}

// ---------------------- b) INSERTION SORT ----------------------
void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// ---------------------- c) BUBBLE SORT ----------------------
void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swapInt(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break; // optimization
    }
}

// ---------------------- d) MERGE SORT ----------------------
void merge(int a[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < n1)
        a[k++] = L[i++];
    while (j < n2)
        a[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSortRec(int a[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSortRec(a, l, mid);
        mergeSortRec(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

void mergeSort(int a[], int n)
{
    mergeSortRec(a, 0, n - 1);
}

// ---------------------- e) QUICK SORT ----------------------
int partitionLomuto(int a[], int l, int r)
{
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swapInt(a[i], a[j]);
        }
    }
    swapInt(a[i + 1], a[r]);
    return i + 1;
}

void quickSortRec(int a[], int l, int r)
{
    if (l < r)
    {
        int p = partitionLomuto(a, l, r);
        quickSortRec(a, l, p - 1);
        quickSortRec(a, p + 1, r);
    }
}

void quickSort(int a[], int n)
{
    quickSortRec(a, 0, n - 1);
}

// ---------------------- MAIN ----------------------
int main()
{
    int original[] = {5, 2, 8, 1, 9, 3};
    int n = sizeof(original) / sizeof(original[0]);
    int arr[50];

    cout << "Original Array: ";
    printArray(original, n);

    copyArray(original, arr, n);
    selectionSort(arr, n);
    cout << "\nSelection Sort: ";
    printArray(arr, n);

    copyArray(original, arr, n);
    insertionSort(arr, n);
    cout << "Insertion Sort: ";
    printArray(arr, n);

    copyArray(original, arr, n);
    bubbleSort(arr, n);
    cout << "Bubble Sort: ";
    printArray(arr, n);

    copyArray(original, arr, n);
    mergeSort(arr, n);
    cout << "Merge Sort: ";
    printArray(arr, n);

    copyArray(original, arr, n);
    quickSort(arr, n);
    cout << "Quick Sort: ";
    printArray(arr, n);

    return 0;
}
