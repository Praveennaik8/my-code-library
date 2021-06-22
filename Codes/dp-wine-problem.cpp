#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define test int t;cin>>t;while(t--)
typedef long double ld;
typedef long long ll;


int main()
{
    test
    {
        int n;
        cin>>n;
        vi arr(n);
        for(int i =0 ;i<n;i++)
        {
            cin>>arr[i];
        }
        int dp[n+1][n+5]={0};
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
               dp[i][j]= 0;
            }
        }
        for(int i = n-1;i>=0;i--)
        {
            for(int j = i;j<n;j++)
            {
                int year = n-(j-i);
                cout<<year<<endl;
                if(i ==n-1)
                {
                    dp[i][j]=  max(dp[i][j],dp[i][j-1]+year*arr[j]);
                }
                if( j == 0)
                {
                    dp[i][j]=  max(dp[i+1][j]+year*arr[i],dp[i][j]);
                }
                else
                    dp[i][j]=  max(dp[i+1][j]+year*arr[i],dp[i][j-1]+year*arr[j]);
                    // select max of 
                    // previous column item from dp+ jth item * year 
                    // or next row item from dp + ith item *year
                for(int i = 0;i<n;i++)
                {
                    for(int j = 0;j<n;j++)
                    {
                        cout<<dp[i][j]<<"\t";
                    }
                    cout<<endl;
                   
                }
                 cout<<"--------------------------------------------------------\n";
            }
        }
        cout<<dp[0][n-1]<<endl;
        

    }
}

