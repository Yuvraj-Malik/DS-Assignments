// q1_procedural_sll.cpp
// Procedural single linked list with menu (global head + functions)
// Uses only <iostream>

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int v) : data(v), next(0) {}
};

Node *head = 0;

void insertAtBeginning(int x)
{
    Node *n = new Node(x);
    n->next = head;
    head = n;
}

void insertAtEnd(int x)
{
    Node *n = new Node(x);
    if (!head)
    {
        head = n;
        return;
    }
    Node *cur = head;
    while (cur->next)
        cur = cur->next;
    cur->next = n;
}

bool insertBeforeValue(int target, int x)
{
    if (!head)
        return false;
    if (head->data == target)
    {
        insertAtBeginning(x);
        return true;
    }
    Node *prev = head;
    Node *cur = head->next;
    while (cur && cur->data != target)
    {
        prev = cur;
        cur = cur->next;
    }
    if (!cur)
        return false;
    Node *n = new Node(x);
    prev->next = n;
    n->next = cur;
    return true;
}

bool insertAfterValue(int target, int x)
{
    Node *cur = head;
    while (cur)
    {
        if (cur->data == target)
        {
            Node *n = new Node(x);
            n->next = cur->next;
            cur->next = n;
            return true;
        }
        cur = cur->next;
    }
    return false;
}

bool deleteFromBeginning()
{
    if (!head)
        return false;
    Node *tmp = head;
    head = head->next;
    delete tmp;
    return true;
}

bool deleteFromEnd()
{
    if (!head)
        return false;
    if (!head->next)
    {
        delete head;
        head = 0;
        return true;
    }
    Node *prev = 0;
    Node *cur = head;
    while (cur->next)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = 0;
    delete cur;
    return true;
}

bool deleteValue(int val)
{
    if (!head)
        return false;
    if (head->data == val)
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
        return true;
    }
    Node *prev = head;
    Node *cur = head->next;
    while (cur)
    {
        if (cur->data == val)
        {
            prev->next = cur->next;
            delete cur;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

int search(int val)
{
    Node *cur = head;
    int pos = 1;
    while (cur)
    {
        if (cur->data == val)
            return pos;
        cur = cur->next;
        ++pos;
    }
    return -1;
}

void display()
{
    if (!head)
    {
        cout << "List is empty\n";
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
    cout << '\n';
}

void clearList()
{
    while (head)
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
}

void printMenu()
{
    cout << "\n--- Menu ---\n";
    cout << "1 Insert at beginning\n2 Insert at end\n3 Insert before a value\n4 Insert after a value\n";
    cout << "5 Delete from beginning\n6 Delete from end\n7 Delete a value (first occ.)\n8 Search\n9 Display\n10 Clear list\n0 Exit\nChoice: ";
}

int main()
{
    int choice;
    while (true)
    {
        printMenu();
        if (!(cin >> choice))
            break;
        if (choice == 0)
            break;
        int x, t;
        bool ok;
        switch (choice)
        {
        case 1:
            cout << "Value: ";
            cin >> x;
            insertAtBeginning(x);
            break;
        case 2:
            cout << "Value: ";
            cin >> x;
            insertAtEnd(x);
            break;
        case 3:
            cout << "Insert before which value? ";
            cin >> t;
            cout << "New value: ";
            cin >> x;
            ok = insertBeforeValue(t, x);
            cout << (ok ? "Inserted\n" : "Target not found\n");
            break;
        case 4:
            cout << "Insert after which value? ";
            cin >> t;
            cout << "New value: ";
            cin >> x;
            ok = insertAfterValue(t, x);
            cout << (ok ? "Inserted\n" : "Target not found\n");
            break;
        case 5:
            cout << (deleteFromBeginning() ? "Deleted from beginning\n" : "List empty\n");
            break;
        case 6:
            cout << (deleteFromEnd() ? "Deleted from end\n" : "List empty\n");
            break;
        case 7:
            cout << "Value to delete: ";
            cin >> x;
            cout << (deleteValue(x) ? "Deleted\n" : "Not found\n");
            break;
        case 8:
            cout << "Search value: ";
            cin >> x;
            {
                int p = search(x);
                if (p == -1)
                {
                    cout << "Not found\n";
                }
                else
                {
                    cout << "Found at position " << p << "\n";
                }
            }
            break;
        case 9:
            display();
            break;
        case 10:
            clearList();
            cout << "List cleared\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    }
    clearList();
    return 0;
}
