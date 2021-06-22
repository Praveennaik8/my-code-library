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

int dijstras(vector< pii >graph[],int n,int src)
{
    vi dist(n,INF);// Distance array init to INF

    priority_queue< pii >pq;// Priority queue with u and dist b/w u and src
    dist[src] = 0;          //Init src distance to 0
    pq.push(mp(0,src));     //Push source vertex and its ditance to queue    

    while(!pq.empty())      // Loop untill queue is empty
    {
        pii crnt = pq.top(); // store top pair
        pq.pop();
        int u = crnt.second;

        if(crnt.first > dist[u]) // No use in looping with 'u'
            continue;

        for(auto v : graph[u])
        {
            int wt = v.second;
            int vert = v.first;
            if(dist[vert] > (dist[u]+wt))
            {
                dist[vert] = (dist[u]+wt);
                pq.push(mp(dist[vert] ,vert));
            }
        }
    }
    repA(i,1,n-1)
    {
        cout<<i<<" == "<<dist[i]<<endl;
    }
}
signed main()
{
    fastio
    testcase
    {
        int n;
        cin>>n;
        vector< pii >graph[n+1];
        ll u,v,w;
        rep(i,n-1)
        {
            cin>>u>>v>>w;
            //cout<<"faile";
            graph[u].pb(mp(v,w));
            graph[v].pb(mp(u,w));
        }
        dijstras(graph,n,1);
    }
}