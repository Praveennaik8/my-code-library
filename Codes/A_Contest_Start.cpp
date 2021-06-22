#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
#define int long long
#define vi vector<int>
#define vll vector<long long>
#define INF (ll)1e19
#define testcase int t; cin>>t ;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
#define pii pair<int,int>
#define SIZE ll(100005)//00002)
#define FAIL -5677884
#define BIT_SIZE 35
#define MOD 1000000007

void print(int x =0 ,int y =0 ,int z = 0,int k = 0,string s= "")
{
    cout<<"Reached here "<<x<<"  "<<y<<"  "<<z<<"  "<<k<<s<<"\n";
}
void prints(string s= "",int x =0)
{
    cout<<"Reached 2 here "<<x<<" "<<s<<"\n";
}

signed main()
{
    fastio
    testcase
    {
        int n,x,tt;
        cin>>n>>x>>tt;
        int heigheststart = (n-1)*x;

        int factor = tt/x;
        int ans = (n-factor)*factor;
        
        // 6 = p + t 

        // cout<<heigheststart<<endl;
        // (tt+x)*i = 2*heigheststart

        // nthstart = x*(n-1)

        // heigheststart = tt+x*(n-1);
        int nth = round(((heigheststart-tt)/(ld)x)+0.5) + 1;
        cout<<(nth)<<endl;
        
    }
}