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
    fastio
    //testcase
    {
        int n;
        cin>>n;
        int a1,a2,a3,b1,b2,b3;
        cin>>a1>>a2>>a3>>b1>>b2>>b3;
        int ans1 = 0,ans2=INT_MAX;
        ans1 = min(a1,b2)+min(a2,b3)+min(a3,b1);
        ans2 = min(a1,abs(n-b2))+min(a2,abs(n-b3))+min(a3,abs(n-b1));
       // ans2 = min(b1,a2)+min(b2,a3)+min(b3,a1);

        cout<<(n-ans2)<<" "<<ans1<<"\n";


    }
}