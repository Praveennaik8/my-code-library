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
ll mulmod(ll a, ll b, ll mod)
{
    ll res = 0; 
    a = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (res + a) % mod;
        a = (a * 2) % mod;
        b /= 2;
    }
    return res % mod;
}
vector<vector<int> > graph;
vector<int>childCount;
bool cmp(int a,int b)
{
    return childCount[a] > childCount[b];
}
void getchildCount(int z,int parent)
{
    if(childCount[z]!=-1)
        return ;
    if(graph[z].size() == 0){
        childCount[z] = 1;
        return;
    }
    int sum = 1;
    for(auto x:graph[z])
    {
        if(x != parent)
            getchildCount(x,z);
    }
    sort(graph[z].begin(),graph[z].end(),cmp);
    int i = 1;
    for(auto x:graph[z])
    {
        if( x!= parent)
        {
            childCount[x] *=i;
            i+=1;
            sum+=childCount[x];
        }
        // cout<<z<<" --> "<<x<<" mul "<<i<<"  "<<childCount[x]<<endl;
        
    }
    childCount[z] = sum;
}
signed main()
{
    fastio
    testcase
    {
        int n,x;
        cin>>n>>x;
        int u,v;
        graph.clear();
        graph.resize(n+1);
        childCount.clear();
        childCount.resize(n+1,-1);
        rep(i,n-1)
        {
            
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        // cout<<ii<<""<<graph[15].size()<<endl;
        getchildCount(1,0);
        // rep(i,n+1)
        //     cout<<i<<"  "<<childCount[i]<<endl;
        cout<<mulmod(childCount[1],x,MOD)<<endl;
        
    }
}