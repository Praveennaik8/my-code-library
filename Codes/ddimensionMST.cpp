// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long int
// // STL implementation of Prim's algorithm for MST 
// #include<bits/stdc++.h> 
// using namespace std; 
// # define INF 0x3f3f3f3f 
// int d;
// vector<vector<int> >pair_list;
// // iPair ==> Integer Pair 
// typedef pair<int, int> iPair; 
  
// // To add an edge 
// void addEdge(vector <pair<int, int> > adj[], int u, 
//                                      int v, int wt) 
// { 
//     adj[u].push_back(make_pair(v, wt)); 
//     adj[v].push_back(make_pair(u, wt)); 
// } 
  
// // Prints shortest paths from src to all other vertices 
// void primMST(vector<pair<int,int> > adj[], int V) 
// { 
//     // Create a priority queue to store vertices that 
//     // are being preinMST. This is weird syntax in C++. 
//     // Refer below link for details of this syntax 
//     // http://geeksquiz.com/implement-min-heap-using-stl/ 
//     priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
  
//     int src = 0; // Taking vertex 0 as source 
  
//     // Create a vector for keys and initialize all 
//     // keys as infinite (INF) 
//     vector<int> key(V, INF); 
  
//     // To store parent array which in turn store MST 
//     vector<int> parent(V, -1); 
  
//     // To keep track of vertices included in MST 
//     vector<bool> inMST(V, false); 
  
//     // Insert source itself in priority queue and initialize 
//     // its key as 0. 
//     pq.push(make_pair(0, src)); 
//     key[src] = 0; 
  
//     /* Looping till priority queue becomes empty */
//     while (!pq.empty()) 
//     { 
//         // The first vertex in pair is the minimum key 
//         // vertex, extract it from priority queue. 
//         // vertex label is stored in second of pair (it 
//         // has to be done this way to keep the vertices 
//         // sorted key (key must be first item 
//         // in pair) 
//         int u = pq.top().second; 
//         pq.pop(); 
  
//         inMST[u] = true; // Include vertex in MST 
  
//         // Traverse all adjacent of u 
//         for (auto x : adj[u]) 
//         { 
//             // Get vertex label and weight of current adjacent 
//             // of u. 
//             int v = x.first; 
//             int weight = x.second; 
  
//             // If v is not in MST and weight of (u,v) is smaller 
//             // than current key of v 
//             if (inMST[v] == false && key[v] > weight) 
//             { 
//                 // Updating key of v 
//                 key[v] = weight; 
//                 pq.push(make_pair(key[v], v)); 
//                 parent[v] = u; 
//             } 
//         } 
//     } 
  
//     // Print edges of MST using parent array 
//     for (int i = 1; i < V; ++i) 
//         printf("%d - %d\n", parent[i], i); 
// } 
// bool comp1(const vector<int>& p1,const vector<int>& p2 )
// {
//     int sum1 = 0,sum2  =0;
//     for(int i = 0;i<d;i++)
//     {
//         sum1+=p1[i]*(i+1);
//         sum2+=p2[i]*(i+1);
//     }
//     if(sum1<sum2)
//         return true;
//     return false;
// }
// int calc_wt(vector<int> arrx,vector<int>  arry)
// {
//     int sum = 0;
//     for(int i = 0;i<d;i++)
//     {
//         sum+=abs(arrx[i]-arry[i]);
//     }
//     return sum;
// }
// // Driver code 
// signed main() 
// {  
//     //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//     //testcase
//     //cout<<"hi\n";
//     int n;
//     cin>>n>>d;
//     pair_list.resize(n);
// 	for(int i = 0;i<n;i++)
//     {
//         for(int j = 0;j<d;j++)
//         {
//             int temp;
//             cin>>temp;
//             pair_list[i].push_back(temp);
//         }
//     }
//     int sum =0;

//     vector<iPair > adj[n];
// //     sort(pair_list.begin(),pair_list.end(),comp1);
    
