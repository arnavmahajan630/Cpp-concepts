#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const int INF = INT_MAX;

vector<pair<int,int>> g[N]; // adjacency list

void dijkstra(int source, int n) {

    vector<int> dist(n + 1, INF);
    vector<bool> vis(n + 1, false);

    set<pair<int,int>> pq; // (distance, node)

    dist[source] = 0;
    pq.insert({0, source});

    while (!pq.empty()) {

        auto node = *pq.begin();
        pq.erase(pq.begin());

        int u = node.second;

        if (vis[u]) continue;
        vis[u] = true;

        for (auto &child : g[u]) {
            int v = child.first;
            int wt = child.second;

            // relaxation
            if (dist[u] != INF && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                pq.insert({dist[v], v});
            }
        }
    }

    cout << "\nDijkstra's Algorithm Result:\n\n";
    cout << "Vertex\tDistance from Source\n";

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF)
            cout << i << "\tINF\n";
        else
            cout << i << "\t" << dist[i] << "\n";
    }
}

int main() {
    int n, m;

    cout << "Enter the n vertices and m edges:\n";
    cin >> n >> m;

    cout << "Enter edges (u v wt):\n";

    for (int i = 0; i < m; i++) {
        int x, y, wt;
        cin >> x >> y >> wt;

        g[x].push_back({y, wt});
        g[y].push_back({x, wt}); // undirected
    }

    int source;
    cout << "Enter the source:\n";
    cin >> source;

    dijkstra(source, n);

    return 0;
}