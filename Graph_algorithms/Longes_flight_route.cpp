#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
 
void dfs(vector<vector<int>>&adj,int node,vector<int>&vis,stack<int>&st){
    vis[node]=1;
    for(auto i:adj[node]){
        if(!vis[i]){
            dfs(adj,i,vis,st);
        }
    }
    st.push(node);
}
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<int>vis(n+1,0);
    vector<int>path(n+1,-1);
    path[1]=0;
    vector<int>parent(n+1,-1);
    stack<int>st;
    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            dfs(adj,i,vis,st);
        }
    }
    while(!st.empty()){
        int x=st.top();
        st.pop();
        if(path[x]!=-1){
            for(int i:adj[x]){
                if(path[i]<path[x]+1){
                    path[i]=path[x]+1;
                    parent[i]=x;
                }
            }
        }
    }
    
    if(parent[n]==-1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<path[n]+1<<endl;
        st.push(n);
        int j=n;
        while(parent[j]!=-1){
            st.push(parent[j]);
            j=parent[j];
        }
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<endl;
        // cout<<path[n]+1<<endl;
    }
    return 0;
}