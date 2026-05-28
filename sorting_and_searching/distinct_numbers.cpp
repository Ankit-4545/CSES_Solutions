// In this we just have to find the number of distinct number in the given input. This resembles the 
// propertyy of a set.
#include<iostream>
#include<set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    set<int>s;
    while(n--){
        int x;
        cin>>x;
        s.insert(x);
    }
    cout<<s.size()<<"\n";
    return 0;
}