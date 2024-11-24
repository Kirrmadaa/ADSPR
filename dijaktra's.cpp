#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph {
    int vertices;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int v) : vertices(v), adj(v) {}

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    void dijkstra(int src) {
        vector<int> dist(vertices, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto &neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        for (int i = 0; i < vertices; i++) {
            cout << "Distance from " << src << " to " << i << " is " << dist[i] << endl;
        }
    }
};

int main() {
    int vertices, edges, src;
    cin >> vertices >> edges;
    Graph g(vertices);

    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    cin >> src;
    g.dijkstra(src);
    return 0;
}
