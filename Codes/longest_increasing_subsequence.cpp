#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int n;
    cin>>n;

    int arr[n+10];
    for(int i = 0;i < n; i++)
        cin>>arr[i];
    
    int dp[n+10];
    for(int i = 0;i <= n; i++)
        dp[i] = 1;

    int maxlen = 1;

    for(int i = 1;i < n;i++)
    {
        
        for(int j = 1;j < i;j++)
        {
            if(arr[j]<arr[i])
                dp[i] = max(dp[i],dp[j]+1);
        }
        maxlen = max(maxlen,dp[i]);
    }
    cout<<maxlen<<endl;
}