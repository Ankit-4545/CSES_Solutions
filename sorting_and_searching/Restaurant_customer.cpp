#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    vector<pair<int,char>>inp;
    for(int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
        inp.push_back({a,'s'});
        inp.push_back({b,'e'});
    }
    sort(inp.begin(),inp.end());
    int max_count=0;
    int num=0;
    for(auto &i:inp){
        if(i.second=='s'){
            num++;
        }
        else num--;
        max_count=max(num,max_count);
    }
    cout<<max_count<<"\n";
    return 0;
}