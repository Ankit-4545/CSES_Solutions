#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>applicant_size(n);
    vector<int>each_apartment_size(m);
    for(int i=0;i<n;++i){
        cin>>applicant_size[i];
    }
    for(int i=0;i<m;++i){
        cin>>each_apartment_size[i];
    }
    sort(applicant_size.begin(),applicant_size.end());
    sort(each_apartment_size.begin(),each_apartment_size.end());
    int count=0;
    int x=0,y=0;
    while (x<n&&y<m)
    {
        long long min_desired=applicant_size[x]-k;
        long long max_desired=applicant_size[x]+k;
        if(each_apartment_size[y]>max_desired){
            x++;
        }
        else if(each_apartment_size[y]<min_desired){
            y++;
        }
        else{
            count++;
            x++;
            y++;
        }
    }
    cout<<count<<endl;   
}