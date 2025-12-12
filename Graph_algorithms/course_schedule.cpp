#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<int>course;
    vector<int>indegree(n+1,0);
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    queue<int>q;
    for(int i=1;i<=n;++i){
        if(indegree[i]==0){
            q.push(i);
            course.push_back(i);
        }
    }
    while(!q.empty()){
        int c=q.front();
        q.pop();
        for(auto i:adj[c]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
                course.push_back(i);
            }
        }
    }
    for(auto i:indegree){
        if(i!=0){
            cout<<"IMPOSSIBLE"<<"\n";
            return 0;
        }
    }
    for(auto x:course){
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}