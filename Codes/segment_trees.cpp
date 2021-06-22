#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
#define int long long
#define vi vector<int>
#define vll vector<long long>
#define testcase int t; cin>>t ;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
#define all(x) x.begin(), x.end()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define mpl map<ll,ll>
#define SIZE ll(100005)//00002)
#define FAIL -5677884
#define BIT_SIZE 35
int lazy[SIZE] ={0};

void build_tree(int arr[],int seg_tree[],int low, int high,int seg_pos)
{
    if(low == high)
    {
        seg_tree[seg_pos] = arr[low];
        return;
    }
    ll mid = (low+high)/2;

    build_tree(arr,seg_tree,low,mid,2*seg_pos+1);
    build_tree(arr,seg_tree,mid+1,high,2*seg_pos+2);

    seg_tree[seg_pos] = seg_tree[2*seg_pos+1]+seg_tree[2*seg_pos+2];
}
void update(int seg_tree[],int low, int high,int q_low,int q_high,int seg_pos )
{
    if(lazy[seg_pos]!=0)
    {
        int add =  lazy[seg_pos];
        lazy[seg_pos] = 0;
        if(low!=high)
        {
            lazy[2*seg_pos+1]+=add;
            lazy[2*seg_pos+2]+=add;
        }
        seg_tree[seg_pos ]=seg_tree[seg_pos ]+10*add;
    }
    if(q_low <= low && q_high >= high)
    {
        seg_tree[seg_pos ]+=(high-low+1)*10;
        if(low!=high)
        {
            lazy[2*seg_pos+1]++;
            lazy[2*seg_pos+2]++;
        }
        return;
    }
    if(q_low > high || q_high < low)//ql>high||qh<low
    {
        return;
    }
    ll mid = (low+high)/2;

    update(seg_tree,low,mid,q_low,q_high,2*seg_pos+1);
    update(seg_tree,mid+1,high,q_low,q_high,2*seg_pos+2);

    seg_tree[seg_pos] = seg_tree[2*seg_pos+1]+seg_tree[2*seg_pos+2];

}

int sum_query(int seg_tree[],int low,int high,int q_low,int q_high,int seg_pos)
{
    if(lazy[seg_pos]!=0)
    {
        int add =  lazy[seg_pos];
        lazy[seg_pos] = 0;
        if(low!=high)
        {
            lazy[2*seg_pos+1]+=add;
            lazy[2*seg_pos+2]+=add;
        }
        seg_tree[seg_pos ]+=(high-low+1)*10*add;
    }
    if(q_low <= low && q_high >= high)
    {
        return seg_tree[seg_pos];
    }
    if(q_low > high || q_high < low)//ql>high||qh<low
    {
        return 0;
    }
    int mid  = (low + high) /2;

    return sum_query(seg_tree,low,mid,q_low,q_high,2*seg_pos+1) + sum_query(seg_tree,mid+1,high,q_low,q_high,2*seg_pos+2);
}
signed main()
{
    //fastio
    
    int n;
    cin>>n;
    int arr[n+10];
    rep(i,n)
    {
        cin>>arr[i];
    }
    ll seg_tree[4*n];
    rep(i,4*n)
    {
        seg_tree[i] = 0;
    }
    build_tree(arr,seg_tree,0,n-1,0);//4N
    ll q;
    cin>>q;
    while(q--)
    {
        ll x,l,h;
        cin>>x>>l>>h;
        switch(x)
        {
            case 1:
                cout<<sum_query(seg_tree,0,n-1,l,h,0)<<endl;
                break;
            case 2:
                update(seg_tree,0,n-1,l,h,0);
                cout<<"updated\n";
                break;
        }
        //log(N)
    }
    
}