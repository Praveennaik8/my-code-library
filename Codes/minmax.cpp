#include<bits/stdc++.h>
using namespace std;

#define int long long

int ini = 0,curr = 0;

int get_max(int arr[],int n)
{
    int temp = 0,max_sum = 0;
    
    for(int i = 0;i < n;i++)
    {
        
        temp+=arr[i];
        if(temp < 0 )
        {
            ini = i+1;
            curr = i+1;
            temp = 0;
        }
        if(max_sum<temp)
        {
            max_sum = temp;
            curr = i;
        }
    }
    return max_sum;
}
signed main()
{
    int n;
    cin>>n;
    int arr[n+10];
    for(int i = 0;i < n; i++)
        cin>>arr[i];
    int max_sum1 = get_max(arr,n);

    int size = n - (curr-ini+1);
    int temp = 0,max_sum = 0;
    
    for(int i = 0;i < n;i++)
    {
        if(i == ini)
        {
            i = curr+1;
            if(i>=n)break;
        }
        temp+=arr[i];
        temp = max(temp,0ll);
        max_sum = max(max_sum,temp);
    }
    
    
    cout<<max_sum1<<" "<<max_sum<<endl;

}