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
vector<int> depth;
void dfs(int u, int parent)
{
    //set immediate parent as base case
    par[u][0]=parent;
    for(int i=1;i<=LG;i++){
		if(par[u][i-1]!=-1)
			par[u][i]= par[par[u][i-1]][i-1];
		else
			break;
	}
    
    for(int v: adj[u]){
        depth[v]= depth[u]+1;
        dfs(v,u);
    }
}

void solve()
{
    ll n,q;
    cin>>n>>q;

    adj.clear();

    for(int i=1;i<=n-1;i++){
        int boss;
		cin>>boss;
		boss--;
        adj[boss].push_back(i);
    }

    LG= ceil(log2(n));
    par.resize(n,vector<int>(LG+1,-1));
    depth.resize(n,0);
    //preprocessing
    dfs(0,-1);
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        u--;v--;

        //bring u and v to the same level (assume u is lower then v)
        if(depth[v]>depth[u])
            swap(u,v);
        
        int k= depth[u]-depth[v];
        for(int i=LG;i>=0;i--){
            if(k&(1<<i))
                u= par[u][i];
        }

        //edge case when after bringin them to same level they are at LCA
        if(u==v){
            cout<<u+1<<'\n';
            continue;
        }
        //find the Lca of u and v
        //now make binary jumps
        for(int i=LG;i>=0;i--){
            if(par[u][i]!=par[v][i]){
                u= par[u][i];
                v= par[v][i];
            }
        }
        cout<<par[u][0]+1<<'\n';
    }
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