#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int v) : val(v), next(0) {}
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

int countOccurrences(Node *head, int key)
{
    int c = 0;
    Node *cur = head;
    while (cur)
    {
        if (cur->val == key)
            ++c;
        cur = cur->next;
    }
    return c;
}

Node *deleteAllOccurrences(Node *head, int key)
{
    Node dummy(0);
    dummy.next = head;
    Node *prev = &dummy;
    Node *cur = head;
    while (cur)
    {
        if (cur->val == key)
        {
            prev->next = cur->next;
            delete cur;
            cur = prev->next;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return dummy.next;
}

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
        cout << cur->val;
        if (cur->next)
            cout << " -> ";
        cur = cur->next;
    }
    cout << '\n';
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
    int n;
    cout << "Enter number of elements: ";
    if (!(cin >> n))
        return 0;
    cout << "Enter elements separated by spaces/newlines:\n";
    Node *head = buildList(n);
    cout << "Enter key to count and delete: ";
    int key;
    cin >> key;
    cout << "Original list: ";
    printList(head);
    int cnt = countOccurrences(head, key);
    cout << "Occurrences of " << key << ": " << cnt << '\n';
    if (cnt > 0)
    {
        head = deleteAllOccurrences(head, key);
        cout << "List after deleting all occurrences of " << key << ": ";
        printList(head);
    }
    else
    {
        cout << "No deletions performed.\n";
    }
    freeList(head);
    return 0;
}
