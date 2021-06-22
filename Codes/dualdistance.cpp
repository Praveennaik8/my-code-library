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
#define SIZE ll(1005)//00002)
#define FAIL -5677884
#define BIT_SIZE 35
#define MOD 1000000007
int n,k;
// vector<vector<int> > graph;
int graph[SIZE][SIZE];
int dist[SIZE][SIZE];
void printSolution();

void floydWarshall()
{
	int  i, j, k;

	for (i = 1; i <=n; i++)
		for (j = 1; j <= n; j++)
        {
            if(i == j)
            {
                dist[i][j] = 0;
            }
            else
                dist[i][j] = graph[i][j];
        }
			

	for (k = 1; k <= n; k++) {
		
		for (i = 1; i <= n; i++) {

			for (j = 1; j <= n; j++) {
				
				if (dist[i][j] > (dist[i][k] + dist[k][j])&& (dist[k][j] != INF&& dist[i][k] != INF))
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	// Print the shortest distance matrix
	// printSolution();
}

/* A utility function to print solution */
void printSolution()
{
	cout << "The following matrix shows the shortest "
			"distances"
			" between every pair of vertices \n";
	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <=n; j++) {
			if (dist[i][j] == INF)
				cout << "INF"
					<< "	 ";
			else
				cout << dist[i][j] << "	 ";
		}
		cout << endl;
	}
}

// Driver code
signed main()
{
    fastio
	testcase
    {
        int q;
        cin>>n>>q;
        int u,v;
        rep(i,n+1)
        {
            rep(j,n+1)
            {
                graph[i][j] = INF;
            }
        }
        rep(i,n-1)
        {
            cin>>u>>v;
            graph[u][v] = 1;
            graph[v][u] = 1;
        }
        floydWarshall();
        while(q--)
        {
            int a,b;
            cin>>a>>b;
            int sum = 0;
            for(int i = 1;i<=n;i++)
            {
                sum += min(dist[i][a],dist[i][b]);
            }
            cout<<sum<<endl;
        }
    }
}

// This code is contributed by Mythri J L
