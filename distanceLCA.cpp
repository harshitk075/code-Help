#include <bits/stdc++.h>
using namespace std;

#define SPEED  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define mod 1000000007
#define mfor(i, a, b) for (int i = a; i <= b; i++)
#define p_b push_back
#define m_p make_pair
#define all(v) v.begin(), v, end()
typedef long long int ll;
#define sp(x) setprecision(x)
//cout<<fixed<<sp(len_of_decimal)<<ans<<endl;
int dir8[2][8] = {{0, 0, 1, -1, 1, 1, -1, -1}, {1, -1, 0, 0, 1, -1, -1, 1}};
int dir4[2][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};
const int mxn = 2e5 + 1;
unordered_map<int, vector<int>> adj;
int LG;
vector<vector<int>> par;
vector<int> depth;
void dfs(int u, int parent)
{
    par[u][0] = parent;
    for (int i = 1; i <= LG; i++)
        par[u][i] = par[par[u][i - 1]][i - 1];

    for (int v : adj[u])
        if (v != parent)
        {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
}

int LCA(int u, int v)
{
    if (depth[v] > depth[u])
        swap(u, v);

    int k = depth[u] - depth[v];
    for (int i = LG; i >= 0; i--)
    {
        if (k & (1 << i))
            u = par[u][i];
    }

    if (u == v)
        return u;

    for (int i = LG; i >= 0; i--)
    {
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

void solve()
{
    ll n, q;
    cin >> n >> q;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //preprocess
    LG = ceil(log2(n));
    par.resize(n, vector<int>(LG + 1, -1));
    depth.resize(n, 0);
    dfs(0, 0);

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        //find distance between a and b
        int lca = LCA(a, b);
        int res = depth[a] + depth[b] - 2 * depth[lca];
        cout << res << '\n';
    }
}
int main()
{
    SPEED
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}