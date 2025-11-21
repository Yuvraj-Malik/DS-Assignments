// q5_check_cll.cpp
// Program to CHECK if a linked list is circular or not (DO NOT CREATE IT)
// Uses only <iostream>

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int v) : data(v), next(0) {}
};

// Build a normal singly linked list (as given by user)
Node *build_list(int n)
{
    Node *head = 0;
    Node *tail = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        Node *nd = new Node(x);
        if (!head)
        {
            head = tail = nd;
        }
        else
        {
            tail->next = nd;
            tail = nd;
        }
    }

    return head;
}

// CHECK if list is circular
bool isCircular(Node *head)
{
    if (!head)
        return false;

    Node *cur = head->next;

    // Move until NULL or back to head
    while (cur && cur != head)
    {
        cur = cur->next;
    }

    return (cur == head); // true if looped back to head
}

// Free list (safe only if NOT circular)
void free_list(Node *head)
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    Node *head = build_list(n);

    // DO NOT create cycle, DO NOT modify list
    // Just check what the user input actually is

    if (isCircular(head))
        cout << "The linked list IS circular.\n";
    else
        cout << "The linked list is NOT circular.\n";

    // Free only if not circular — otherwise it will loop forever
    if (!isCircular(head))
        free_list(head);

    return 0;
}
