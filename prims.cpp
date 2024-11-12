#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int primMST(int V, const vector<vector<pair<int, int>>>& adj) {
    vector<int> minWeight(V, numeric_limits<int>::max()); // Minimum weight to reach each node
    vector<bool> inMST(V, false);                         // Track nodes in MST
    minWeight[0] = 0;
    int mstCost = 0;

    for (int i = 0; i < V; ++i) {
        int u = -1;

        // Find the vertex with the minimum weight edge not in MST
        for (int v = 0; v < V; ++v) {
            if (!inMST[v] && (u == -1 || minWeight[v] < minWeight[u]))
                u = v;
        }

        inMST[u] = true;
        mstCost += minWeight[u];

        // Update minWeight for neighbors of u
        for (auto [v, weight] : adj[u]) {
            if (!inMST[v] && weight < minWeight[v]) {
                minWeight[v] = weight;
            }
        }
    }

    return mstCost;
}

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);

    // Add edges (u, v, w) where u and v are vertices, and w is the weight
    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[4].push_back({2, 7});

    cout << "Total cost of Minimum Spanning Tree: " << primMST(V, adj) << endl;
    return 0;
}
