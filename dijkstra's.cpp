#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii; // pair (distance, vertex)

vector<int> dijkstra(int V, int src, const vector<vector<pii>>& adj) {
    vector<int> distance(V, numeric_limits<int>::max());
    distance[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq; // min-heap
    pq.push({0, src});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist > distance[u]) continue;

        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }
    return distance;
}

int main() {
    int V = 5; // number of vertices
    vector<vector<pii>> adj(V); // adjacency list

    // Add edges (u, v, w)
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});
    adj[4].push_back({3, 5});

    int src = 0; // starting node
    vector<int> distances = dijkstra(V, src, adj);

    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; ++i)
        cout << i << "\t\t" << distances[i] << "\n";

    return 0;
}
