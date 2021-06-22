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

signed main()
{
    fastio
    testcase
    {
        int n,m;
        cin>>n>>m;
        int train[n+10],Bdest[m+10];
        repA(i,1,n)
            cin>>train[i];

        rep(i,m)
            cin>>Bdest[i];

        int cost[n+10];
        rep(i,n)
            cost[i] = -1;
        
        int val = -1;
        repA(i,1,n)
        {
            if(val!=-1)
                val+=1;
            if(train[i] == 1)
            {
                val = 0;
            }
            cost[i] = val;
        }
        val = -1;
        for(int i = n;i>0;i--)
        {
            if(val!=-1)
                val+=1;
            if(train[i] == 2)
            {
                val = 0;
            }
            if(val>=0)
            {
                if(cost[i] == -1)
                    cost[i] = val;
                else
                    cost[i] = min(val,cost[i]);
            }
            
        }
        cost[1] = 1;
        rep(i,m)
        {
            cout<<cost[Bdest[i]]<<" ";
        }
        cout<<"\n";
    }
}