#include<iostream>
#include<climits>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;++i){
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
        adj[a].push_back(b);
    }
    vector<long long>dist(n+1,0);
    vector<int>parent(n+1);
    for(int i=1;i<=n;++i){
        parent[i]=i;
    }
    for(int i=1;i<n;++i){
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            int wt=i[2];
            if(dist[v]>dist[u]+wt){
                dist[v]=dist[u]+wt;
                parent[v]=u;
            }
        }
    }
    bool cycle=false;
    int x=-1;
    vector<int>res;
    for(auto i:edges){
        int u=i[0];
        int v=i[1];
        int wt=i[2];
        if(dist[v]>dist[u]+wt){
            cycle=true;
            x=v;
            break;
        }
    }
    if(!cycle){
        cout<<"NO"<<"\n";
        return 0;
    }
    cout<<"YES"<<"\n";
    for(int i=0;i<n;++i){
        x=parent[x];
    }
    int curr=x;
    res.push_back(curr);
    curr=parent[curr];
    while(curr!=x){
        res.push_back(curr);
        curr=parent[curr];
    }
    res.push_back(curr);
    reverse(res.begin(),res.end());
    for(auto i:res){
        cout<<i<<" ";
    }
    
    cout<<"\n";
    return 0;
}