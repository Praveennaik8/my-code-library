#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
#define int long long
#define vi vector<int>
#define vll vector<long long>
#define INF (ll)1e18
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
typedef pair<int, int> pd; 

struct myComp { 
    constexpr bool operator()( 
        pair<int, int> const& a, 
        pair<int, int> const& b) 
        const noexcept 
    { 
        return a.second > b.second; 
    } 
}; 
main()
{
    fastio
    testcase
    {
        int n;
        cin>>n;
        int fuel[n+10],cost[n+10];
        rep(i,n)
            cin>>fuel[i];
        
        rep(i,n)
            cin>>cost[i];
        
        
        int dp[n+10][n+10];
        rep(i,n+10)
            dp[i][i] = 0;

        for(int i = 0;i<n;i++)
        {
            int k = i;
            priority_queue<pd, vector<pd>, myComp> p1;
            for(int j = 0;j <= n;j++)
            {
                int p = (j+k)%n;
                //cout<<p<<" , ";
                
                if(j == 0)
                    dp[i][j] = 0;
                else if(j!=0)
                {
                    int p_temp = p-1;
                    if(p_temp==-1) 
                        p_temp = n-1;
                    dp[i][p] = dp[i][p_temp];
                    int f,c;
                    if(p1.empty())
                        dp[i][p] = INF;
                    else
                    {
                        f = p1.top().first;
                        c = p1.top().second;
                        p1.pop();
                        dp[i][p]+=c;
                        if(f-1>0)
                        {
                            p1.push(make_pair(f-1,c));
                        }
                    }
                    
                    
                    
                }
                //cout<<dp[i][p]<<"  ";
                if(fuel[p]!=0)
                    p1.push(make_pair(fuel[p],cost[p]));
                

            }
            //cout<<endl;
        }
        
        int mincost = INF;
        rep(i,n)
        {
            mincost = min(mincost,dp[i][i]);
        }
        cout<<mincost<<"\n";

        
    }
}