// //     // for(int i = 0;i<n;i++)
// //     // {
// //     //     for(int j = 0;j<d;j++)
// //     //     {
// //     //         cout<<pair_list[i][j]<<"  ";
// //     //     }
// //     //     cout<<"\n";
// //     // }
// //     edgey e[25000];
// //    // sum = max(sum,total(n));
// // 	//int edges[n+10][n+10];
//     int z = -1;
//     int x = n>10?10:n/2;
//     for(int i = 0;i<n;i++)
//     {
//         //cout<<i<<"done\n";;
//         // for(int j = 0;j<=x;j++)
//         // {
//         //     if(i!=j){
//         //         ++z;
//         //     e[z].src = i; 
// 	    //     e[z].dest = j; 
// 	    //     e[z].dist = calc_wt(pair_list[i],pair_list[j]);
	        
//         //     }
//         // }
//         // for(int j = n-1;j>=(x);j--)
//         // {

//         //     if(i!=j){
//         //         ++z;
//         //     e[z].src = i; 
// 	    //     e[z].dest = j; 
// 	    //     e[z].dist = calc_wt(pair_list[i],pair_list[j]);
//         //     }
//         // }
//         for(int j =i+1;j<n;j++)
//         {
//             addEdge(adj,i,j,calc_wt(pair_list[i],pair_list[j]));
//         }

//     }
//     // //cout<<"done\n";
// 	// V = n;
//     // E = z+1;

//     // sort(e,e+E,cmp);
//     // for(int i = 0;i<=z;i++)
//     // {
//     //     cout<<e[i].src<<"  "<<e[i].dest<<"  ==  "<<e[i].dist<<endl;
//     // }
//     // cout<<V<<"  , "<<E<<endl;
// 	primMST(adj, n);

// 	return 0; 
// } 
#include<bits/stdc++.h>
using namespace std;
#define int int
int V, E, tempX, tempY;
int parent[20000005];
int height[20000005];
struct edgey
{
    int src,dest,dist;
};
bool cmp(edgey g1,edgey g2)
{
    return g1.dist > g2.dist;
}
int root(int src)
{
    int i=src;
    while(parent[i]!=i)
    {
        i=parent[i];
    }
    return i;
}
void unin(int src,int dest)
{
    int x1=root(src);
    int x2=root(dest);
	if(height[x1]>height[x2]){
		parent[x2]=x1;
		height[x2]=height[x1];
	}
	else if(height[x1]<height[x2]){
		parent[x1]=x2;
		height[x1]=height[x2];
	}
	else{
    	parent[x2]=x1;
		height[x2]+=1;
		height[x1]=height[x2];
	}
}
int mst(edgey e[])
{
    for (int i = 0; i < V; ++i)
    {
        parent[i]=i;
    }
    int ans=0;
    for (int i = 0; i < E; ++i)
    {
        if(root(e[i].src)!=root(e[i].dest))
        {
            cout<<e[i].src<<"  -- >  "<<e[i].dest<<" == "<<e[i].dist<<endl;
            ans=ans+(e[i].dist);
            unin(e[i].src,e[i].dest);
        }
    }
    return ans;
}

int calc_wt(int arrx[],int arry[],int d)
{
    int sum = 0;
    for(int i = 1;i<=d;i++)
    {
        sum+=abs(arrx[i]-arry[i]);
    }
    return sum;
}
// Driver code 
main() 
{ 
    //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    //testcase
    
    int n,d;
    cin>>n>>d;
    int graph[n+10][d+10];
	for(int i = 1;i<=n;i++)
    {
        //nodes.insert(i);
        for(int j = 1;j <= d;j++)
        {
            cin>>graph[i][j];
        }
    }
    edgey e[n*n%250000005];
    int z = -1;
	//int edges[n+10][n+10];
    for(int i = 1;i<=n;i++)
    {
        for(int j = i+1;j<=n;j++)
        {
            if(i!=j)
            {
                ++z;
                e[z].src = i; 
                e[z].dest = j; 
                e[z].dist = calc_wt(graph[i],graph[j],d);
                ++z;
                e[z].src = j; 
                e[z].dest = i; 
                e[z].dist = e[z-1].dist;
            }
        }
    }
    
	V = n;
    E = z+1;

    sort(e,e+E,cmp);
    for(int i = 0;i<=z;i++)
    {
        cout<<e[i].src<<"  "<<e[i].dest<<"  ==  "<<e[i].dist<<endl;
    }
    cout<<V<<"  , "<<E<<endl;
	cout<<mst(e)<<endl;

	return 0; 
} 
