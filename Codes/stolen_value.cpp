#include<bits/stdc++.h>
using namespace std;
///Select alternative numbers to pick the maximum sum

signed main()
{
    int n;cin>>n;
    int arr[n+10];

    for (int i = 1; i <= n; i++)
        cin>>arr[i];

    int dp[n+10];
    dp[0] = 0;
    dp[1] = arr[1];
    
    for(int i = 2;i <= n; i++)
        dp[i] = max(dp[i-1],dp[i-2]+arr[i]);
    
    cout<<dp[n]<<endl;
}