#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define test int t;cin>>t;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define MOD 1000000009
typedef long double ld;
typedef long long ll;
#define SZ (ll)1e6+5

vi graph[SZ];
bool visited[SZ];
void bfs(int n,int i)
{
    if(i==n)
       return ;
    visited[i] = true;
    cout<<i<<endl;
    queue<int>q;
    q.push(i);
    visited[i] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0;i<graph[u].size();i++)
        {
            if(!visited[graph[u][i]])
            {
                cout<<graph[u][i]<<endl;
                visited[graph[u][i]] = true;
                q.push(graph[u][i]);
            }
        }
    }
}

signed main()
{
    fastio
    int n,k,u,v,w;
    cin>>n>>k;
    for(int i =0 ;i<k;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        //graph[v].push_back(u);
    }
    for(int i =0 ;i<n;i++)
        visited[i] = false;
    
    for(int i =0 ;i<n;i++)   
    {
        if(!visited[i])
            bfs(n,i);
    } 
}

