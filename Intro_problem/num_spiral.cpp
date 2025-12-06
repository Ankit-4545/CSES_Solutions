#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        long long r,c;
        cin>>r>>c;
        long long val;
        long long k=max(r,c);
        long long prev=(k-1);
        if(k%2==0){
            if(r==k){
                val=(k*k)-(c-1);
                cout<<val<<"\n";
            }
            else if(c==k){
                val=(prev*prev)+r;
                cout<<val<<"\n";
            }
        }
        else{
            if(r==k){
                val=(prev*prev)+c;
                cout<<val<<"\n";
            }
            else if(c==k){ 
                val=(k*k)-(r-1);
                cout<<val<<"\n";
            }
        }
    }
    return 0;
}