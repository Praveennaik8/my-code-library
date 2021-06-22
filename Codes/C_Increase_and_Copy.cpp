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

signed main()
{
    //fastio
    testcase
    {
        int n;
        cin>>n;
        int x = sqrt(n)-1;
        bool flag = true;
        ll ans = INT_MAX;
        ll ans3[] ={0,1,2,2,3};
       // cout<<"yes"<<x<<endl;
       
        if(n>5)
        for(int i = x;i<=n;i++)
        {
            //cout<<"yes\n";
        
            ll y= i+(n/i) -2;
            if(i*(int)(n/i)<n)
                ++y;
            //cout<<i<<" "<<y<<endl;
            ans = min(ans,y);
            if(n/i+2 < i)
                break;
        }
         if(n<6)
        {
            ans = ans3[n-1];
        }
        cout<<ans<<"\n";

    }
}