#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int n,target;
    cin>>n>>target;

    int arr[n+10];
    for(int i = 0;i < n; i++)
        cin>>arr[i];
    
    int sum[target+10];

    for(int i = 0;i <= target; i++)
        sum[i] = 0;
    
    sum[0] = 1;
    
    for(int i = 0;i < n;i++)
    {
        for(int j = arr[i];j <= target;j++)
        {
            sum[j] = sum[j] + sum[j-arr[i]];
        }
    }
    cout<<sum[target]<<endl;
}