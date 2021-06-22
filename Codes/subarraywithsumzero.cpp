#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
#define int long long
#define SIZE (ll)100000 

void printsubArray(vector<int>arr,int strt,int end)
{
    for(int i = strt;i<=end;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
signed main()
{
    int n;
    cin>>n;
    vector<int>arr(n+10);
    
    for(int i = 1;i<=n;i++)
    {
        cin>>arr[i];
    }
    int sum = 0;
    for(int i = 1;i<=n;i++)
    {
        sum = 0;
        for(int j = i;j>=1;j--)
        {
            sum+=arr[j];
            if(sum == 0)
                printsubArray(arr,j,i);
        }
    }
}

