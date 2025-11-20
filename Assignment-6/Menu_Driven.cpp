#include <iostream>
using namespace std;

struct DNode
{
    int data;
    DNode *prev;
    DNode *next;
    DNode(int v) : data(v), prev(0), next(0) {}
};

// Doubly Linked List operations (non-circular)
void dll_insert_at_begin(DNode *&head, int val)
{
    DNode *n = new DNode(val);
    n->next = head;
    if (head)
        head->prev = n;
    head = n;
}

void dll_insert_at_end(DNode *&head, int val)
{
    DNode *n = new DNode(val);
    if (!head)
    {
        head = n;
        return;
    }
    DNode *cur = head;
    while (cur->next)
        cur = cur->next;
    cur->next = n;
    n->prev = cur;
}

bool dll_insert_after(DNode *&head, int target, int val)
{
    DNode *cur = head;
    while (cur)
    {
        if (cur->data == target)
        {
            DNode *n = new DNode(val);
            n->next = cur->next;
            n->prev = cur;
            if (cur->next)
                cur->next->prev = n;
            cur->next = n;
            return true;
        }
        cur = cur->next;
    }
    return false;
}

bool dll_insert_before(DNode *&head, int target, int val)
{
    DNode *cur = head;
    while (cur)
    {
        if (cur->data == target)
        {
            DNode *n = new DNode(val);
            n->next = cur;
            n->prev = cur->prev;
            cur->prev = n;
            if (n->prev)
                n->prev->next = n;
            else
                head = n;
            return true;
        }
        cur = cur->next;
    }
    return false;
}

bool dll_delete_value(DNode *&head, int val)
{
    DNode *cur = head;
    while (cur)
    {
        if (cur->data == val)
        {
            if (cur->prev)
                cur->prev->next = cur->next;
            else
                head = cur->next;
            if (cur->next)
                cur->next->prev = cur->prev;
            delete cur;
            return true;
        }
        cur = cur->next;
    }
    return false;
}

int dll_search(DNode *head, int val)
{
    int pos = 1;
    DNode *cur = head;
    while (cur)
    {
        if (cur->data == val)
            return pos;
        cur = cur->next;
        ++pos;
    }
    return -1;
}

void dll_display(DNode *head)
{
    if (!head)
    {
        cout << "DLL empty\n";
        return;
    }
    DNode *cur = head;
    while (cur)
    {
        cout << cur->data;
        if (cur->next)
            cout << " <-> ";
        cur = cur->next;
    }
    cout << '\n';
}

void dll_clear(DNode *&head)
{
    while (head)
    {
        DNode *t = head;
        head = head->next;
        delete t;
    }
}

// Circular singly linked list node
struct CNode
{
    int data;
    CNode *next;
    CNode(int v) : data(v), next(0) {}
};

// CLL operations (circular singly linked list)
void cll_insert_at_begin(CNode *&tail, int val)
{
    CNode *n = new CNode(val);
    if (!tail)
    {
        n->next = n;
        tail = n;
        return;
    }
    n->next = tail->next;
    tail->next = n;
}

void cll_insert_at_end(CNode *&tail, int val)
{
    CNode *n = new CNode(val);
    if (!tail)
    {
        n->next = n;
        tail = n;
        return;
    }
    n->next = tail->next;
    tail->next = n;
    tail = n;
}

bool cll_insert_after(CNode *&tail, int target, int val)
{
    if (!tail)
        return false;
    CNode *cur = tail->next;
    do
    {
        if (cur->data == target)
        {
            CNode *n = new CNode(val);
            n->next = cur->next;
            cur->next = n;
            if (cur == tail)
                tail = n;
            return true;
        }
        cur = cur->next;
    } while (cur != tail->next);
    return false;
}

bool cll_insert_before(CNode *&tail, int target, int val)
{
    if (!tail)
        return false;
    CNode *prev = tail;
    CNode *cur = tail->next;
    do
    {
        if (cur->data == target)
        {
            CNode *n = new CNode(val);
            n->next = cur;
            prev->next = n;
            if (cur == tail->next)
            {
                // inserted before head; tail->next should point to new head
                // already handled by prev->next = n (prev initially tail)
            }
            return true;
        }
        prev = cur;
        cur = cur->next;
    } while (cur != tail->next);
    return false;
}

bool cll_delete_value(CNode *&tail, int val)
{
    if (!tail)
        return false;
    CNode *prev = tail;
    CNode *cur = tail->next;
    do
    {
        if (cur->data == val)
        {
            if (cur == prev)
            { // only one node
                delete cur;
                tail = 0;
                return true;
            }
            prev->next = cur->next;
            if (cur == tail)
                tail = prev;
            delete cur;
            return true;
        }
        prev = cur;
        cur = cur->next;
    } while (cur != tail->next);
    return false;
}

int cll_search(CNode *tail, int val)
{
    if (!tail)
        return -1;
    CNode *cur = tail->next;
    int pos = 1;
    do
    {
        if (cur->data == val)
            return pos;
        cur = cur->next;
        ++pos;
    } while (cur != tail->next);
    return -1;
}

