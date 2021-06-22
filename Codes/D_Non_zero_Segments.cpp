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
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define mpl map<ll,ll>
#define SIZE ll(100005)//00002)
#define FAIL -5677884
#define BIT_SIZE 35
int findSubArrays(int arr[], int n) 
{ 
    // create an empty map 
    unordered_map<int, vector<int> > map; 
   
    // create an empty vector of pairs to store 
    // subarray starting and ending index 
    //vector <pair<int, int>> out; 
   
    // Maintains sum of elements so far 
    int sum = 0; 
    int cnt = 0;
    for (int i = 0; i < n; i++) 
    { 
        // add current element to sum 
        sum += arr[i]; 
   
        // if sum is 0, we found a subarray starting 
        // from index 0 and ending at index i 
        if (sum == 0) 
        {
            cnt++;
            map.clear();
            sum =arr[i];
        }
        else if (map.find(sum) != map.end()) 
        { 
            // map[sum] stores starting index of all subarrays 
            vector<int> vc = map[sum]; 
            for (auto it = vc.begin(); it != vc.end(); it++) 
                cnt++;
            map.clear();
            sum =arr[i];
        } 
        //else 
            map[sum].push_back(i); 
    } 
   
    // return output vector 
    return cnt; 
} 
signed main()
{
    fastio
    {
        int n;
        cin>>n;
        int arr[n+10];
        rep(i,n)
        {
            cin>>arr[i];
        }
        // ll prefix[n+10];
        // prefix[0] =arr[0];
        // int last = 0;
        // repA(i,1,n)
        // {
        //     prefix[i]=prefix[i-1]+arr[i];
            
        // }
        cout<<findSubArrays(arr,n)<<"\n";


    }
}