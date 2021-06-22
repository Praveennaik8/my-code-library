#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int n,sum;
    cin>>n>>sum;

    int arr[n+10];
    for(int i = 0;i < n; i++)
        cin>>arr[i];
    
    bool dp[n+10][sum+10];

    for(int i = 0;i <= sum; i++)
        dp[0][i] = false;
    
    for(int i = 0;i <= n; i++)
        dp[i][0] = true;

    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= sum;j++)
        {
            if(dp[i-1][j] == true)
                dp[i][j] = true;
            else
            {
                if(arr[i-1] > j)
                    dp[i][i] = false;
                else
                    dp[i][j] = dp[i-1][j-arr[i-1]];
            }
        }
    }
    cout<<dp[n][sum]<<endl;
}