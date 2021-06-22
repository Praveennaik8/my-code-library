#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define test int t;cin>>t;while(t--)
#define endl "\n"
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int highestPowerof2(int n)
{
   int p = (int)log2(n);
   return (int)pow(2, p);
}


int main()
{
    fastio
    test
    {
        ll n;
        cin>>n;
        // ll newn = 1+n;
        // int small = (newn/4)*4;
        // if(small!=0)
        //     small-=1;
        // int rem = n-small;
        // cout<<rem<<" ";
        // for(int i = n;i>small;i--)
        // {
        //     cout<<i<<" ";
        // }
        // cout<<"\n";
        int near = highestPowerof2(n);
        for(int i = near;i<=n;i++)
        {
            sum^= i;
        }
        for()
        

    }
}
