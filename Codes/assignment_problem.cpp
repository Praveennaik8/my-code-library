#include<bits/stdc++.h>
using namespace std;

int get_setbit(int num)
{
    int cnt = 0;
    while(num)
    {
        if(num&1)
            ++cnt;
        num>>=1;
    }
    return cnt;
}
bool isSet(int num,int pos)
{
    return num&(1<<pos);
}
signed main()
{
    int n;
    cin>>n;
    int matrix[n+10][n+10];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin>>matrix[i][j];

    int dp[(int)(pow(2,n)+0.5)] ;
    
    for(int i = 0;i<(int)(pow(2,n)+0.5);i++)
        dp[i] = INT_MAX;

    dp[0] = 0;

    for(int mask = 0;mask<(int)(pow(2,n)+0.5);mask++)
    {
        int x = get_setbit(mask);
        for(int j = 0;j<n;j++)
        {
            if(!isSet(mask,j))
                dp[mask|(1<<j)] = min(dp[mask|(1<<j)],dp[mask]+matrix[x][j]);
        }
           
    }
    cout<<dp[(int)(pow(2,n)+0.5)-1]<<endl;
}