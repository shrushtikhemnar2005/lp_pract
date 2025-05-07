#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfsOfGraph(int V, vector<vector<int>>& adj) {
    vector<int> bfsResult;
    vector<bool> visited(V, false);

    queue<int> q;
    q.push(0);           // Start from node 0
    visited[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfsResult.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return bfsResult;
}

int main() {
    int V; // number of vertices
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> adj(V);
    int E; // number of edges
    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (start_vertex end_vertex):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // because it's an undirected graph
    }

    vector<int> ans = bfsOfGraph(V, adj);
    
    cout << "BFS Traversal starting from node 0: ";
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
