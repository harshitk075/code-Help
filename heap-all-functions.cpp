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
struct max_heap
{
    vector<int> A;

    //returns parent index of i
    //O(1)
    int parent(int i)
    {
        if(i==0)
            return -1;
        return (i-1)/2;
    }
    //returns left child index of i
    // O(1)
    int left_child(int i)
    {
        return 2*i+1;
    }
    //return right child index of i
    //O(1)
    int right_child(int i)
    {
        return 2*i+2;
    }
    //returns current size of heap
    // O(1)
    int size()
    {
        return A.size();
    }
    //does heapify-up on ith index element
    //recursive - O(h)--> O(logn)
    void heapify_up(int i)
    {
        //base case
        if(parent(i)==-1)
            return;
        
        if(A[i]>A[parent(i)]){
            swap(A[i],A[parent(i)]);
            heapify_up(parent(i));
        }
    }
    //does heapify-down on ith index element
    //recursively - O(h) --> O(logn)
    void heapify_down(int i)
    {
        int left= left_child(i);
        int right= right_child(i);

        int mx= i;
        if(left<size() && A[left]>A[mx])
            mx=left;
        if(right<size() && A[right]>A[mx])
            mx=right;
        
        if(mx!=i){
            swap(A[i],A[mx]);
            heapify_down(mx);
        }
    }
    //insert to heap
    // O(logn) in worst case
    //O(1) best case
    void push(int ele)
    {
        //occupy last free in A
        A.push_back(ele);
        int idx= A.size()-1;
        heapify_up(idx);
    }

    //top element from heap
    // O(1)
    int top()
    {
        if(size()==0){
            cout<<"underflow error\n";
            return -1;
        }
        else{
            return A[0];
        }
    }
    //delete/pop from heap
    // O(logn)
    void pop()
    {
        if(size()==0){
            cout<<"underflow error\n";
            return;
        }
        else{
            A[0]= A.back();
            A.pop_back();
            heapify_down(0);
        }
    }


};

void heapify_d(int i, vector<int> &vec)
{
    int left= 2*i+1;
    int right= 2*i+2;

    int mx= i;
    if(left<vec.size() && vec[left]>vec[mx])
        mx=left;
    if(right<vec.size() && vec[right]>vec[mx])
        mx=right;
    
    if(mx!=i){
        swap(vec[i],vec[mx]);
        heapify_d(mx,vec);
    }
}

void solve()
{
    // //check all the heap functions
    // max_heap temp;
    // temp.push(10);
    // temp.push(100);
    // temp.push(19);
    // temp.push(5);

    // cout<<temp.size()<<endl;
    // cout<<temp.top()<<endl;

    //heapify
    vector<int> vec={1,5,4,9,0,112,1};
    for(int i=vec.size()-1;i>=0;i--)
        heapify_d(i,vec);
    
    cout<<vec[0]<<'\n';
    return;
}
int main()
{
   SPEED
   //int t;
   //cin>>t;
   //while(t--) 
   solve();
   return 0;
}