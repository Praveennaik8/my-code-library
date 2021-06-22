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
#define MOD 1000000007

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    } else {
        return a.second > b.second;
    }
}

int main()
{
    fastio
    test
    {
        ll n,a,b,c;
        cin>>n;
        vector<pair<int,int> >vp;
        int f[n+10],s[n+10],t[n+10];
        rep(i,n)
        {
            cin>>f[i];
            
        }
        rep(i,n)
        {
            cin>>s[i];
            
        }
        rep(i,n)
        {
            cin>>t[i];
            
        }
        rep(i,n)
        {
            vp.pb({f[i],s[i]*t[i]});
        }
        
        sort( vp.begin(), vp.end(),comp);
        int suffix[n+10],ans = 0;
        suffix[n] = 0;
        // rep(i,n)
        // {
        //     cout<<vp[i].first<<" "<<vp[i].second<<" , ";
        // }
        // cout<<"\n";
        for(int i = n-1;i>=0;i--)
        {
            suffix[i] = suffix[i+1]+vp[i].second;
        }
        rep(i,n-1)
        {
            //cout<<vp[i].first<<"  "<<suffix[i+1]<<"\n";
            ans+= vp[i].first * suffix[i+1];
            //ans%=MOD;
        }
        cout<<ans<<"\n";


    }
}
