#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int n;
    cin>>n;
    int dp[n+10];
    
    for(int i = 0;i <=n;i++)
        dp[i] = 0;

    for(int i = 2;i <=n;i++)
    {
        for(int j = 1;j<=i/2;j++)
        {
            dp[i] = max(max(dp[i],j*(i-j)),j*dp[i-j]);
        }
    }
    for(int i = 0;i <=n;i++)
        cout<<dp[i]<<" ";
    cout<<dp[n]<<endl;
}