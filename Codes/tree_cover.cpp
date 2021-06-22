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
int n,k;
vector<vector<int> > graph;
vector<int>path;
vector<int> nextch;
pair<int, int> bfs(int u)
{
    path.clear();
    path.resize(n+1,-1);
	// mark all distance with -1
	int dis[n+1];
	memset(dis, -1, sizeof(dis));
    // cout<<"^^^^^^^^^^^^^^^\n";

	queue<int> q;
	q.push(u);

	// distance of u from u will be 0
	dis[u] = 0;
    path[u] = 0;

	while (!q.empty())
	{
		int t = q.front();	 
        q.pop();

		// loop for all graphacent nodes of node-t
		for (auto it = graph[t].begin(); it != graph[t].end(); it++)
		{
			int v = *it;

			// push node into queue only if
			// it is not visited already
			if (dis[v] == -1)
			{
				q.push(v);

				// make distance of v, one more
				// than distance of t
				dis[v] = dis[t] + 1;
                if(path[v]==-1)
                {
                    // cout<<"before "<<v<<" "<<t<<" "<<path[v]<<endl;
                    path[v] = t;
                    // cout<<"after "<<v<<" "<<t<<" "<<path[v]<<endl;
                }
                    
                // path[t] = v;
			}
		}
	}

	int maxDis = 0;
	int nodeIdx;

	// get farthest node distance and its index
	for (int i = 1; i <= n; i++)
	{
		if (dis[i] > maxDis)
		{
			maxDis = dis[i];
			nodeIdx = i;
		}
	}
	return make_pair(nodeIdx, maxDis);
}

// method prints longest path of given tree
int longestPathLength()
{
	pair<int, int> t1, t2;

	// first bfs to find one end point of
	// longest path
	t1 = bfs(1);

	// second bfs to find actual longest path
	t2 = bfs(t1.first);

	// cout << "Longest path is from " << t1.first << " to "
	// 	<< t2.first << " of length " << t2.second;
    return t2.first;
}
int dfs(int z,int parent)
{
    // cout<<"root "<<z<<endl;
    if(graph[z].size()==1&&parent!=0)
        return 1;
    int sum = 0,tempsum = 0;
    
    for(auto x:graph[z])
    {
        if(x != parent)
        {
            tempsum = dfs(x,z);
            // cout<<z<<" -> "<<x<<" = "<<tempsum<<endl;
            if(graph[z].size()>2)
            {
                if(sum <tempsum )
                {
                    
                    if(sum!=0)
                        nextch.push_back(sum);
                    sum = tempsum;
                    // cout<<z<<" - "<<sum<<endl;
                }
                else{
                    nextch.push_back(tempsum);
                }
            }
            else
                sum = max(sum,tempsum);
        }
            
    }
    // cout<<z<<" -> "<<1+sum<<endl;
    return 1+sum;
}
// Driver code to test above methods
signed main()
{
	// fastio
    testcase
    {
        
        cin>>n>>k;
        nextch.clear();
        graph.clear();
        graph.resize(n+1);
        int u,v;
        rep(i,n-1)
        {
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        // cout<<"\n--------------------\n";
        // for(int i = 1;i<=n;i++)
        // {
        //     cout<<i<<" -> ";
        //     for(auto x:graph[i])
        //     {
        //         cout<<x<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<"\n--------------------\n";

        int root = longestPathLength();
        // cout<<root<<endl;
        int ans = dfs(root,0);
        int count = 2;
        sort(all(nextch),greater<int>());
        // for(auto x:nextch)
        // {
        //     cout<<x<<endl;
        // }
        for(auto x:nextch)
        {
            
            if(ans>=k)
            {
                break;
            }
            count+=1;
            ans+=x;
            // cout<<x<<" "<<ans<<endl;
        }
        if(k == 1)
            count = 1;
        cout<<count<<endl;
        
        // cout<<"\n--------------------\n";
        // rep(i,path.size())
        // {
        //     cout<<i<<" "<<path[i]<<endl;
        // }
        // cout<<"\n--------------------\n";
    }

	return 0;
}
