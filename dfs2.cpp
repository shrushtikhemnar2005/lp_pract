#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> dfsOfGraph(int V, vector<vector<int>>& adj){
    vector<int> dfsresult;
    stack<int> st;
    vector<bool> visited(V,false);
    st.push(0);
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!visited[node]){
            visited[node]=true;
            dfsresult.push_back(node);
        }
        for(auto it=adj[node].rbegin();it!=adj[node].rend();it++){
            if(!visited[*it]){
                st.push(*it);
            }
        }
    }
    return dfsresult;

}
int main(){
    int V,E;
    cout<<"enter the no of vertices:";
    cin>>V;

    vector<vector<int>> adj(V);

    cout<<"enter no of edges:";
    cin>>E;

    cout<<"enter start and end vertex:";
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans=dfsOfGraph(V,adj);

    for(int i : ans){
        cout<<i<<"";
    }
    return 0;
}