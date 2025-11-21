#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int v) : data(v), left(0), right(0) {}
};
Node *buildFromLevel(const vector<int> &a)
{
    if (a.empty() || a[0] == -1)
        return 0;
    queue<Node *> q;
    Node *root = new Node(a[0]);
    q.push(root);
    int i = 1;
    while (!q.empty() && i < (int)a.size())
    {
        Node *cur = q.front();
        q.pop();
        if (i < (int)a.size())
        {
            if (a[i] != -1)
            {
                cur->left = new Node(a[i]);
                q.push(cur->left);
            }
            i++;
        }
        if (i < (int)a.size())
        {
            if (a[i] != -1)
            {
                cur->right = new Node(a[i]);
                q.push(cur->right);
            }
            i++;
        }
    }
    return root;
}
bool isBSTUtil(Node *root, long long minv, long long maxv)
{
    if (!root)
        return true;
    if (root->data <= minv || root->data >= maxv)
        return false;
    return isBSTUtil(root->left, minv, root->data) && isBSTUtil(root->right, root->data, maxv);
}
int main()
{
    cout << "Enter number of elements in level-order (use -1 for null nodes): ";
    int n;
    if (!(cin >> n))
        return 0;
    vector<int> a(n);
    cout << "Enter " << n << " integers (level-order, -1 for null): ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Node *root = buildFromLevel(a);
    cout << "Is the binary tree a BST? ";
    cout << (isBSTUtil(root, LLONG_MIN, LLONG_MAX) ? "Yes\n" : "No\n");
    return 0;
}
