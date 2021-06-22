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
    
    int temp = 0,max_sum = 0;
    
    for(int i = 0;i < n;i++)
    {
        temp+=arr[i];
        temp = max(temp,0ll);
        max_sum = max(max_sum,temp);
    }
    cout<<max_sum<<endl;
}