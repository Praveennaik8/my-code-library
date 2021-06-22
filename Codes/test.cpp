// // You are given a tree with N nodes numbered from 1 to N. A set S of nodes is called valid if there exist two vertices u and v (possibly, u=v) such that every node in S lies on the simple path from u to v.

// // Count the number of valid sets modulo 109+7. Two sets are different if one node is included in one set and not in the other. If there are multiple pairs (u,v) making a set valid, that set is still only counted once.

// // Input
// // The first line contains an integer T, the number of test cases. Then the test cases follow.
// // Each test case contains N lines of input.
// // The first line contains a single integer N, the number of tree nodes.
// // Each of the next N−1 lines contains two space-separated integers u and v representing an edge between nodes u and v.
// // Output
// // For each test case, output in a single line the number of valid sets modulo 109+7.

// // Constraints
// // 1≤T≤50
// // 1≤N≤105
// // 1≤u,v≤N
// // Sum N over all testcases is at most 5⋅105.
// // The given input is a valid tree.
// // Subtasks
// // Subtask #1 (20 points):

// // 1≤T≤10
// // 1≤N≤3⋅103
// // Subtask #2 (80 points): Original Constraints

// // Sample Input
// // 2
// // 4
// // 1 2
// // 3 1
// // 2 4
// // 4
// // 1 2
// // 2 3
// // 2 4
// // Sample Output
// // 15
// // 13
// // Explanation
// // Test Case 1: Every non-empty set is valid.

// // Test Case 2: The valid sets are {1}, {2}, {3}, {4}, {1,2}, {1,3}, {1,4}, {2,3}, {2,4}, {3,4}, {1,2,3}, {1,2,4}, {2,3,4}.


// #include<bits/stdc++.h>
// using namespace std;

// typedef long double ld;
// typedef long long ll;
// #define int long long
// #define vi vector<int>
// #define vll vector<long long>
// #define INF (ll)1e19
// #define testcase int t; cin>>t ;while(t--)
// #define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #define all(x) x.begin(), x.end()
// #define fill(a)  memset(a, 0, sizeof (a))
// #define fst first
// #define snd second
// #define mp make_pair
// #define pb push_back
// #define rep(i, n)    for(int i = 0; i < (n); ++i)
// #define repA(i, a, n)  for(int i = a; i <= (n); ++i)
// #define repD(i, a, n)  for(int i = a; i >= (n); --i)
// #define mpl map<ll,ll>
// #define pii pair<int,int>
// #define SIZE ll(100005)//00002)
// #define FAIL -5677884
// #define BIT_SIZE 35
// #define MOD 1000000007

// void print(int x =0 ,int y =0 ,int z = 0,int k = 0,string s= "")
// {
//     cout<<"Reached here "<<x<<"  "<<y<<"  "<<z<<"  "<<k<<s<<"\n";
// }
// void prints(string s= "",int x =0)
// {
//     cout<<"Reached 2 here "<<x<<" "<<s<<"\n";
// }
// vector< vector<int> > graph;
// int validCount = 0,ddd = 0;
// int V;
// bool value = false;
  
// // A recursive function to print all paths from 'u' to 'd'.
// // visited[] keeps track of vertices in current path.
// // path[] stores actual vertices and path_index is current
// // index in path[]
// void printAllPathsUtil(int u, int d, bool visited[],int path[], int& path_index,vector<int>&grp)
// {
//     // Mark the current node and store it in path[]
//     visited[u] = true;
//     path[path_index] = u;
//     path_index++;
  
//     // If current vertex is same as destination, then print
//     // current path[]
//     if (u == d) {
//         for (int i = 0; i < path_index; i++)
//         {
//             auto xxx = find(grp.begin(),grp.end(),path[i]);
//             if(xxx != grp.end())
//             {
//                 grp.erase(xxx);
//             }
//         }
//         if(grp.size()==0)
//             value = true;
//     }
//     else // If current vertex is not destination
//     {
//         // Recur for all the vertices graphacent to current vertex
//         vector<int>::iterator i;
//         for (i = graph[u].begin(); i != graph[u].end(); ++i)
//             if (!visited[*i])
//                 printAllPathsUtil(*i, d, visited, path, path_index,grp);
//     }
  
