#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii; // (weight, vertex)

int primMST(int n, vector<vector<pii>>& graph) {
    vector<bool> visited(n, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, 0}); // (weight, vertex)
    int mst_weight = 0;

    while (!pq.empty()) {
        auto [weight, u] = pq.top(); pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        mst_weight += weight;

        for (auto [v, w] : graph[u]) {
            if (!visited[v])
                pq.push({w, v});
        }
    }
    return mst_weight;
}

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<pii>> graph(n);
    cout << "Enter edges in format: u v w\n";
    for (int i = 0; i < e; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // undirected
    }

    int total_weight = primMST(n, graph);
    cout << "Minimum Spanning Tree total weight: " << total_weight << endl;
    return 0;
}
/*Enter number of vertices: 4
Enter number of edges: 5
Enter edges in format: u v w
0 1 1
0 2 4
1 2 2
1 3 6
2 3 3*/
