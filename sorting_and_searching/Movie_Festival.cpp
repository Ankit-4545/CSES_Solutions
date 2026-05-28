// This problem is based on the pattern of given class interval for finding number of maximum classes we can attend
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
    vector<pair<int,int>>inp;
    for(int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
        inp.push_back({b,a});
    }
    sort(inp.begin(),inp.end());
    int num=1;
    int start=inp[0].second;
    int end=inp[0].first;
    for(int i=1;i<inp.size();++i){
        if(inp[i].second>=end){
            num++;
            start=inp[i].second;
            end=inp[i].first;
        }
    }
    cout<<num<<"\n";
    return 0;
}