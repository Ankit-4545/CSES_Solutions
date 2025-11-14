#include <iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
 
void bfs(vector<vector<char>>&v,pair<int,int>p,vector<vector<int>>&vis,vector<vector<int>>&path,vector<vector<pair<int,int>>>&parent){
    queue<pair<int,int>>q;
    q.push(p);
    vis[p.first][p.second]=1;
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        vector<int>dir={-1,1,0,0};
        vector<int>dir1={0,0,-1,1};
        for(int i=0;i<4;++i){
            int new_r=r+dir[i];
            int new_c=c+dir1[i];
            if(new_r>=0&&new_r<v.size()&&new_c>=0&&new_c<v[0].size()&&vis[new_r][new_c]==0&&v[new_r][new_c]!='#'){
                q.push({new_r,new_c});
                vis[new_r][new_c]=1;
                path[new_r][new_c]=path[r][c]+1;
                parent[new_r][new_c]={r,c};
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<vector<int>>path(n,vector<int>(m,0));
    vector<vector<pair<int,int>>>parent(n,vector<pair<int,int>>(m));
    vector<vector<char>>v(n,vector<char>(m,'*'));
    pair<int,int>start;
    pair<int,int>end;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            char c;
            cin>>c;
            v[i][j]=c;
            if(c=='A'){
                start={i,j};
            }
            if(c=='B'){
                end={i,j};
            }
        }
    }
    parent[start.first][start.second]={-1,-1};
    
    bfs(v,start,vis,path,parent);
    if(path[end.first][end.second]==0){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        cout<<path[end.first][end.second]<<endl;
        string s="";
        if(path[end.first][end.second]!=0){
            pair<int,int>p=parent[end.first][end.second];
            pair<int,int>curr={end.first,end.second};
            while(p.first!=-1){
                if(p.first-curr.first==-1&&p.second-curr.second==0){
                    s+='D';
                }
                else if(p.first-curr.first==1&&p.second-curr.second==0){
                    s+='U';
                }
                else if(p.first-curr.first==0&&p.second-curr.second==-1){
                    s+='R';
                }
                else{
                    s+='L';
                }
                curr=p;
                p=parent[curr.first][curr.second];
            }
            reverse(s.begin(),s.end());
        }
        cout<<s<<endl;
    }
    return 0;
}