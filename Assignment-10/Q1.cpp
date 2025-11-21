#include <iostream>
#include <vector>
#include <limits>
using namespace std;
int main()
{
    cout << "Graph representation\n";
    cout << "Enter number of vertices: ";
    int n;
    if (!(cin >> n))
        return 0;
    cout << "Directed? 1-Yes 2-No: ";
    int dir;
    cin >> dir;
    bool directed = (dir == 1);
    cout << "Choose representation: 1-Adjacency Matrix 2-Adjacency List: ";
    int rep;
    cin >> rep;
    if (rep == 1)
    {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        cout << "Enter number of edges: ";
        int m;
        cin >> m;
        cout << "Enter edges as: u v (0-based) [for weighted enter w after u v, else weight assumed 1]\n";
        bool weighted = false;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            if (!(cin >> u >> v))
                return 0;
            int w = 1;
            if (cin.peek() != '\n')
            {
                if (cin >> w)
                    weighted = true;
            }
            mat[u][v] = w;
            if (!directed)
                mat[v][u] = w;
        }
        cout << "Enter vertex to query degree/adjacent: ";
        int q;
        cin >> q;
        int outdeg = 0, indeg = 0;
        cout << "Adjacent vertices: ";
        for (int j = 0; j < n; j++)
        {
            if (mat[q][j] != 0)
            {
                cout << j << " ";
                outdeg++;
            }
        }
        cout << "\n";
        for (int i = 0; i < n; i++)
            if (mat[i][q] != 0)
                indeg++;
        if (directed)
            cout << "Out-degree: " << outdeg << "\nIn-degree: " << indeg << "\n";
        else
            cout << "Degree: " << outdeg << "\n";
        int edges = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] != 0)
                    edges++;
        if (!directed)
            edges /= 2;
        cout << "Number of edges: " << edges << "\n";
    }
    else
    {
        vector<vector<pair<int, int>>> adj(n);
        cout << "Enter number of edges: ";
        int m;
        cin >> m;
        cout << "Enter edges as: u v [w optional]\n";
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            int w = 1;
            if (cin.peek() != '\n')
            {
                if (cin >> w)
                {
                }
            }
            adj[u].push_back({v, w});
            if (!directed)
                adj[v].push_back({u, w});
        }
        cout << "Enter vertex to query degree/adjacent: ";
        int q;
        cin >> q;
        cout << "Adjacent vertices: ";
        for (auto &p : adj[q])
            cout << p.first << " ";
        cout << "\n";
        if (directed)
        {
            cout << "Out-degree: " << adj[q].size() << "\n";
            int indeg = 0;
            for (int i = 0; i < n; i++)
                for (auto &p : adj[i])
                    if (p.first == q)
                        indeg++;
            cout << "In-degree: " << indeg << "\n";
        }
        else
            cout << "Degree: " << adj[q].size() << "\n";
        int edges = 0;
        for (int i = 0; i < n; i++)
            edges += adj[i].size();
        if (!directed)
            edges /= 2;
        cout << "Number of edges: " << edges << "\n";
    }
    return 0;
}
