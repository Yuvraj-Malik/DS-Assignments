#include <iostream>
#include <climits>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int v) : data(v), left(0), right(0) {}
};
Node *insert(Node *root, int v)
{
    if (!root)
        return new Node(v);
    if (v < root->data)
        root->left = insert(root->left, v);
    else if (v > root->data)
        root->right = insert(root->right, v);
    return root;
}
Node *searchRec(Node *root, int key)
{
    if (!root || root->data == key)
        return root;
    if (key < root->data)
        return searchRec(root->left, key);
    return searchRec(root->right, key);
}
Node *searchIter(Node *root, int key)
{
    while (root)
    {
        if (root->data == key)
            return root;
        root = key < root->data ? root->left : root->right;
    }
    return 0;
}
Node *findMin(Node *root)
{
    if (!root)
        return 0;
    while (root->left)
        root = root->left;
    return root;
}
Node *findMax(Node *root)
{
    if (!root)
        return 0;
    while (root->right)
        root = root->right;
    return root;
}
Node *inorderSuccessor(Node *root, int key)
{
    Node *cur = root;
    Node *succ = 0;
    while (cur && cur->data != key)
    {
        if (key < cur->data)
        {
            succ = cur;
            cur = cur->left;
        }
        else
            cur = cur->right;
    }
    if (!cur)
        return 0;
    if (cur->right)
        return findMin(cur->right);
    return succ;
}
Node *inorderPredecessor(Node *root, int key)
{
    Node *cur = root;
    Node *pred = 0;
    while (cur && cur->data != key)
    {
        if (key > cur->data)
        {
            pred = cur;
            cur = cur->right;
        }
        else
            cur = cur->left;
    }
    if (!cur)
        return 0;
    if (cur->left)
        return findMax(cur->left);
    return pred;
}
int main()
{
    cout << "Enter number of nodes for BST: ";
    int n;
    if (!(cin >> n))
        return 0;
    Node *root = 0;
    cout << "Enter " << n << " distinct values: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    cout << "Enter key to search: ";
    int k;
    cin >> k;
    Node *r1 = searchRec(root, k);
    cout << "Recursive search result: ";
    if (r1)
        cout << r1->data << "\n";
    else
        cout << "Not found\n";
    Node *r2 = searchIter(root, k);
    cout << "Iterative search result: ";
    if (r2)
        cout << r2->data << "\n";
    else
        cout << "Not found\n";
    Node *m = findMax(root);
    cout << "Maximum in BST: ";
    if (m)
        cout << m->data << "\n";
    else
        cout << "Tree empty\n";
    Node *mi = findMin(root);
    cout << "Minimum in BST: ";
    if (mi)
        cout << mi->data << "\n";
    else
        cout << "Tree empty\n";
    Node *succ = inorderSuccessor(root, k);
    cout << "Inorder successor of " << k << ": ";
    if (succ)
        cout << succ->data << "\n";
    else
        cout << "None\n";
    Node *pred = inorderPredecessor(root, k);
    cout << "Inorder predecessor of " << k << ": ";
    if (pred)
        cout << pred->data << "\n";
    else
        cout << "None\n";
    return 0;
}
