#include <iostream>
using namespace std;

struct DNode
{
    char data;
    DNode *prev;
    DNode *next;
    DNode(char c) : data(c), prev(0), next(0) {}
};

DNode *build_dll_chars(int n)
{
    DNode *head = 0;
    DNode *tail = 0;
    for (int i = 0; i < n; ++i)
    {
        char c;
        cin >> c;
        DNode *nd = new DNode(c);
        if (!head)
            head = tail = nd;
        else
        {
            tail->next = nd;
            nd->prev = tail;
            tail = nd;
        }
    }
    return head;
}

bool is_palindrome(DNode *head)
{
    if (!head)
        return true;
    DNode *tail = head;
    while (tail->next)
        tail = tail->next;
    DNode *l = head;
    DNode *r = tail;
    while (l != r && l->prev != r)
    {
        if (l->data != r->data)
            return false;
        l = l->next;
        r = r->prev;
    }
    return true;
}

void free_dll(DNode *head)
{
    while (head)
    {
        DNode *t = head;
        head = head->next;
        delete t;
    }
}

int main()
{
    cout << "Enter number of characters: ";
    int n;
    if (!(cin >> n))
        return 0;
    if (n > 0)
        cout << "Enter characters (no spaces required; separated by space or newline):\n";
    DNode *head = build_dll_chars(n);
    cout << (is_palindrome(head) ? "Palindrome\n" : "Not Palindrome\n");
    free_dll(head);
    return 0;
}
