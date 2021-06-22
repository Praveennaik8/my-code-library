#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define test int t;cin>>t;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define MOD 1000000009
typedef long double ld;
typedef long long ll;


signed main()
{
    fastio
    ll dp[1000009];
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4;i<=1000000;i++)
    {
        dp[i] = (dp[i-2]%MOD+dp[i-3]%MOD)%MOD;
        //cout<<dp[i]<<endl;
    }
    test
    {
        ll x;
        cin>>x;
        cout<<dp[x]<<endl;
    }

}
