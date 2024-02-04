#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void shortestPath(vector<pair<int, int>> adj[], int V, int src, int dest)
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    vector<int> path;
    for (int v = dest; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    cout << "Shortest path: ";
    for (int v : path)
        cout << v << " ";
    cout << "\nDistance: " << dist[dest] << "\n";
}

int main()
{
    int V = 5;
    vector<iPair> adj[V];

    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 3, 6);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 1, 4, 5);
    addEdge(adj, 1, 3, 8);
    addEdge(adj, 2, 4, 7);
    addEdge(adj, 3, 4, 9);

    int start, end;
    cout << "Enter the start node: ";
    cin >> start;
    cout << "Enter the end node: ";
    cin >> end;

    shortestPath(adj, V, start, end);

    return 0;
}
