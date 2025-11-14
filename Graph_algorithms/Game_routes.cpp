#include <iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
 
int main() {
    int mod=1e9+7;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int>indegree(n+1,0);
    vector<vector<int>>adj(n+1);
    vector<long long int>ways(n+1,0);
    ways[1]=1;
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    queue<int>q;
    for(int i=1;i<=n;++i){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(auto i:adj[v]){
            ways[i]=(ways[i]+ways[v])%mod;
            indegree[i]--;
            if(indegree[i]==0) q.push(i);
        }
    }
    cout<<ways[n]%mod;
    return 0;
}
