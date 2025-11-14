#include<iostream>
#include<queue>
#include<vector>
using namespace std;
 
bool bipartite(vector<int>&team,vector<int>&vis,vector<vector<int>>&adj,int node){
    queue<int>q;
    q.push(node);
    vis[node]=1;
    team[node]=1;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(auto i:adj[v]){
            if(team[i]==team[v]) return false;
            if(!vis[i]){
                q.push(i);
                vis[i]=1;
                if(team[v]==1) team[i]=2;
                else team[i]=1;
            }
        }
    }
    return true;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    while(m--){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int>vis(n+1,0);
    vector<int>team(n+1,0);
    for(int j=1;j<=n;++j){
        if(!vis[j]){
            if(!bipartite(team,vis,adj,j)){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }  
    }
    for(int i=0;i<team.size();++i){
        if(i==0) continue;
        cout<<team[i]<<" ";
    }
    cout<<endl;
    return 0;
}
