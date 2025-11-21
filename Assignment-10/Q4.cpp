#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge
{
    int u, v, w;
};
struct DSU
{
    int n;
    vector<int> p, r;
    DSU(int n) : n(n), p(n), r(n)
    {
        for (int i = 0; i < n; i++)
            p[i] = i;
    }
    int find(int a) { return p[a] == a ? a : p[a] = find(p[a]); }
    bool uni(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (r[a] < r[b])
            swap(a, b);
        p[b] = a;
        if (r[a] == r[b])
            r[a]++;
        return true;
    }
};
int main()
{
    cout << "Kruskal's MST\n";
    cout << "Enter number of vertices: ";
    int n;
    if (!(cin >> n))
        return 0;
    cout << "Enter number of edges: ";
    int m;
    cin >> m;
    vector<Edge> edges;
    cout << "Enter edges as: u v w (0-based)\n";
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
         { return a.w < b.w; });
    DSU dsu(n);
    vector<Edge> mst;
    int total = 0;
    for (auto &e : edges)
    {
        if (dsu.uni(e.u, e.v))
        {
            mst.push_back(e);
            total += e.w;
        }
    }
    cout << "MST edges (u v w):\n";
    for (auto &e : mst)
        cout << e.u << " " << e.v << " " << e.w << "\n";
    cout << "Total weight: " << total << "\n";
    return 0;
}
