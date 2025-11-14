#include<iostream>
// #include<queue>
#include<vector>
// #include<stack>
#include<map>
using namespace std;
 
void dfs(vector<vector<int>>&adj,vector<int>&vis,int node){
    vis[node]=1;
    for(auto i:adj[node]){
        if(!vis[i]){
            dfs(adj,vis,i);
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<int>vis(n+1,0);
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<int>>res;
    int start=1;
    int count=0;
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            if(i!=start){
                res.push_back({start,i});
            }
            dfs(adj,vis,i);
            count++;    
        }
    }
    cout<<count-1<<endl;
    for(auto i:res){
        cout<<i[0]<<" "<<i[1]<<endl;
    }
    return 0;
}