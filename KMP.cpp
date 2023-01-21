
// KMP pattern seach code
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

void solve()
{
    string text;
    string pattern;
    cin>>text;
    cin>>pattern;
    int n= text.length();
    int m= pattern.length();
    //prepare a LIS (longest proper prefix suffix)
    int LIS[m]{0};
    int j=0;

    //STEP 1
    for(int i=1;i<n;i++){
        if(pattern[i]==pattern[j]){
            LIS[i]= j+1;
            i++;
            j++;
        }
        else{
            if(j!=0)
                j= LIS[j-1];
            else
                i++;
        }
    }

    //step 2:
    int it=0; //idx of text
    int ip=0; //idx of pattern
    while(it<n){
        if(text[it]==pattern[ip]){
            it++;
            ip++;
        }

        if(ip==m){
            cout<<"Pattern found at: "<<it-ip<<endl;
            ip= LIS[ip-1];
        }

        else if(it<n && text[it]!= pattern[ip]){
            if(ip>0)
                ip= LIS[ip-1];
            else
                it++;
        }
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

