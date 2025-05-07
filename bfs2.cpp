#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> bfsOfGraph(int V, vector<vector<int>>& adj){
    vector<bool> visited(V,false);
    vector<int> bfsresult;
    queue<int> q;

    q.push(0);
    visited[0]=true;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfsresult.push_back(node);

        for(int neighbor : adj[node]){
            if(!visited[neighbor]){
                visited[neighbor]=true;
                q.push(neighbor);
            }
        }
    }



    return bfsresult;

}
int main()
{
    int V,E;
    cout<<"enter the no of vertices: ";
    cin>>V;

    vector<vector<int>> adj(V);
    cout<<"enter the no of Edges:";
    cin>>E;

    cout<<"enter the start and end vertex:";
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans=bfsOfGraph(V,adj);
    cout<<"path for bfs traversal:";
    for(int i : ans ){
        cout<<i<<"";
    }
    return 0;
}