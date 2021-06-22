#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define test int t;cin>>t;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define MOD 1000000007
typedef long double ld;
typedef long long ll;
#define mp map<ll,ll>


signed main()
{
    fastio
    ll n,k;
    cin>>n>>k;
    ll arr[n+10];
    mp mp1;
    vll diff;
    for(ll i = 0;i<n;i++)
    {
        cin>>arr[i];
        
        if(!mp1[arr[i]])
           diff.push_back(arr[i]);
        mp1[arr[i]]++;

    }
    // cout<<"hi 1 "<<endl;
    n = diff.size();
    int dp[n+10][k+10];
    k = min(k,(ll)diff.size());
    for(int i = 0;i<=k;i++)
        dp[0][i] = 0;
    // cout<<"hi 2"<<endl;
    dp[0][0] = 1;
    dp[0][1] = mp1[diff[0]];
    n =(ll) diff.size();
    // cout<<"hi 3"<<endl;
    for(int i =1;i<n;i++)
    {
        dp[i][0] =1;
        for(int j = 1;j<=k;j++)
        {
            dp[i][j] = dp[i-1][j]%MOD+dp[i-1][j-1]*mp1[diff[i]]%MOD;
            dp[i][j]%=MOD;
        }
    }
    // cout<<"hi 4"<<endl;
    ll sum = 0;
    for(int i = 0;i<=k;i++)
    {
        sum+=dp[n-1][i];
        sum%=MOD;
    }
    cout<<sum<<"\n";
}
// #include<bits/stdc++.h>
// using namespace std;
// #define vi vector<int>
// #define vll vector<long long>
// #define test int t;cin>>t;while(t--)
// #define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #define int long long
// #define MOD 1000000007
// typedef long double ld;
// typedef long long ll;
// #define mp map<ll,ll>


// signed main()
// {
//     fastio
//     ll n,k;
//     cin>>n>>k;
//     ll arr[n+10];
//     mp mp1;
//     vll diff;
//     for(ll i = 0;i<n;i++)
//     {
//         cin>>arr[i];
        
//         if(!mp1[arr[i]])
//            diff.push_back(arr[i]);
//         mp1[arr[i]]++;

//     }
//     // cout<<"hi 1 "<<endl;
//     n = diff.size();

//     ll sum = 0;
//     sum  = (int)(pow(2,n)+0.5)-1;
//     sum%=MOD;
//     for(auto x:mp1)
//     {
//         sum =sum*x.second;
//         sum%=MOD;
//     }
//     cout<<sum<<"\n";
// }
