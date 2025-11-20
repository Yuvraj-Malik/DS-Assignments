#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int v) : data(v), next(0) {}
};

// Build list from n user inputs
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

// Print list
void printList(Node *head)
{
    if (!head)
    {
        cout << "Empty\n";
        return;
    }

    Node *cur = head;
    while (cur)
    {
        cout << cur->data;
        if (cur->next)
            cout << " -> ";
        cur = cur->next;
    }
    cout << "\n";
}

// Iterative reversal (ONLY method used in Q4)
Node *reverseIterative(Node *head)
{
    Node *prev = 0;
    Node *cur = head;

    while (cur)
    {
        Node *nxt = cur->next; // store next
        cur->next = prev;      // reverse pointer
        prev = cur;            // move prev forward
        cur = nxt;             // move cur forward
    }
    return prev; // new head
}

// Free memory
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
    int n;
    cout << "Enter number of elements: ";
    if (!(cin >> n))
        return 0;

    cout << "Enter elements:\n";
    Node *head = buildList(n);

    cout << "Original list: ";
    printList(head);

    head = reverseIterative(head);

    cout << "Reversed list: ";
    printList(head);

    freeList(head);
    return 0;
}
