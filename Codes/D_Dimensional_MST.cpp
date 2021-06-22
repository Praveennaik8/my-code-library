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

inline void print(int x =0 ,int y =0 ,int z = 0,int k = 0,string s= "")
{
    cout<<"Reached here "<<x<<"  "<<y<<"  "<<z<<"  "<<k<<s<<"\n";
}
inline void prints(string s= "",int x =0)
{
    cout<<"Reached 2 here "<<x<<" "<<s<<"\n";
}
int sum1(vi arrx,vi arry,int d)
{
    int su = 0;
    rep(i,d)su+=abs(arrx[i]-arry[i]);
    return su;
}
int fnd(int dsu[],int n,int u)
{
    return dsu[u];
}
void unin(int dsu[],int n,int u,int v)
{
    int x = fnd(dsu,n,u);
    for(int i = 0;i<n;i++)
    {
        if(dsu[i] == x)
            dsu[i] = dsu[v];
    }
}
bool comp(const pair<pair<int,int>,int> p1,const pair<pair<int,int>,int> p2)
{
    return p1.second > p2.second;
}
signed main()
{
    fastio  
    int n,d;
    cin>>n>>d;
    vector<vector<int> >points(n,vector<int>(d));

    rep(i,n) 
        rep(j,d)
            cin>>points[i][j];

    vector< pair<pair<int,int>,int> >edges;
   // print();
    rep(mask,(1<<d)/2)
    {
        int max = INT_MIN,min = INT_MAX,maxind = 0,minind = 0,sum = 0;
        rep(i,n)
        {
            sum = 0;
            rep(j,d)
            {
                if(mask>>j&1)
                    sum+=points[i][j];
                else
                    sum-=points[i][j];
            }
            if(max < sum)
            {
                max = sum;
                maxind = i;
            }
            if(min > sum)
            {
                min = sum;
                minind = i;
            }  
        }
        // print(max,min,maxind,minind);
        rep(i,n)
            edges.push_back({{i,maxind},sum1(points[i],points[maxind],d)});
        rep(i,n)
            edges.push_back({{i,minind},sum1(points[i],points[minind],d)});
    }
    int dsu[n];
    rep(i,n) dsu[i] = i;
    sort(edges.begin(),edges.end(),comp);
    int ecount = 0,wt = 0;
    for(int i = 0;i<edges.size()&&ecount<n-1;i++)
    {
        int u = edges[i].first.first, v = edges[i].first.second;
        if(fnd(dsu,n,u) != fnd(dsu,n,v))
        {
            unin(dsu,n,u,v);
            wt += edges[i].second;
            ecount++;
        }
    }
    cout<<wt<<"\n";
}
