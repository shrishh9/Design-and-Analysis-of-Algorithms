#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) const {
        return weight < other.weight;
    }
};

// Find and Union functions for Union-Find structure
int find(int v, vector<int>& parent) {
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v], parent); // Path compression
}

void unite(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = find(a, parent);
    b = find(b, parent);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

int kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; ++i)
        parent[i] = i;

    int mstCost = 0;
    for (Edge e : edges) {
        if (find(e.u, parent) != find(e.v, parent)) {
            mstCost += e.weight;
            unite(e.u, e.v, parent, rank);
        }
    }

    return mstCost;
}

int main() {
    int V = 5;
    vector<Edge> edges = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {2, 4, 7}, {1, 4, 5}, {3, 4, 9}
    };

    cout << "Total cost of Minimum Spanning Tree: " << kruskalMST(V, edges) << endl;
    return 0;
}
