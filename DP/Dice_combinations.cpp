#include<iostream>
#include<vector>
using namespace std;
int mod=1e9+7;
// ind parameter is not required because the element inside the vector is already known and so is the vector.
 
//tabulation
int func(int n){
    long long int count=0;
    vector<long long int>dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=6;++j){
            if(i>=j){//I have to accumulate the value of count so that is why this line
                dp[i]=(dp[i]+dp[i-j])%mod;
            }
        }
    }
    return dp[n];    
}
 
// //memoization
// int func(int n,vector<long long int>&v){
//     long long int count=0;
//     if(n==0) return 1;
//     if(n<0) return 0;
//     if(v[n]!=-1) return v[n];
//     for(int i=1;i<=6;++i){
//         count=(count+func(n-i,v))%mod;//I have to accumulate the value of count so that is why this line
//     }
//     return v[n]=count;    
// }
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    // vector<long long int>v(n+1,-1);
    cout<<func(n)<<endl;
    return 0;
}