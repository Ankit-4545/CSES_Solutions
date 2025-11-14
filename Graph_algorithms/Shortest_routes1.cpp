#include<iostream>
#include<queue>
#include<climits>
#include<vector>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<long long int>path(n+1,LLONG_MAX);
    path[1]=0;
    priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>>pq;
    pq.push({0,1});
    while(!pq.empty()){
        long long int dist=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(dist>path[node]) continue;
        for(auto i:adj[node]){
            int edge=i.first;
            long long int cost=i.second;
            if(dist+cost<path[edge]){
                path[edge]=dist+cost;
                pq.push({path[edge],edge});
            }
        }
    }
    for(int i=1;i<=n;++i){
        cout<<path[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
