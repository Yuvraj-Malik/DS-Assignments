#include <iostream>
#include <vector>
using namespace std;
void heapify(vector<int> &a, int n, int i, bool isMax)
{
    int extrem = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n)
    {
        if (isMax)
        {
            if (a[l] > a[extrem])
                extrem = l;
        }
        else
        {
            if (a[l] < a[extrem])
                extrem = l;
        }
    }
    if (r < n)
    {
        if (isMax)
        {
            if (a[r] > a[extrem])
                extrem = r;
        }
        else
        {
            if (a[r] < a[extrem])
                extrem = r;
        }
    }
    if (extrem != i)
    {
        int t = a[i];
        a[i] = a[extrem];
        a[extrem] = t;
        heapify(a, n, extrem, isMax);
    }
}
void buildHeap(vector<int> &a, int n, bool isMax)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i, isMax);
}
void heapSort(vector<int> &a, bool increasing)
{
    int n = a.size();
    if (increasing)
    {
        buildHeap(a, n, true);
        for (int i = n - 1; i > 0; i--)
        {
            int t = a[0];
            a[0] = a[i];
            a[i] = t;
            heapify(a, i, 0, true);
        }
    }
    else
    {
        buildHeap(a, n, false);
        for (int i = n - 1; i > 0; i--)
        {
            int t = a[0];
            a[0] = a[i];
            a[i] = t;
            heapify(a, i, 0, false);
        }
    }
}
int main()
{
    cout << "Heapsort\n";
    cout << "Enter number of elements: ";
    int n;
    if (!(cin >> n))
        return 0;
    vector<int> a(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Choose order: 1 - Increasing, 2 - Decreasing: ";
    int choice;
    cin >> choice;
    bool inc = (choice == 1);
    heapSort(a, inc);
    if (inc)
        cout << "Sorted array (increasing): ";
    else
        cout << "Sorted array (decreasing): ";
    for (int x : a)
        cout << x << " ";
    cout << "\n";
    return 0;
}
