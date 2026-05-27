#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    multiset<int>st;
    vector<int>res;
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        st.insert(a);
    }
    for(int i=0;i<m;++i){
        int a;
        cin>>a;
        auto it=st.upper_bound(a);
        if(it==st.begin()) res.push_back(-1);
        else{
            it--;
            res.push_back(*it);
            st.erase(it);
        }
    }
    for(auto &i:res){
        cout<<i<<"\n";
    }
    cout<<"\n";
    return 0;
}