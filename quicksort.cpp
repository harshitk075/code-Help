#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define mod 1000000007
#define  mfor(i,a,b)  for(int i=a;i<=b;i++)
#define p_b  push_back
#define m_p make_pair
#define all(v) v.begin(),v.end()
typedef  long long int ll;
#define sp(x) setprecision(x)
//cout<<fixed<<sp(len_of_decimal)<<ans<<endl;
int dir8[2][8]={{0,0,1,-1,1,1,-1,-1},{1,-1,0,0,1,-1,-1,1}};
int dir4[2][4]={{0,0,1,-1},{1,-1,0,0}};

int partition(int l, int r, vector<int> &vec)
{
    int pivot= vec[r];
    int low= l-1;

    for(int i=l;i<r;i++){
        if(vec[i]<=pivot){
            low++;
            swap(vec[low],vec[i]);
        }
    }
    swap(vec[low+1],vec[r]);
    return low+1;
}
void quicksort(int l, int r, vector<int> &vec)
{
    if(l>=r)
        return;
    
    int pidx= partition(l,r,vec);
    // for(int i=l;i<=r;i++)
    //     cout<<vec[i]<<" ";
    // cout<<'\n';
    quicksort(l,pidx-1,vec);
    quicksort(pidx+1,r,vec);
    return;
}
void solve()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++)
        cin>>vec[i];
    
    quicksort(0,n-1,vec);
    for(int ele: vec)
        cout<<ele<<" ";
    
    cout<<endl;
    return;
}
int main()
{
   SPEED
   int t=1;
   //cin>>t;
   while(t--) 
   solve();
   return 0;
}