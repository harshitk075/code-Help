/**
 Note: imp
 In the below implementation the parent of root 
 is set to root itself so when ever invalid k is there
 the answer will be root itsef (self loop in the root iteself)


 if we want to return -1 for invalid k then we can set
 parent of root as -1 and check the condition while setting 
 parent for every node, like
 
    for(int i=1;i<=LG;i++){
        if(parent[u][i-1]!=-1)
            parent[u][i]= parent[parent[u][i-1]][i-1];
        else
            break;
    }

**/

#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define mod 1000000007
#define  mfor(i,a,b)  for(int i=a;i<=b;i++)
#define p_b  push_back
#define m_p make_pair
#define all(v) v.begin(),v,end()
typedef  long long int ll;
#define sp(x) setprecision(x)
//cout<<fixed<<sp(len_of_decimal)<<ans<<endl;
int dir8[2][8]={{0,0,1,-1,1,1,-1,-1},{1,-1,0,0,1,-1,-1,1}};
int dir4[2][4]={{0,0,1,-1},{1,-1,0,0}};
const int mxn= 1e5+1;
int LG;
unordered_map<int,vector<int>> adj;
vector<vector<int>> par;
void dfs(int u, int parent)
{
    //set immediate parent as base case
    par[u][0]=parent;
    for(int i=1;i<=LG;i++)
        par[u][i]= par[par[u][i-1]][i-1];
    
    for(int v: adj[u]){
        if(v!=parent)
            dfs(v,u);
    }
}

void solve()
{
    ll n;
    cin>>n;
    adj.clear();

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    LG= ceil(log2(n));
    par.resize(n,vector<int>(LG+1,-1));

    //preprocessing
    dfs(0,0);

    int q;
    cin>>q;
    while(q--)
    {
        int u,k;
        cin>>u>>k;
        u--;
        //find the kth ancestor of u
        int res=u;
        for(int i=LG;i>=0;i--){
            if(k&(1<<i) && res!=-1)
                res= par[res][i]; 
        }

        cout<<res+1<<'\n';
    }
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