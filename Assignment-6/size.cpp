#include <iostream>
using namespace std;

struct DNode
{
    int data;
    DNode *prev;
    DNode *next;
    DNode(int v) : data(v), prev(0), next(0) {}
};

struct CNode
{
    int data;
    CNode *next;
    CNode(int v) : data(v), next(0) {}
};

// Build DLL until -1
DNode *buildDLL()
{
    DNode *head = 0;
    DNode *tail = 0;
    int x;

    cout << "Enter DLL values (end with -1):\n";
    while (cin >> x && x != -1)
    {
        DNode *nd = new DNode(x);
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

// DLL size
int sizeDLL(DNode *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

// Build Circular List until -1
CNode *buildCLL()
{
    CNode *tail = 0;
    int x;

    cout << "Enter CLL values (end with -1):\n";
    while (cin >> x && x != -1)
    {
        CNode *nd = new CNode(x);
        if (!tail)
        {
            nd->next = nd; // 1 node circular
            tail = nd;
        }
        else
        {
            nd->next = tail->next;
            tail->next = nd;
            tail = nd;
        }
    }
    return tail;
}

// CLL size
int sizeCLL(CNode *tail)
{
    if (!tail)
        return 0;

    int count = 0;
    CNode *head = tail->next;
    CNode *cur = head;

    do
    {
        count++;
        cur = cur->next;
    } while (cur != head);

    return count;
}

// Free DLL
void freeDLL(DNode *head)
{
    while (head)
    {
        DNode *temp = head;
        head = head->next;
        delete temp;
    }
}

// Free CLL
void freeCLL(CNode *tail)
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
    // DLL Size
    DNode *dll = buildDLL();
    cout << "Size of DLL: " << sizeDLL(dll) << "\n";

    // CLL Size
    CNode *cll = buildCLL();
    cout << "Size of CLL: " << sizeCLL(cll) << "\n";

    // Cleanup
    freeDLL(dll);
    freeCLL(cll);

    return 0;
}
