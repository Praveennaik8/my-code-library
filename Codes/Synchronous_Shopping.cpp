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
int dijstras(vector< pii >graph[],int n,int src,int k,vector<pair<int,string> > types)
{
    vi dist(n+10,INF);// Distance array init to INF

    priority_queue< pii >pq;// Priority queue with u and dist b/w u and src
    dist[src] = 0;          //Init src distance to 0
    pq.push(mp(0,src));     //Push source vertex and its ditance to queue    
    //print(1);
    while(!pq.empty())      // Loop untill queue is empty
    {
        
        pii crnt = pq.top(); // store top pair
        pq.pop();
        int u = crnt.second;
        //print(u);
        if(crnt.first > dist[u]) // No use in looping with 'u'
            continue;

        for(auto v : graph[u])
        {
            //prints("second ",v.first);
            int wt = v.second;
            int vert = v.first;
            if(dist[vert] > (dist[u]+wt))
            {
                dist[vert] = (dist[u]+wt);
                pq.push(mp(dist[vert] ,vert));
            }
        }
    }
    mpl frq;
    repA(i,1,n-1)
    {
        cout<<i<<" == "<<dist[i]<<endl;
    }
    


}
signed main()
{
    //fastio
    //testcase
    {
        int n,m,k;
        cin>>n>>m>>k;
        vector< pii >graph[n+10];
        ll u,v,w,x;
        vector<pair<int,string> > types(n+10);
        string s;
        repA(i,1,n)
        {
            cin>>x;  
            cin>>s;
            types[i] = mp(x,s);
            //cout<<types[i]<<"  kk\n";
        }
        rep(i,m)
        {
            cin>>u>>v>>w;
            //cout<<"faile";~
            //print();
            graph[u].pb(mp(v,w));
            graph[v].pb(mp(u,w));
        }
        dijstras(graph,n,1,k,types);
    }
}