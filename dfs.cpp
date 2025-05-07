#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dfsOfGraph(int V, vector<vector<int>>& adj) {
    vector<int> dfsResult;
    vector<bool> visited(V, false);
    stack<int> st;

    st.push(0); // Start DFS from node 0

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            visited[node] = true;
            dfsResult.push_back(node);

            // Push adjacent nodes into stack
            // To maintain correct DFS order, you may want to reverse adj[node]
            for (auto it = adj[node].rbegin(); it != adj[node].rend(); ++it) {
                if (!visited[*it]) {
                    st.push(*it);
                }
            }
        }
    }

    return dfsResult;
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
        adj[v].push_back(u); // Undirected graph
    }

    vector<int> ans = dfsOfGraph(V, adj);

    cout << "DFS Traversal using Stack starting from node 0: ";
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
