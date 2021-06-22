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

void print(int x = 0 ,int y = 0 ,int z = 0,int k = 0,string s = "")
{
    cout<<"Reached here "<<x<<"  "<<y<<"  "<<z<<"  "<<k<<s<<"\n";
}
void prints(string s= "",int x =0)
{
    cout<<"Reached 2 here "<<x<<" "<<s<<"\n";
}
int select(int x,int a,int b,int c, int z = -9999)
{
    if(a!=x&&z!=a)
        return a;
    if(b!=x&&z!=b)
        return b;
    return c;
}
signed main()
{
    fastio
    testcase
    {
        int n;
        cin>>n;
        int ans[n+10],a[n+10],b[n+10],c[n+10];
        rep(i,n)
            cin>>a[i];
        rep(i,n)
            cin>>b[i];
        rep(i,n)
            cin>>c[i];
        ans[0] = select(-1,a[0],b[0],c[0]);
        repA(i,1,n-1)
        {
            ans[i] = select(ans[i-1],a[i],b[i],c[i]);
        }
        ans[n-1] = select(ans[n-2],a[n-1],b[n-1],c[n-1],ans[0]);
        rep(i,n)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
}