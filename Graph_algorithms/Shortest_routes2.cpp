#include<iostream>
#include<queue>
#include<climits>
// #include<algorithm>
#include<vector>
using namespace std;
 
//when storing edges in input matrix store minimum of all the input
//make diagonal 0
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<long long>>inp(n+1,vector<long long>(n+1,LLONG_MAX));
    for(int i=0;i<=n;++i){
        inp[i][i]=0;
    }
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        inp[a][b]=min(inp[a][b],(long long)c);//to check if multiple edge exist then must store the edge with minimum value
        inp[b][a]=min(inp[b][a],(long long)c);
    }
    vector<vector<int>>queries;
    while(q--){
        int a,b;
        cin>>a>>b;
        queries.push_back({a,b});
    }
    for(int i=1;i<=n;++i){//through intermediate i vertices
        for(int j=1;j<=n;++j){//row
            for(int k=1;k<=n;++k){//column
                if(inp[j][i]!=LLONG_MAX&&inp[i][k]!=LLONG_MAX) inp[j][k]=min(inp[j][k],inp[j][i]+inp[i][k]);
            }
        }
    }
    for(auto i:queries){
        int r=i[0];
        int c=i[1];
        if(inp[r][c]==LLONG_MAX) cout<<-1<<"\n";
        else cout<<inp[r][c]<<"\n";
    }
    return 0;
}
