#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define test int t;cin>>t;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

typedef long double ld;
typedef long long ll;


int main()
{
    fastio
    test
    {
        int n,k;
        cin>>n>>k;
        vi arr(n);
        for(int i =0 ;i<n;i++)
        {
            cin>>arr[i];
        }
        vi dp(n,INT_MAX);
        dp[0] = k;

        for(int i = 0;i<n;i++)
        {
            vi freq(1000,0);
            int rep = 0;
            for(int j = i;j>=0;j--)
            {
                freq[arr[j]]++;
                if(freq[arr[j]]==2)
                    rep+=2;
                else if(freq[arr[j]]>2)
                    rep++;
                if(j == 0)
                {
                    dp[i] = min(dp[i],rep+k);
                }
                else
                    dp[i] = min(dp[i],rep+k+dp[j-1]);
               // cout<<i<<" "<<j<<" "<<dp[i]<<endl;
            }
        }
        cout<<dp[n-1]<<endl;
    }
}

