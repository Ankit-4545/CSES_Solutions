#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<int>dist(n+1,0);
    vector<int>vis(n+1,0);
    vector<int>parent(n+1,-1);
    vector<int>res;
    queue<pair<int,int>>q;
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    q.push({1,0});
    vis[1]=1;
    while(!q.empty()){
        int node=q.front().first;
        int d=q.front().second;
        q.pop();
        for(auto i:adj[node]){
            if(!vis[i]){
                q.push({i,d+1});
                vis[i]=1;
                parent[i]=node;
                dist[i]=d+1;
            }
        }
    }
    if(vis[n]==0){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<dist[n]+1<<endl;
        int x=n;
        while(x!=-1){
            res.push_back(x);
            x=parent[x];
        }
        reverse(res.begin(),res.end());
        for(auto j:res){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}