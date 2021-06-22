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
    ll n,k,p;cin>>n>>k>>p;
    ll ans[n+10] , arr[n+10];
    map<ll,ll>mp;
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    ll id = 2;
    mp[arr[0]]=id;
    for(int i =1;i<n;i++)
    {
        if(arr[i]-arr[i-1]>k)
        {
            ++id;
            mp[arr[i]]=id;
        }
        else
        {
            mp[arr[i]]=id;
        }
        
    }
    // for(auto x:mp)
    // {
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
    while(p--)
    {
        int a,b;
        cin>>a>>b;
        if(mp[arr[a]]==mp[arr[b]])
            cout<<"YES\n";
        else
        {
            cout<<"NO\n";
        }

        
    }
    

}
