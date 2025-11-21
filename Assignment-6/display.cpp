#include <iostream>
using namespace std;

struct CNode
{
    int data;
    CNode *next;
    CNode(int v) : data(v), next(0) {}
};

// Build a circular linked list of n nodes
CNode *build_cll(int n)
{
    CNode *tail = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        CNode *nd = new CNode(x);

        if (!tail)
        {
            nd->next = nd; // first node points to itself
            tail = nd;
        }
        else
        {
            nd->next = tail->next; // new node points to head
            tail->next = nd;       // old tail points to new node
            tail = nd;             // update tail
        }
    }
    return tail; // tail pointer is enough
}

// Display CLL starting from head and repeat head value at end
void display_cll(CNode *tail)
{
    if (!tail)
    {
        cout << "Empty\n";
        return;
    }
    CNode *head = tail->next;
    CNode *cur = head;

    do
    {
        cout << cur->data << " ";
        cur = cur->next;
    } while (cur != head);

    cout << head->data; // repeat first node value
    cout << "\n";
}

// Free circular list
void free_cll(CNode *tail)
{
    if (!tail)
        return;

    CNode *head = tail->next;
    CNode *cur = head->next;

    while (cur != head)
    {
        CNode *temp = cur;
        cur = cur->next;
        delete temp;
    }
    delete head;
}

int main()
{
    int n;
    cout << "Enter number of elements in CLL: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    CNode *tail = build_cll(n);

    cout << "Circular list (with first value repeated at end):\n";
    display_cll(tail);

    free_cll(tail);
    return 0;
}
