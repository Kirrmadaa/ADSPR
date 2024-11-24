#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adjMatrix;

    Graph(int V) {
        this->V = V;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    void primMST() {
        vector<int> parent(V, -1);
        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false);

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < V - 1; count++) {
            int u = -1;
            int minKey = INT_MAX;

            for (int v = 0; v < V; v++) {
                if (!inMST[v] && key[v] < minKey) {
                    u = v;
                    minKey = key[v];
                }
            }

            inMST[u] = true;

            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] != 0 && !inMST[v] && adjMatrix[u][v] < key[v]) {
                    key[v] = adjMatrix[u][v];
                    parent[v] = u;
                }
            }
        }

        printMST(parent);
    }

    void printMST(vector<int>& parent) {
        int totalCost = 0;
        cout << "Edge \tWeight\n";
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << "\t" << adjMatrix[i][parent[i]] << endl;
            totalCost += adjMatrix[i][parent[i]];
        }
        cout << "Total cost of the minimum spanning tree: " << totalCost << endl;
    }
};

int main() {
    int V, E, u, v, weight;
    
    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges in the format (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    g.primMST();

    return 0;
}
