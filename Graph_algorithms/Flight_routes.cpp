#include<iostream>
#include<queue>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
 
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     int n,m,k;
//     cin>>n>>m>>k;
//     vector<vector<pair<int,int>>>adj(n+1);
//     while(m--){
//         int a,b,c;
//         cin>>a>>b>>c;
//         adj[a].push_back({b,c});
//     }
//     vector<vector<long long int>>path(n+1);
//     path[1].push_back(0);
//     priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>>pq;
//     pq.push({0,1});
//     while(!pq.empty()){
//         long long int dist=pq.top().first;
//         int node=pq.top().second;
//         pq.pop();
//         if(path[node].size()>k&&dist>path[node].back()) continue;
//         for(auto i:adj[node]){
//             int edge=i.first;
//             long long int cost=i.second;
//             if(path[edge].size()<k){
//                 path[edge].push_back(dist+cost);
//                 pq.push({dist+cost,edge});
//                 sort(path[edge].begin(),path[edge].end());
//             }
//             else{
//                 if(path[edge].back()>dist+cost){
//                     path[edge].pop_back();
//                     path[edge].push_back(dist+cost);
//                     pq.push({dist+cost,edge});
//                     sort(path[edge].begin(),path[edge].end());
 
//                 }
//             }
//         }
//     }
//     // sort(path[n].begin(),path[n].end());
//     for(int i=0;i<k;++i){
//         cout<<path[n][i]<<" ";
//     }
//     cout<<endl;
    
//     return 0;
// }
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<int,int>>>adj(n+1);
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<priority_queue<long long int>>path(n+1);
    path[1].push(0);
    priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>>pq;
    pq.push({0,1});
    while(!pq.empty()){
        long long int dist=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(path[node].size()==k&&dist>path[node].top()) continue;
        for(auto i:adj[node]){
            int edge=i.first;
            long long int cost=i.second;
            if(path[edge].size()<k){
                path[edge].push(dist+cost);
                pq.push({dist+cost,edge});
                // sort(path[edge].begin(),path[edge].end());
            }
            else{
                if(path[edge].top()>dist+cost){
                    path[edge].pop();
                    path[edge].push(dist+cost);
                    pq.push({dist+cost,edge});
                    // sort(path[edge].begin(),path[edge].end());
 
                }
            }
        }
    }
    vector<long long int>res;
    while(!path[n].empty()){
        res.push_back(path[n].top());
        path[n].pop();
    }
    reverse(res.begin(),res.end());
    for(int i=0;i<k;++i){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}