#include <iostream>
using namespace std;

struct Node
{
    int v;
    Node *next;
    Node(int x) : v(x), next(0) {}
};

Node *buildList(int n)
{
    Node *head = 0;
    Node *tail = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        Node *nd = new Node(x);
        if (!head)
            head = tail = nd;
        else
        {
            tail->next = nd;
            tail = nd;
        }
    }
    return head;
}

int middleFastSlow(Node *head)
{
    if (!head)
        return -2147483648; // sentinel for empty
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow points to middle (second middle if even length)
    return slow->v;
}

int middleArrayMethod(Node *head)
{
    // First count nodes
    int n = 0;
    Node *cur = head;
    while (cur)
    {
        ++n;
        cur = cur->next;
    }
    if (n == 0)
        return -2147483648;
    // allocate plain array
    int *arr = new int[n];
    cur = head;
    int idx = 0;
    while (cur)
    {
        arr[idx++] = cur->v;
        cur = cur->next;
    }
    // Choose first middle for even lengths: index (n-1)/2
    int mid = arr[(n - 1) / 2];
    delete[] arr;
    return mid;
}

void freeList(Node *head)
{
    while (head)
    {
        Node *t = head;
        head = head->next;
        delete t;
    }
}

int main()
{
    cout << "Enter number of elements: ";
    int n;
    if (!(cin >> n))
        return 0;
    cout << "Enter elements:\n";
    Node *head = buildList(n);
    cout << "Choose method (1=fast/slow [second-middle if even], 2=array-based [first-middle if even]): ";
    int ch;
    cin >> ch;
    if (ch == 1)
    {
        int res = middleFastSlow(head);
        if (res == -2147483648)
            cout << "List empty\n";
        else
            cout << "Middle: " << res << '\n';
    }
    else
    {
        int res = middleArrayMethod(head);
        if (res == -2147483648)
            cout << "List empty\n";
        else
            cout << "Middle: " << res << '\n';
    }
    freeList(head);
    return 0;
}
