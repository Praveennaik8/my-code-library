// Minimum addition
// Max. score: 100
// You are given an array  of  positive numbers. You are also given  queries. Each query contains two integers . For each query, determine the sum of all values that must be added to each number in range  to  such that bitwise AND of all numbers in the range is greater than 0.

// You are required to minimize the total value that must be added. The value you must add to numbers is not necessarily equal for all numbers.

// Note: Each query is independent of each other, that is, for each query, you must treat the range over the initial input array.

// Input format

// The first line contains an integer  denoting the number of array elements.
// The next line denotes  array elements.
// The next line contains a number  denoting the number of queries.
// Next  lines contain two integers  and .
// Output format

// For each query, print the minimum sum of values to be added in a new line.

// Constraints





 

// SAMPLE INPUT 
// 5
// 4 3 2 4 1
// 4
// 1 4
// 2 3
// 4 4
// 4 5
// SAMPLE OUTPUT 
// 3
// 0
// 0
// 1
// Explanation
// For the first query we can add 1 to the 1st, 3rd and, 4th numbers.
// For the second and third query, we don't need to add as the Bitwise AND is already > 0.
// For the last query, we can add 1 to 4th number.
 

#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
#define int long long
#define vi vector<int>
#define vll vector<long long>
#define testcase int t; cin>>t ;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
#define all(x) x.begin(), x.end()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define repi_1n for(int i = 1;i<=n;i++)
#define repi_0n for(int i = 0;i<n;i++)
#define repj_1n for(int j = 1;j<=n;j++)
#define repj_0n for(int j = 0;j<n;j++)
#define mpl map<ll,ll>
#define SIZE ll(100005)//00002)
#define FAIL -5677884
#define BIT_SIZE 35


void test(ll x)
{
   cout<<"\nvisited "<<x<<"\n";
}

bool isKthBitSet(int n, int k) 
{ 
    if (n & (1 << (k - 1))) 
        return true; 
    return false;
} 
signed main()
{
    fastio
    
    int arr_size;
    cin>>arr_size;
    //test(arr_size);
    int arr[arr_size+10];
    for(int i = 1;i<=arr_size;i++)
        cin>>arr[i];
        //test(arr_size);
    int dp[arr_size+10][BIT_SIZE],costdp[arr_size+10][BIT_SIZE];
    int powof2[BIT_SIZE];
    powof2[0] = 1;
   //test(arr_size);
    int n = arr_size;
    for(int i = 0;i<BIT_SIZE;i++)
    {
        dp[0][i] = 0;
        powof2[i+1] = powof2[i]*2;
        costdp[0][i] = 0;
    }
   //test(arr_size);
   //test(1); 
    arr_size = n;    
    
    for(int i = 1;i<=arr_size;i++)
    {
        int tempsum = 0;
        for(int j = 1;j<BIT_SIZE;j++)
        {
            ////test(j);
            // cout<<"i == "<<i<<"\n";
            if(isKthBitSet(arr[i],j))
            {
                dp[i][j] = dp[i-1][j]+1;
                tempsum+=powof2[j-1];
                costdp[i][j] = costdp[i-1][j];
            }     
            else
            {
                dp[i][j] = dp[i-1][j];
                costdp[i][j] = costdp[i-1][j]+(powof2[j-1]-tempsum);
            }
                
        }
    }
   //test(2);
    int q;
    cin>>q;
    while(q--)
    {
       //test(q);
        int l,r;
        cin>>l>>r;
        int ans = INT_MAX;
        int x = r-l+1;
        for(int i = 1;i<BIT_SIZE;i++)
        {
            //int y = x - (( dp[r][i] - dp[l][i])+(dp[l][i]-dp[l-1][i]));
            //cout<<i<<" "<<y<<" * "<<powof2[i-1]<<endl;
            //ans = min(ans,y*powof2[i-1]);
            int y = costdp[r][i] - costdp[l-1][i];//+(costdp[l][i]-costdp[l-1][i]);
            ans = min(ans,y);
        }
        cout<<ans<<"\n";
    }
}
