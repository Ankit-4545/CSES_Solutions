#include<iostream>
#include<queue>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj;
    //Take additional adjacency list and make graph to detect reachable cycle from the source node
    vector<vector<int>>graph(n+1);
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        adj.push_back({a,b,c});
        graph[a].push_back(b);
    }
    //Bellman ford
    vector<long long int>path(n+1,LLONG_MIN);
    path[1]=0;
    for(int i=1;i<n;++i){
        for(auto edges:adj){
            int u=edges[0];
            int v=edges[1];
            long long int cost=edges[2];
            if(path[u]!=LLONG_MIN && path[v]<path[u]+cost){
                path[v]=path[u]+cost;
            }
        }
    }
    //in the last iteration check if the node can be further relaxed or not. if it is then the node is bad
    //means it is a part of positive cycle and will give larger number so mark it as bad
    queue<int>q;
    vector<int>bad(n+1,0);
    for(auto i:adj){
        int u=i[0];
        int v=i[1];
        long long int d=i[2];
        if(path[u]!=LLONG_MIN&&path[v]<path[u]+d){
            q.push(v);
            bad[v]=1;
        }
    }
    //check all the reachable node from badly marked node all those node will also be affected by the bad 
    //node
    while(!q.empty()){
        int n=q.front();
        q.pop();
        for(auto i:graph[n]){
            if(!bad[i]){
                bad[i]=1;
                q.push(i);
            }
        }
    }
    //check if last node marked as bad or not if so return -1 else print the maximum score to n.
    if(bad[n]) cout<<-1<<endl;
    else cout<<path[n]<<endl;
    return 0;
}