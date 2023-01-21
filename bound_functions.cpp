#include<bits/stdc++.h>
using namespace std;


void solve()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++)
        cin>>vec[i];
    
    int num;
    cin>>num;
    //lower bound
    int l=0,r=n-1;
    int ans=n;
    while(l<=r){
        int mid= l+(r-l)/2;

        if(vec[mid]<=num)
            l=mid+1;
        
        else{
            ans= mid;
            r=mid-1;
        }
    }
    cout<<ans<<endl;
    return;
}

int main()
{
    solve();
    return 0;
}