void cll_display(CNode *tail)
{
    if (!tail)
    {
        cout << "CLL empty\n";
        return;
    }
    CNode *cur = tail->next;
    do
    {
        cout << cur->data << ' ';
        cur = cur->next;
    } while (cur != tail->next);
    cout << cur->data << '\n'; // repeat head at end per assignment (shows head again)
}

void cll_clear(CNode *&tail)
{
    if (!tail)
        return;
    CNode *head = tail->next;
    CNode *cur = head->next;
    while (cur != head)
    {
        CNode *tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    delete head;
    tail = 0;
}

void print_main_menu()
{
    cout << "\n--- Main Menu ---\n";
    cout << "1. Operate on Doubly Linked List (DLL)\n";
    cout << "2. Operate on Circular Linked List (CLL)\n";
    cout << "0. Exit\n";
    cout << "Choice: ";
}

void print_dll_menu()
{
    cout << "\n-- DLL Menu --\n";
    cout << "1 Insert at beginning\n2 Insert at end\n3 Insert after value\n4 Insert before value\n5 Delete value\n6 Search\n7 Display\n8 Clear\n0 Back\nChoice: ";
}

void print_cll_menu()
{
    cout << "\n-- CLL Menu --\n";
    cout << "1 Insert at beginning\n2 Insert at end\n3 Insert after value\n4 Insert before value\n5 Delete value\n6 Search\n7 Display (repeat head at end)\n8 Clear\n0 Back\nChoice: ";
}

int main()
{
    DNode *dll_head = 0;
    CNode *cll_tail = 0; // tail pointer for easier insert at end
    int main_choice;
    while (true)
    {
        print_main_menu();
        if (!(cin >> main_choice))
            break;
        if (main_choice == 0)
            break;
        if (main_choice == 1)
        {
            int ch;
            while (true)
            {
                print_dll_menu();
                if (!(cin >> ch))
                    return 0;
                if (ch == 0)
                    break;
                int v, t;
                bool ok;
                switch (ch)
                {
                case 1:
                    cout << "Value: ";
                    cin >> v;
                    dll_insert_at_begin(dll_head, v);
                    break;
                case 2:
                    cout << "Value: ";
                    cin >> v;
                    dll_insert_at_end(dll_head, v);
                    break;
                case 3:
                    cout << "Target: ";
                    cin >> t;
                    cout << "Value: ";
                    cin >> v;
                    ok = dll_insert_after(dll_head, t, v);
                    cout << (ok ? "Inserted after\n" : "Target not found\n");
                    break;
                case 4:
                    cout << "Target: ";
                    cin >> t;
                    cout << "Value: ";
                    cin >> v;
                    ok = dll_insert_before(dll_head, t, v);
                    cout << (ok ? "Inserted before\n" : "Target not found\n");
                    break;
                case 5:
                    cout << "Value to delete: ";
                    cin >> v;
                    cout << (dll_delete_value(dll_head, v) ? "Deleted\n" : "Not found\n");
                    break;
                case 6:
                    cout << "Search value: ";
                    cin >> v;
                    {
                        int pos = dll_search(dll_head, v);
                        if (pos == -1)
                            cout << "Not found\n";
                        else
                            cout << "Found at position " << pos << '\n';
                    }
                    break;
                case 7:
                    dll_display(dll_head);
                    break;
                case 8:
                    dll_clear(dll_head);
                    cout << "DLL cleared\n";
                    break;
                default:
                    cout << "Invalid\n";
                }
            }
        }
        else if (main_choice == 2)
        {
            int ch;
            while (true)
            {
                print_cll_menu();
                if (!(cin >> ch))
                    return 0;
                if (ch == 0)
                    break;
                int v, t;
                bool ok;
                switch (ch)
                {
                case 1:
                    cout << "Value: ";
                    cin >> v;
                    cll_insert_at_begin(cll_tail, v);
                    break;
                case 2:
                    cout << "Value: ";
                    cin >> v;
                    cll_insert_at_end(cll_tail, v);
                    break;
                case 3:
                    cout << "Target: ";
                    cin >> t;
                    cout << "Value: ";
                    cin >> v;
                    ok = cll_insert_after(cll_tail, t, v);
                    cout << (ok ? "Inserted after\n" : "Target not found\n");
                    break;
                case 4:
                    cout << "Target: ";
                    cin >> t;
                    cout << "Value: ";
                    cin >> v;
                    ok = cll_insert_before(cll_tail, t, v);
                    cout << (ok ? "Inserted before\n" : "Target not found\n");
                    break;
                case 5:
                    cout << "Value to delete: ";
                    cin >> v;
                    cout << (cll_delete_value(cll_tail, v) ? "Deleted\n" : "Not found\n");
                    break;
                case 6:
                    cout << "Search value: ";
                    cin >> v;
                    {
                        int pos = cll_search(cll_tail, v);
                        if (pos == -1)
                            cout << "Not found\n";
                        else
                            cout << "Found at position " << pos << '\n';
                    }
                    break;
                case 7:
                    cll_display(cll_tail);
                    break;
                case 8:
                    cll_clear(cll_tail);
                    cout << "CLL cleared\n";
                    break;
                default:
                    cout << "Invalid\n";
                }
            }
        }
        else
        {
            cout << "Invalid\n";
        }
    }
    // cleanup
    dll_clear(dll_head);
    cll_clear(cll_tail);
    return 0;
}
