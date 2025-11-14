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
    for(int i=0;i<m;++i){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    //In the priority queue i will store{dist,{node,coupon_used_flag}}
    //So for every node there will be two value pushed into the priority queue one is for used coupon and one is for unused coupon
    priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,pair<int,int>>>,greater<pair<long long,pair<int,int>>>>pq;
    //Same i will take n*2 vector to store and update both the distance dynamically on using coupon and not using it
    //0- means unused coupon
    //1- means used coupon
    vector<vector<long long>>dist(n+1,vector<long long>(2,LLONG_MAX));
    dist[1][0]=0;
    pq.push({0,{1,0}});
    while(!pq.empty()){
        long long far=pq.top().first;
        int node=pq.top().second.first;
        int flag=pq.top().second.second;
        pq.pop();
        if(far!=dist[node][flag]) continue; //this line is used to skip outdated entries because we are entering multiple
        //values for a node for used coupon and unused coupon used to avoid entries like {10,{1,1}} when {7,{1,1}} already
        //processed ">" symbol cant be used here because
        for(auto i:adj[node]){
            int neighbour=i.first;
            int weight=i.second;
            if(flag==0){
                if(dist[neighbour][1]>far+weight/2){
                    dist[neighbour][1]=far+weight/2;
                    pq.push({far+weight/2,{neighbour,1}});
                }
                if(dist[neighbour][0]>far+weight){
                    dist[neighbour][0]=far+weight;
                    pq.push({far+weight,{neighbour,0}});
                }
            }
            else{
                if(dist[neighbour][1]>far+weight){//after coupon used change the state of used coupon for node
                    dist[neighbour][1]=far+weight;
                    pq.push({far+weight,{neighbour,1}});
                }

            }
        }
    }
    cout<<dist[n][1]<<"\n";
    return 0;
}