// This problem is based on Two pointer sum pattern.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,x;
    cin>>n>>x;
    long long sum=0;
    vector<int>wt(n);
    for(int i=0;i<n;++i){
        cin>>wt[i];
    }
    sort(wt.begin(),wt.end());
    int l=0,r=n-1;
    int num=0;
    while(l<r){
        if(wt[l]+wt[r]<=x){
            num++;
            l++;
        }
        r--;
    }
    int rem=n-2*num;
    cout<<num+rem<<endl;
}
