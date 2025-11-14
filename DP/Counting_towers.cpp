#include<iostream>
#include<vector>
using namespace std;

int main(){
    int mod=1e9+7;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    vector<vector<long long>>dp(1e6+1,vector<long long>(2,1));
    while(t--){
        int n;
        cin>>n;
        dp[n][0]=1;
        dp[n][1]=1;
        for(int i=n-1;i>0;--i){
            dp[i][0]=(4*dp[i+1][0]+dp[i+1][1])%mod;//from ith row two vertical cell trying to extend so 5 possible cases
            dp[i][1]=(2*dp[i+1][1]+dp[i+1][0])%mod;//from ith row horizontal cell trying to extend so 3 possible cases
        }
        cout<<(dp[1][0]+dp[1][1])%mod<<"\n";//Final soultion of the subproblem
    }
    return 0;
}