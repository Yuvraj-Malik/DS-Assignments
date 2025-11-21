#include <iostream>
#include <vector>
using namespace std;
struct PriorityQueue
{
    vector<int> a;
    bool isMax;
    PriorityQueue(bool mx) : isMax(mx) {}
    bool cmp(int x, int y)
    {
        if (isMax)
            return x > y;
        return x < y;
    }
    void push(int val)
    {
        a.push_back(val);
        int i = a.size() - 1;
        while (i > 0)
        {
            int p = (i - 1) / 2;
            if (cmp(a[i], a[p]))
            {
                int t = a[i];
                a[i] = a[p];
                a[p] = t;
                i = p;
            }
            else
                break;
        }
    }
    int top()
    {
        if (a.empty())
            return INT_MIN;
        return a[0];
    }
    void pop()
    {
        if (a.empty())
            return;
        a[0] = a.back();
        a.pop_back();
        int n = a.size();
        int i = 0;
        while (true)
        {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int extrem = i;
            if (l < n && cmp(a[l], a[extrem]))
                extrem = l;
            if (r < n && cmp(a[r], a[extrem]))
                extrem = r;
            if (extrem == i)
                break;
            int t = a[i];
            a[i] = a[extrem];
            a[extrem] = t;
            i = extrem;
        }
    }
    int size() { return a.size(); }
};
int main()
{
    cout << "Priority Queue using Heap\n";
    cout << "Choose type: 1 - Max-Heap (max-priority), 2 - Min-Heap (min-priority): ";
    int t;
    if (!(cin >> t))
        return 0;
    PriorityQueue pq(t == 1);
    cout << "Enter number of initial elements: ";
    int n;
    cin >> n;
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        pq.push(v);
    }
    while (true)
    {
        cout << "Menu: 1-Push 2-Top 3-Pop 4-Size 5-Exit\n";
        cout << "Enter choice: ";
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            cout << "Enter value to push: ";
            int v;
            cin >> v;
            pq.push(v);
            cout << "Pushed " << v << "\n";
        }
        else if (ch == 2)
        {
            if (pq.size() == 0)
                cout << "Empty\n";
            else
                cout << "Top: " << pq.top() << "\n";
        }
        else if (ch == 3)
        {
            if (pq.size() == 0)
                cout << "Empty, cannot pop\n";
            else
            {
                cout << "Popped: " << pq.top() << "\n";
                pq.pop();
            }
        }
        else if (ch == 4)
        {
            cout << "Size: " << pq.size() << "\n";
        }
        else if (ch == 5)
        {
            cout << "Exiting\n";
            break;
        }
        else
            cout << "Invalid choice\n";
    }
    return 0;
}
