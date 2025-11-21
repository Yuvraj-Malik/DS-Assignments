#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    cout << "Breadth First Search (BFS)\n";
    cout << "Enter number of vertices: ";
    int n;
    if (!(cin >> n))
        return 0;
    vector<vector<int>> adj(n);
    cout << "Enter number of edges: ";
    int m;
    cin >> m;
    cout << "Enter edges (u v) 0-based: ";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "Enter start vertex: ";
    int s;
    cin >> s;
    vector<int> vis(n, 0);
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    cout << "BFS order: ";
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u])
            if (!vis[v])
            {
                vis[v] = 1;
                q.push(v);
            }
    }
    cout << "\n";
    return 0;
}
