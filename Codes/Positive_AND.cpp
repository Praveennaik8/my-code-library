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
bool ispowerof2(int n) 
{ 
    if (n == 0) 
        return 0; 
    while (n != 1) 
    { 
        if (n%2 != 0) 
            return 0; 
        n = n/2; 
    } 
    return 1; 
} 
signed main()
{
    fastio
    int dp[100005];
    dp[1] = 2;
    dp[2] = 3;
    dp[3] = 1;
    dp[4] = 5;
    repA(i,5,100005)
    {
        if(ispowerof2(i))
            dp[i] = dp[i-1]+2;
        else if(ispowerof2(i-1))
            dp[i] = dp[i-1] - 1;
        else if(ispowerof2(i-2))
            dp[i] = dp[i-2] + 1;
        else
        {
            dp[i] = dp[i-1]+1;
        }
        
    }
    testcase
    {
        int n;
        cin>>n;
        int strt = 1;
        if(n==1)
            cout<<"1\n";    
        else if(ispowerof2(n))
            cout<<"-1\n";
        else
        {
            repA(i,1,n)
            {
                cout<<dp[i]<<" ";
            }
            cout<<"\n";
        }
    }
}