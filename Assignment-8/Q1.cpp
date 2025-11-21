#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int v) : data(v), left(0), right(0) {}
};

Node *insertBST(Node *root, int v)
{
    if (!root)
        return new Node(v);
    if (v < root->data)
        root->left = insertBST(root->left, v);
    else
        root->right = insertBST(root->right, v);
    return root;
}

void preorder(Node *r)
{
    if (!r)
        return;
    cout << r->data << " ";
    preorder(r->left);
    preorder(r->right);
}

void inorder(Node *r)
{
    if (!r)
        return;
    inorder(r->left);
    cout << r->data << " ";
    inorder(r->right);
}

void postorder(Node *r)
{
    if (!r)
        return;
    postorder(r->left);
    postorder(r->right);
    cout << r->data << " ";
}

int main()
{
    cout << "Enter number of nodes: ";
    int n;
    if (!(cin >> n))
        return 0;

    Node *root = 0;

    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        root = insertBST(root, x);
    }

    cout << "Preorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << "\n";
    return 0;
}
