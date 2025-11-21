#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
int main()
{
    cout << "Dijkstra's Shortest Paths\n";
    cout << "Enter number of vertices: ";
    int n;
    if (!(cin >> n))
        return 0;
    vector<vector<pair<int, int>>> adj(n);
    cout << "Enter number of edges: ";
    int m;
    cin >> m;
    cout << "Enter edges as: u v w (0-based, directed assumed). For undirected push both ways manually if needed.\n";
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    cout << "Enter source vertex: ";
    int s;
    cin >> s;
    const int INF = numeric_limits<int>::max() / 4;
    vector<int> dist(n, INF), parent(n, -1);
    dist[s] = 0;
    using P = pair<int, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto &p : adj[u])
        {
            int v = p.first, w = p.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    cout << "Vertex  Distance  Path\n";
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INF)
        {
            cout << i << "   INF   -\n";
            continue;
        }
        cout << i << "   " << dist[i] << "   ";
        vector<int> path;
        int cur = i;
        while (cur != -1)
        {
            path.push_back(cur);
            cur = parent[cur];
        }
        for (int j = path.size() - 1; j >= 0; j--)
        {
            cout << path[j];
            if (j)
                cout << "->";
        }
        cout << "\n";
    }
    return 0;
}
