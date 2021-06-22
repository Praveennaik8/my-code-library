#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
#define int long long
#define vi vector<int>
#define vll vector<long long>
#define INF (ll)1e19
#define testcase int t; cin>>t ;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define mpl map<ll,ll>
#define pii pair<int,int>
#define SIZE ll(100005)//00002)
#define FAIL -5677884
#define BIT_SIZE 35
#define MOD 1000000007

void print(int x =0 ,int y =0 ,int z = 0,int k = 0,string s= "")
{
    cout<<"Reached here "<<x<<"  "<<y<<"  "<<z<<"  "<<k<<s<<"\n";
}
void prints(string s= "",int x =0)
{
    cout<<"Reached 2 here "<<x<<" "<<s<<"\n";
}
typedef struct lis
{
    int val = 0,diff = 0;
}LIS;
signed main()
{
    int n;
    cin>>n;
    int arr[n+10];
    rep(i,n)
        cin>>arr[i];

    LIS dp[n+10];
    rep(i,n){
        dp[i].val = 1;
        dp[i].diff = 0;
    }
    int maxsub = 0;

    repA(i,1,n-1)
    {
        repA(j,0,i-1)
        {
            if(arr[j]<arr[i] && dp[j].diff < (arr[i]-arr[j]) && dp[i].val<=dp[j].val+1)
            {
                cout<<"hi\n";
                if(dp[i].val == dp[j].val+1)
                {
                    dp[i].diff = min(dp[i].diff,arr[i]-arr[j]);

                }
                else
                {
                    dp[i].val = max(dp[i].val,dp[j].val+1);
                    dp[i].diff = arr[i]-arr[j];
                }
                
                
            }
            else if(arr[j]<arr[i] && dp[i].val == 1)
            {
                dp[i].val = 2;
                dp[i].diff = arr[i]-arr[j];
            }
            
        }
        maxsub = max(maxsub,dp[i].val);
    }
    rep(i,n)
    {
        cout<<dp[i].val<<"  "<<dp[i].diff<<endl;
    }
    cout<<maxsub<<endl;

}