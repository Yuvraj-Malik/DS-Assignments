#include <iostream>
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
Node *findMin(Node *root)
{
    if (!root)
        return 0;
    while (root->left)
        root = root->left;
    return root;
}
Node *remove(Node *root, int key)
{
    if (!root)
        return 0;
    if (key < root->data)
        root->left = remove(root->left, key);
    else if (key > root->data)
        root->right = remove(root->right, key);
    else
    {
        if (!root->left)
        {
            Node *t = root->right;
            delete root;
            return t;
        }
        else if (!root->right)
        {
            Node *t = root->left;
            delete root;
            return t;
        }
        Node *t = findMin(root->right);
        root->data = t->data;
        root->right = remove(root->right, t->data);
    }
    return root;
}
int maxDepth(Node *root)
{
    if (!root)
        return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return 1 + (l > r ? l : r);
}
int minDepth(Node *root)
{
    if (!root)
        return 0;
    if (!root->left)
        return 1 + minDepth(root->right);
    if (!root->right)
        return 1 + minDepth(root->left);
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    return 1 + (l < r ? l : r);
}
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
    cout << "Enter number of deletions: ";
    int d;
    cin >> d;
    cout << "Enter " << d << " values to delete: ";
    for (int i = 0; i < d; i++)
    {
        int v;
        cin >> v;
        root = remove(root, v);
    }
    cout << "Inorder after deletions: ";
    inorder(root);
    cout << "\n";
    cout << "Max depth: " << maxDepth(root) << "\n";
    cout << "Min depth: " << minDepth(root) << "\n";
    return 0;
}
