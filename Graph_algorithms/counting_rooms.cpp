#include <iostream>
#include<vector>
using namespace std;
 
void dfs(vector<vector<char>>&v,int row,int col){
    v[row][col]='#';
    vector<int>dir={-1,1,0,0};
    vector<int>dir1={0,0,1,-1};
    for(int i=0;i<4;++i){
        int new_r=row+dir[i];
        int new_c=col+dir1[i];
        if(new_r>=0&&new_r<v.size()&&new_c>=0&&new_c<v[0].size()&&v[new_r][new_c]=='.'){
            dfs(v,new_r,new_c);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>init;
    vector<vector<char>>v(n,vector<char>(m,'*'));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            char c;
            cin>>c;
            v[i][j]=c;
            pair<int,int>p;
            if(c=='.'){
                p={i,j};
                init.push_back(p);
            }
        }
    }
    int count=0;
    for(int i=0;i<init.size();++i){
        int row=init[i].first;
        int col=init[i].second;
        if(v[row][col]=='.'){
            count++;
            dfs(v,row,col);
        }
    }
    cout<<count<<endl;
    return 0;
}