//     // Remove current vertex from path[] and mark it as unvisited
//     path_index--;
//     visited[u] = false;
    
// }

// void printAllPaths(int s, int d,vector<int>grp)
// {
//     // Mark all the vertices as not visited
//     bool* visited = new bool[V];
  
//     // Create an array to store paths
//     int* path = new int[V];
//     int path_index = 0; // Initialize path[] as empty
  
//     // Initialize all vertices as not visited
//     for (int i = 0; i < V; i++)
//         visited[i] = false;
  
//     // Call the recursive helper function to print all paths
//     return printAllPathsUtil(s, d, visited, path, path_index,grp);
// }


// void combinationUtil(int arr[], int data[],int start, int end,int index, int r);
 
// // The main function that prints
// // all combinations of size r
// // in arr[] of size n. This function
// // mainly uses combinationUtil()
// void printCombination(int arr[], int n, int r)
// {
//     // A temporary array to store
//     // all combination one by one
//     int data[r];
 
//     // Print all combination using
//     // temprary array 'data[]'
//     combinationUtil(arr, data, 0, n-1, 0, r);
// }
 
// /* arr[] ---> Input Array
// data[] ---> Temporary array to
// store current combination
// start & end ---> Staring and
// Ending indexes in arr[]
// index ---> Current index in data[]
// r ---> Size of a combination to be printed */
// void combinationUtil(int arr[], int data[],int start, int end,int index, int r)
// {
//     // Current combination is ready
//     // to be printed, print it
//     if (index == r)
//     {
//         vector<int>s;
//         for (int j = 0; j < r; j++)
//         {
//             cout << data[j] << " ";
//             s.push_back(data[j]);
//         }
//         cout<<endl;
//         for(int i = 0;i<s.size();i++)
//         {
//             for(int j = i+1;j<s.size();j++)
//             {
//                 value = false;
//                 printAllPaths(s[i],s[j],s);
//                 if(value)
//                 {
//                     validCount+=1;
//                     cout<<"inc\n";
//                     return;
//                 }
//             }
//         }
//         // cout << endl;
//         return;
//     }
 
//     // replace index with all possible
//     // elements. The condition "end-i+1 >= r-index"
//     // makes sure that including one element
//     // at index will make a combination with
//     // remaining elements at remaining positions
//     for (int i = start; i <= end &&end - i + 1 >= r - index; i++)
//     {
//         data[index] = arr[i];
//         combinationUtil(arr, data, i+1,end, index+1, r);
//     }
// }
 
// signed main()
// {
//     // fastio
//     testcase
//     {
//         int n;
//         cin>>n;
//         V = n;
//         graph.clear();
//         graph.resize(n+1);
//         validCount = 0;
//         int u,v;
//         ddd = 0;
//         rep(i,n-1)
//         {
//             cin>>u>>v;
//             graph[u].push_back(v);
//             graph[v].push_back(u);
//         }
//         int arr[n+10];
//         // cout<<"------\n";
//         rep(i,n)
//             arr[i] = i+1;
//         for(int i = 3;i<=n;i++)
//         {
//             printCombination(arr, n, i);
//         }
//         cout<<validCount+n+(n*(n-1)/2)<<endl;
//         // cout<<ddd<<endl;
        
        
        
//     }
// }
/* ----------------------------------------------------------------------------------------------------*/
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
        int k;
        cin>>k;
        // int dp[2*k+2];
        // for(int i = 1;i<=2*k+1;i++)
        //     dp[i] = k+i*i;
        
        // int sum = 0;
        // for(int i = 2;i<=2*k+1;i++)
        // {
        //     // cout<<dp[i-1]<<"  "<<dp[i]<<" = ";
        //     int gc = __gcd(dp[i-1],dp[i]);
        //     // int gc = __gcd(k+(i-1)*(i-1),(i*i)-(i-1)*(i-1));
        //     // cout<<gc<<endl;
        //     sum+=gc;
        // }
        for(int i = 2;i<=k;i++)
        {
            int x = i-1;
            cout<<x*x<<" "<<i*i<<" "<<__gcd(x*x,i*i)<<endl;
        }
        // cout<<sum<<endl;
        
    }
}