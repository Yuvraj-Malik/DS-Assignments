#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
int main()
{
    cout << "Prim's MST\n";
    cout << "Enter number of vertices: ";
    int n;
    if (!(cin >> n))
        return 0;
    vector<vector<pair<int, int>>> adj(n);
    cout << "Enter number of edges: ";
    int m;
    cin >> m;
    cout << "Enter edges as: u v w (0-based)\n";
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cout << "Enter start vertex: ";
    int s;
    cin >> s;
    vector<int> key(n, INT_MAX), parent(n, -1), inMST(n, 0);
    key[s] = 0;
    using P = pair<int, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        auto [kw, u] = pq.top();
        pq.pop();
        if (inMST[u])
            continue;
        inMST[u] = 1;
        for (auto &p : adj[u])
        {
            int v = p.first, w = p.second;
            if (!inMST[v] && w < key[v])
            {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }
    int total = 0;
    cout << "MST edges (u v w):\n";
    for (int i = 0; i < n; i++)
    {
        if (parent[i] != -1)
        {
            int u = parent[i];
            int v = i;
            int w = key[i];
            cout << u << " " << v << " " << w << "\n";
            total += w;
        }
    }
    cout << "Total weight: " << total << "\n";
    return 0;
}
